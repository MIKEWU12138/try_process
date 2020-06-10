/*
 * File: LCWS_subsystem_integrated.c
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

#include "LCWS_subsystem_integrated.h"
#include "LCWS_subsystem_integrated_private.h"
#include "mul_s32_loSR.h"
#include "norm_TbqwX7rn.h"
#include "obt_3pO7kBnK.h"
#include "repos_fcn_xpArvFer.h"
#include "rt_roundf.h"

/* Named constants for Chart: '<S2>/DtmnWarningChart' */
#define LCWS_subs_IN_Warning_left1level ((uint8_T)1U)
#define LCWS_subs_IN_Warning_left2level ((uint8_T)2U)
#define LCWS_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define LCWS_subsystem_integr_IN_UnSafe ((uint8_T)2U)
#define LCWS_subsystem_integrat_IN_Safe ((uint8_T)1U)

/* Named constants for Chart: '<S3>/DtmnWarningChart' */
#define LCWS_subsystem_IN_Warning1level ((uint8_T)1U)
#define LCWS_subsystem_IN_Warning2level ((uint8_T)2U)

/* Named constants for Chart: '<S4>/DtmnChart' */
#define LCWS_subsystem_inte_IN_Inactive ((uint8_T)2U)
#define LCWS_subsystem_inte_IN_Positive ((uint8_T)2U)
#define LCWS_subsystem_integ_IN_Passive ((uint8_T)1U)
#define LCWS_subsystem_integr_IN_Active ((uint8_T)1U)
#define LCWS_subsystem_integrate_IN_Off ((uint8_T)1U)
#define LCWS_subsystem_integrated_IN_On ((uint8_T)2U)

const LCWS_DataBus LCWS_subsystem_integrated_rtZLCWS_DataBus =
{
  0,                                   /* bswL_ID */
  0,                                   /* cvwL_ID */
  0,                                   /* bswR_ID */
  0,                                   /* cvwR_ID */
  false,                               /* warning_left_low */
  false,                               /* warning_left_high */
  false,                               /* warning_right_low */
  false,                               /* warning_right_high */
  LCWS_OFF,                            /* active_status */
  LCWS_NO_WARNING,                     /* left_warning_status */
  LCWS_NO_WARNING                      /* right_warning_status */
} ;                                    /* LCWS_DataBus ground */

/* Exported block signals */
LCWS_DataBus VsLCWS_DataBus;           /* '<S6>/Bus_Creator' */
real32_T VfLCWS_curvature;             /* '<S21>/Gain2' */
real32_T VfLCWS_speed_in;              /* '<S21>/Gain1' */
real32_T VaLCWS_Obt[33];               /* '<S22>/ObserveObtVecFunction2' */
real32_T VaLCWS_x_in[10];              /* '<S22>/ObserveObtVecFunction1' */
real32_T VaLCWS_y_in[10];              /* '<S22>/ObserveObtVecFunction1' */
real32_T VaLCWS_heading_in[10];        /* '<S22>/ObserveObtVecFunction1' */
real32_T VaLCWS_Vx_in[10];             /* '<S22>/ObserveObtVecFunction1' */
real32_T VaLCWS_Vy_in[10];             /* '<S22>/ObserveObtVecFunction1' */
real32_T VaLCWS_obt_lenth_in[10];      /* '<S22>/ObserveObtVecFunction1' */
real32_T VaLCWS_obt_width_in[10];      /* '<S22>/ObserveObtVecFunction1' */
real32_T VaLCWS_nearest_point_rel_x_in[10];/* '<S22>/ObserveObtVecFunction1' */
real32_T VaLCWS_nearest_point_rel_y_in[10];/* '<S22>/ObserveObtVecFunction1' */
int32_T VaLCWS_id_in[10];              /* '<S22>/ObserveObtVecFunction1' */
int32_T ViLCWS_bswR_ID;                /* '<S3>/Gain2' */
int32_T ViLCWS_cvwR_ID;                /* '<S3>/Gain1' */
int32_T ViLCWS_bswL_ID;                /* '<S2>/Gain' */
int32_T ViLCWS_cvwL_ID;                /* '<S2>/Gain1' */
uint16_T VnLCWS_num_L;                 /* '<S22>/Gain2' */
uint16_T VnLCWS_num_R;                 /* '<S22>/Gain1' */
uint16_T VnLCWS_num_in;                /* '<S22>/Gain3' */
int8_T VaLCWS_position_zone_in[10];    /* '<S22>/ObserveObtVecFunction1' */
int8_T VaLCWS_orientation_in[10];      /* '<S22>/ObserveObtVecFunction1' */
int8_T VaLCWS_motion_status_in[10];    /* '<S22>/ObserveObtVecFunction1' */
uint8_T VfLCWS_gear_in;                /* '<S21>/Gain3' */
uint8_T VaLCWS_type[10];               /* '<S22>/ObserveObtVecFunction1' */
uint8_T ViLCWS_bswR;                   /* '<S3>/Gain3' */
uint8_T ViLCWS_cvwR;                   /* '<S3>/Gain4' */
uint8_T ViLCWS_bswL;                   /* '<S2>/Gain2' */
uint8_T ViLCWS_cvwL;                   /* '<S2>/Gain3' */
EnumLCWS_Active_Status VeLCWS_active_status;/* '<S4>/Rate Transition' */
EnumLCWS_Warning_Status VeLCWS_right_warning_status_out;/* '<S6>/Rate Transition1' */
EnumLCWS_Warning_Status VeLCWS_left_warning_status_out;/* '<S6>/Rate Transition' */
EnumLCWS_Warning_Status VeLCWS_right_warning_status;/* '<S3>/Rate Transition' */
EnumLCWS_Warning_Status VeLCWS_left_warning_status;/* '<S2>/Rate Transition' */
EnumLCWS_warningArea ViLCWS_bswLL;     /* '<S2>/Rate Transition1' */
 #pragma section ".cal" 
/* Exported block parameters */
real32_T KfLCWS_c_DisbleCurveThrshMax = 0.0125F;/* Variable: KfLCWS_c_DisbleCurveThrshMax
                                                 * Referenced by: '<S20>/Constant20'
                                                 */
real32_T KfLCWS_c_EnbleCurveThrshMax = 0.0111111114F;/* Variable: KfLCWS_c_EnbleCurveThrshMax
                                                      * Referenced by: '<S20>/Constant19'
                                                      */
real32_T KfLCWS_d_BSDLargerZone_BackDis = 6.0F;/* Variable: KfLCWS_d_BSDLargerZone_BackDis
                                                * Referenced by: '<S20>/Constant9'
                                                */
real32_T KfLCWS_d_BSDLargerZone_FrontDis = 0.0F;/* Variable: KfLCWS_d_BSDLargerZone_FrontDis
                                                 * Referenced by: '<S20>/Constant7'
                                                 */
real32_T KfLCWS_d_BSDLargerZone_NearDis = 0.0F;/* Variable: KfLCWS_d_BSDLargerZone_NearDis
                                                * Referenced by: '<S20>/Constant3'
                                                */
real32_T KfLCWS_d_BSDZone_BackDis = 5.0F;/* Variable: KfLCWS_d_BSDZone_BackDis
                                          * Referenced by: '<S20>/Constant8'
                                          */
real32_T KfLCWS_d_BSDZone_Eye95Dis = 0.7F;/* Variable: KfLCWS_d_BSDZone_Eye95Dis
                                           * Referenced by: '<S20>/Constant10'
                                           */
real32_T KfLCWS_d_BSDZone_FarDis = 4.0F;/* Variable: KfLCWS_d_BSDZone_FarDis
                                         * Referenced by: '<S20>/Constant4'
                                         */
real32_T KfLCWS_d_BSDZone_FrontDis = 0.7F;/* Variable: KfLCWS_d_BSDZone_FrontDis
                                           * Referenced by: '<S20>/Constant6'
                                           */
real32_T KfLCWS_d_BSDZone_NearDis = 0.3F;/* Variable: KfLCWS_d_BSDZone_NearDis
                                          * Referenced by: '<S20>/Constant2'
                                          */
real32_T KfLCWS_d_CVLargerZone_FrontDis = 1.0F;/* Variable: KfLCWS_d_CVLargerZone_FrontDis
                                                * Referenced by: '<S20>/Constant12'
                                                */
real32_T KfLCWS_d_CVZone_FrontDis = 2.0F;/* Variable: KfLCWS_d_CVZone_FrontDis
                                          * Referenced by: '<S20>/Constant11'
                                          */
real32_T KfLCWS_d_NearDisHiLevel = 0.5F;/* Variable: KfLCWS_d_NearDisHiLevel
                                         * Referenced by: '<S20>/Constant16'
                                         */
real32_T KfLCWS_d_VehLenth = 4.0F;     /* Variable: KfLCWS_d_VehLenth
                                        * Referenced by: '<S20>/Constant'
                                        */
real32_T KfLCWS_d_VehWidth = 2.5F;     /* Variable: KfLCWS_d_VehWidth
                                        * Referenced by: '<S20>/Constant1'
                                        */
real32_T KfLCWS_r_ObtWidthProportion = 0.0F;/* Variable: KfLCWS_r_ObtWidthProportion
                                             * Referenced by: '<S20>/Constant25'
                                             */
real32_T KfLCWS_t_TTCLargerThrsh_LowLevel = 4.0F;/* Variable: KfLCWS_t_TTCLargerThrsh_LowLevel
                                                  * Referenced by: '<S20>/Constant14'
                                                  */
real32_T KfLCWS_t_TTCThrshHiLevel = 1.0F;/* Variable: KfLCWS_t_TTCThrshHiLevel
                                          * Referenced by: '<S20>/Constant15'
                                          */
real32_T KfLCWS_t_TTCThrshLowLevel = 3.5F;/* Variable: KfLCWS_t_TTCThrshLowLevel
                                           * Referenced by: '<S20>/Constant13'
                                           */
real32_T KfLCWS_v_DisbleVehSpdThrshHi = 53.0F;/* Variable: KfLCWS_v_DisbleVehSpdThrshHi
                                               * Referenced by: '<S20>/Constant27'
                                               */
real32_T KfLCWS_v_DisbleVehSpdThrshLo = -2.0F;/* Variable: KfLCWS_v_DisbleVehSpdThrshLo
                                               * Referenced by: '<S20>/Constant18'
                                               */
real32_T KfLCWS_v_EnbleVehSpdThrshHi = 50.0F;/* Variable: KfLCWS_v_EnbleVehSpdThrshHi
                                              * Referenced by: '<S20>/Constant26'
                                              */
real32_T KfLCWS_v_EnbleVehSpdThrshLo = -1.0F;/* Variable: KfLCWS_v_EnbleVehSpdThrshLo
                                              * Referenced by: '<S20>/Constant17'
                                              */
real32_T KfLCWS_v_LatSpdThr = 20.0F;   /* Variable: KfLCWS_v_LatSpdThr
                                        * Referenced by: '<S20>/Constant24'
                                        */
real32_T KfLCWS_v_OncomRelSpdThrshHi_in = 4.0F;/* Variable: KfLCWS_v_OncomRelSpdThrshHi_in
                                                * Referenced by: '<S20>/Constant22'
                                                */
real32_T KfLCWS_v_OncomRelSpdThrshHi_out = 5.0F;/* Variable: KfLCWS_v_OncomRelSpdThrshHi_out
                                                 * Referenced by: '<S20>/Constant23'
                                                 */
int8_T KfLCWS_d_BSDLargerZone_FarDis = 5;/* Variable: KfLCWS_d_BSDLargerZone_FarDis
                                          * Referenced by: '<S20>/Constant5'
                                          */
boolean_T KbLCWS_ObtFilter = 0;        /* Variable: KbLCWS_ObtFilter
                                        * Referenced by: '<S22>/Constant21'
                                        */
boolean_T KbLCWS_ObtStaticIn = 0;      /* Variable: KbLCWS_ObtStaticIn
                                        * Referenced by: '<S22>/Constant28'
                                        */
boolean_T KbLCWS_Switch = 0;           /* Variable: KbLCWS_Switch
                                        * Referenced by: '<S20>/Constant21'
                                        */
boolean_T KbLCWS_curve = 0;            /* Variable: KbLCWS_curve
                                        * Referenced by: '<S21>/Constant28'
                                        */
 #pragma section 
/* Block signals (auto storage) */
B_LCWS_subsystem_integrated_T LCWS_subsystem_integrated_B;

/* Block states (auto storage) */
DW_LCWS_subsystem_integrated_T LCWS_subsystem_integrated_DW;

/* Model step function */
void LCWS_subsystem_integrated_step(void)
{
  uint8_T BSW;
  real32_T BSD_near1;
  real32_T BSD_near2;
  real32_T BSD_far1;
  real32_T BSD_back2;
  real32_T A[2];
  real32_T B[2];
  real32_T C[2];
  real32_T unusedU1[2];
  boolean_T b;
  real32_T y;
  uint16_T num_L;
  uint16_T num_R;
  real32_T vec_L[220];
  real32_T vec_R[220];
  real32_T vec_L_out_data[220];
  real32_T vec_R_out_data[220];
  uint16_T b_0;
  uint16_T i;
  uint16_T num_L_0;
  uint16_T num_R_0;
  real32_T rtb_curvature;
  boolean_T rtb_LogicalOperator1;
  real32_T rtb_KfLCWS_d_BSDLargerZone_FarD;
  real32_T rtb_vec_L_out_kyjy[220];
  real32_T rtb_vec_R_out_dv4e[220];
  EnumLCWS_Warning_Status rtb_left_warning_status;
  EnumLCWS_Warning_Status rtb_right_warning_status;
  boolean_T enable;
  boolean_T rtb_Compare_dy3b;
  boolean_T rtb_Compare_iafx;
  EnumLCWS_Active_Status active_status;
  EnumLCWS_warningArea BSW_nwgt;
  int32_T i_0;
  real32_T B_0[2];
  real32_T tmp_data[11];
  int32_T i_1;
  int32_T vec_L_out_size[2];
  int32_T vec_R_out_size[2];
  int8_T tmp;
  real32_T tmp_0;
  boolean_T exitg1;

  /* Outputs for Atomic SubSystem: '<Root>/LCWS_Subsystem' */
  /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
  /* Switch: '<S21>/Switch' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   *  Inport: '<Root>/VsMPFU_DataBus'
   */
  if (VsMPFU_DataBus.curvature.is_valid)
  {
    rtb_KfLCWS_d_BSDLargerZone_FarD = VsMPFU_DataBus.curvature.value;
  }
  else
  {
    rtb_KfLCWS_d_BSDLargerZone_FarD = VsEGMO_DataBus.motion.curvature;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Switch: '<S21>/Switch1' incorporates:
   *  Constant: '<S21>/Constant28'
   *  Constant: '<S21>/Constant4'
   */
  if (KbLCWS_curve)
  {
    rtb_curvature = rtb_KfLCWS_d_BSDLargerZone_FarD;
  }
  else
  {
    rtb_curvature = 0.0F;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S5>/CvrtObtVecFunctionEnabled' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  /* Logic: '<S21>/Logical Operator1' incorporates:
   *  Constant: '<S21>/Constant'
   *  DataTypeConversion: '<S22>/Data Type Conversion'
   *  DataTypeConversion: '<S22>/Data Type Conversion1'
   *  Inport: '<Root>/VsDCSN_DataBus'
   *  Logic: '<S21>/Logical Operator'
   *  MATLAB Function: '<S22>/CvrtObtVecFunction'
   *  MATLAB Function: '<S22>/CvrtObtVecFunction1'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtBus Selector4Outport1'
   */
  if ((VsDCSN_DataBus.EnablingFlags_Group.lcw_feature_enable) && (!false))
  {
    if (!LCWS_subsystem_integrated_DW.CvrtObtVecFunctionEnabled_MODE)
    {
      LCWS_subsystem_integrated_DW.CvrtObtVecFunctionEnabled_MODE = true;
    }

    /* MATLAB Function: '<S22>/CvrtObtVecFunction' incorporates:
     *  Constant: '<S21>/Constant1'
     *  Constant: '<S22>/Constant28'
     *  Inport: '<Root>/VsOBFU_DataBus'
     */
    num_L = 0U;
    num_R = 0U;
    memset(&vec_L[0], 0, 220U * (sizeof(real32_T)));
    memset(&vec_R[0], 0, 220U * (sizeof(real32_T)));
    if (((int32_T)VsOBFU_DataBus.num_obstacles) < 128)
    {
      b_0 = VsOBFU_DataBus.num_obstacles;
    }
    else
    {
      b_0 = 128U;
    }

    for (i = 1U; i <= b_0; i = (uint16_T)(((uint32_T)i) + 1U))
    {
      if (((((((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].position_zone == 4) ||
               (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].position_zone == 6)) ||
              (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].position_zone == 7)) &&
             (((real_T)VsOBFU_DataBus.obstacles[((int32_T)i) - 1].heading_rel) <
              1.57)) && (((real_T)VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                          heading_rel) > -1.57)) && (((int32_T)num_L) < 20)) &&
          (KbLCWS_ObtStaticIn || (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
            motion_status != 2)))
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
        vec_L[((int32_T)num_L) + 19] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .center_point_rel.x;
        vec_L[((int32_T)num_L) + 39] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .center_point_rel.y;
        vec_L[((int32_T)num_L) + 59] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .heading_rel;
        vec_L[((int32_T)num_L) + 79] = (real32_T)sqrt((real_T)((real32_T)
          ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x *
            VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x) +
           (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y *
            VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y))));
        vec_L[((int32_T)num_L) + 99] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .length;
        vec_L[((int32_T)num_L) + 119] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].width;
        vec_L[((int32_T)num_L) + 139] = (real32_T)VsOBFU_DataBus.obstacles
          [((int32_T)i) - 1].motion_orientation;
        vec_L[((int32_T)num_L) + 159] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].nearest_point_rel.x;
        vec_L[((int32_T)num_L) + 179] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].nearest_point_rel.y;
        vec_L[((int32_T)num_L) + 199] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].velocity_rel.y;
      }

      if (((((((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].position_zone == 5) ||
               (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].position_zone == 7)) ||
              (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].position_zone == 8)) &&
             (((real_T)VsOBFU_DataBus.obstacles[((int32_T)i) - 1].heading_rel) <
              1.57)) && (((real_T)VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                          heading_rel) > -1.57)) && (((int32_T)num_R) < 20)) &&
          (KbLCWS_ObtStaticIn || (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
            motion_status != 2)))
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
        vec_R[((int32_T)num_R) + 19] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .center_point_rel.x;
        vec_R[((int32_T)num_R) + 39] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .center_point_rel.y;
        vec_R[((int32_T)num_R) + 59] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .heading_rel;
        vec_R[((int32_T)num_R) + 79] = (real32_T)sqrt((real_T)((real32_T)
          ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x *
            VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x) +
           (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y *
            VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y))));
        vec_R[((int32_T)num_R) + 99] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .length;
        vec_R[((int32_T)num_R) + 119] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].width;
        vec_R[((int32_T)num_R) + 139] = (real32_T)VsOBFU_DataBus.obstacles
          [((int32_T)i) - 1].motion_orientation;
        vec_R[((int32_T)num_R) + 159] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].nearest_point_rel.x;
        vec_R[((int32_T)num_R) + 179] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].nearest_point_rel.y;
        vec_R[((int32_T)num_R) + 199] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].velocity_rel.y;
      }
    }

    if (!false)
    {
      memset(&vec_L[140], 0, 20U * (sizeof(real32_T)));
      memset(&vec_R[140], 0, 20U * (sizeof(real32_T)));
    }

    repos_fcn_xpArvFer(num_L, num_R, rtb_curvature, vec_L, vec_R, vec_L_out_data,
                       vec_L_out_size, vec_R_out_data, vec_R_out_size);

    /* MATLAB Function: '<S22>/CvrtObtVecFunction' */
    LCWS_subsystem_integrated_DW.SFunction_DIMS2_iirt[0] = vec_L_out_size[0];
    LCWS_subsystem_integrated_DW.SFunction_DIMS2_iirt[1] = vec_L_out_size[1];
    i_0 = vec_L_out_size[0] * vec_L_out_size[1];
    if (0 <= (i_0 - 1))
    {
      memcpy(&rtb_vec_L_out_kyjy[0], &vec_L_out_data[0], ((uint32_T)i_0) *
             (sizeof(real32_T)));
    }

    /* MATLAB Function: '<S22>/CvrtObtVecFunction' */
    LCWS_subsystem_integrated_DW.SFunction_DIMS3_domv[0] = vec_R_out_size[0];
    LCWS_subsystem_integrated_DW.SFunction_DIMS3_domv[1] = vec_R_out_size[1];
    i_0 = vec_R_out_size[0] * vec_R_out_size[1];
    if (0 <= (i_0 - 1))
    {
      memcpy(&rtb_vec_R_out_dv4e[0], &vec_R_out_data[0], ((uint32_T)i_0) *
             (sizeof(real32_T)));
    }

    /* MATLAB Function: '<S22>/CvrtObtVecFunction1' incorporates:
     *  Constant: '<S21>/Constant1'
     *  Constant: '<S22>/Constant28'
     *  Inport: '<Root>/VsOBFU_DataBus'
     *  MATLAB Function: '<S22>/CvrtObtVecFunction'
     */
    num_L_0 = 0U;
    num_R_0 = 0U;
    memset(&vec_L[0], 0, 220U * (sizeof(real32_T)));
    memset(&vec_R[0], 0, 220U * (sizeof(real32_T)));
    if (((int32_T)VsOBFU_DataBus.num_obstacles) < 128)
    {
      b_0 = VsOBFU_DataBus.num_obstacles;
    }
    else
    {
      b_0 = 128U;
    }

    for (i = 1U; i <= b_0; i = (uint16_T)(((uint32_T)i) + 1U))
    {
      if ((((((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].center_point_rel.y >
               0.0F) && (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                         center_point_rel.x < 5.0F)) && (((real_T)
               VsOBFU_DataBus.obstacles[((int32_T)i) - 1].heading_rel) < 1.57)) &&
            (((real_T)VsOBFU_DataBus.obstacles[((int32_T)i) - 1].heading_rel) >
             -1.57)) && (((int32_T)num_L_0) < 20)) && (KbLCWS_ObtStaticIn ||
           (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].motion_status != 2)))
      {
        i_1 = ((int32_T)num_L_0) + 1;
        if (i_1 < 20)
        {
          num_L_0 = (uint16_T)i_1;
        }
        else
        {
          num_L_0 = 20U;
        }

        vec_L[((int32_T)num_L_0) - 1] = (real32_T)VsOBFU_DataBus.obstacles
          [((int32_T)i) - 1].id;
        vec_L[((int32_T)num_L_0) + 19] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].center_point_rel.x;
        vec_L[((int32_T)num_L_0) + 39] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].center_point_rel.y;
        vec_L[((int32_T)num_L_0) + 59] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].heading_rel;
        vec_L[((int32_T)num_L_0) + 79] = (real32_T)sqrt((real_T)((real32_T)
          ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x *
            VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x) +
           (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y *
            VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y))));
        vec_L[((int32_T)num_L_0) + 99] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].length;
        vec_L[((int32_T)num_L_0) + 119] = VsOBFU_DataBus.obstacles[((int32_T)i)
          - 1].width;
        vec_L[((int32_T)num_L_0) + 139] = (real32_T)VsOBFU_DataBus.obstacles
          [((int32_T)i) - 1].motion_orientation;
        vec_L[((int32_T)num_L_0) + 159] = VsOBFU_DataBus.obstacles[((int32_T)i)
          - 1].nearest_point_rel.x;
        vec_L[((int32_T)num_L_0) + 179] = VsOBFU_DataBus.obstacles[((int32_T)i)
          - 1].nearest_point_rel.y;
        vec_L[((int32_T)num_L_0) + 199] = VsOBFU_DataBus.obstacles[((int32_T)i)
          - 1].velocity_rel.y;
      }

      if ((((((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].center_point_rel.y <
               0.0F) && (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                         center_point_rel.x < 5.0F)) && (((real_T)
               VsOBFU_DataBus.obstacles[((int32_T)i) - 1].heading_rel) < 1.57)) &&
            (((real_T)VsOBFU_DataBus.obstacles[((int32_T)i) - 1].heading_rel) >
             -1.57)) && (((int32_T)num_R_0) < 20)) && (KbLCWS_ObtStaticIn ||
           (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].motion_status != 2)))
      {
        i_1 = ((int32_T)num_R_0) + 1;
        if (i_1 < 20)
        {
          num_R_0 = (uint16_T)i_1;
        }
        else
        {
          num_R_0 = 20U;
        }

        vec_R[((int32_T)num_R_0) - 1] = (real32_T)VsOBFU_DataBus.obstacles
          [((int32_T)i) - 1].id;
        vec_R[((int32_T)num_R_0) + 19] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].center_point_rel.x;
        vec_R[((int32_T)num_R_0) + 39] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].center_point_rel.y;
        vec_R[((int32_T)num_R_0) + 59] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].heading_rel;
        vec_R[((int32_T)num_R_0) + 79] = (real32_T)sqrt((real_T)((real32_T)
          ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x *
            VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x) +
           (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y *
            VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y))));
        vec_R[((int32_T)num_R_0) + 99] = VsOBFU_DataBus.obstacles[((int32_T)i) -
          1].length;
        vec_R[((int32_T)num_R_0) + 119] = VsOBFU_DataBus.obstacles[((int32_T)i)
          - 1].width;
        vec_R[((int32_T)num_R_0) + 139] = (real32_T)VsOBFU_DataBus.obstacles
          [((int32_T)i) - 1].motion_orientation;
        vec_R[((int32_T)num_R_0) + 159] = VsOBFU_DataBus.obstacles[((int32_T)i)
          - 1].nearest_point_rel.x;
        vec_R[((int32_T)num_R_0) + 179] = VsOBFU_DataBus.obstacles[((int32_T)i)
          - 1].nearest_point_rel.y;
        vec_R[((int32_T)num_R_0) + 199] = VsOBFU_DataBus.obstacles[((int32_T)i)
          - 1].velocity_rel.y;
      }
    }

    if (!false)
    {
      memset(&vec_L[140], 0, 20U * (sizeof(real32_T)));
      memset(&vec_R[140], 0, 20U * (sizeof(real32_T)));
    }

    repos_fcn_xpArvFer(num_L_0, num_R_0, rtb_curvature, vec_L, vec_R,
                       vec_L_out_data, vec_L_out_size, vec_R_out_data,
                       vec_R_out_size);

    /* MATLAB Function: '<S22>/CvrtObtVecFunction1' */
    LCWS_subsystem_integrated_DW.SFunction_DIMS2[0] = vec_L_out_size[0];
    LCWS_subsystem_integrated_DW.SFunction_DIMS2[1] = vec_L_out_size[1];
    i_0 = vec_L_out_size[0] * vec_L_out_size[1];
    if (0 <= (i_0 - 1))
    {
      memcpy(&vec_L[0], &vec_L_out_data[0], ((uint32_T)i_0) * (sizeof(real32_T)));
    }

    /* MATLAB Function: '<S22>/CvrtObtVecFunction1' */
    LCWS_subsystem_integrated_DW.SFunction_DIMS3[0] = vec_R_out_size[0];
    LCWS_subsystem_integrated_DW.SFunction_DIMS3[1] = vec_R_out_size[1];
    i_0 = vec_R_out_size[0] * vec_R_out_size[1];
    if (0 <= (i_0 - 1))
    {
      memcpy(&vec_R[0], &vec_R_out_data[0], ((uint32_T)i_0) * (sizeof(real32_T)));
    }

    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant21'
     *  MATLAB Function: '<S22>/CvrtObtVecFunction1'
     */
    if (KbLCWS_ObtFilter)
    {
      LCWS_subsystem_integrated_DW.Switch_DIMS1[0] =
        LCWS_subsystem_integrated_DW.SFunction_DIMS2_iirt[0];
      LCWS_subsystem_integrated_DW.Switch_DIMS1[1] =
        LCWS_subsystem_integrated_DW.SFunction_DIMS2_iirt[1];
      i_0 = LCWS_subsystem_integrated_DW.SFunction_DIMS2_iirt[0] *
        LCWS_subsystem_integrated_DW.SFunction_DIMS2_iirt[1];
      if (0 <= (i_0 - 1))
      {
        memcpy(&vec_L[0], &rtb_vec_L_out_kyjy[0], ((uint32_T)i_0) * (sizeof
                (real32_T)));
      }
    }
    else
    {
      LCWS_subsystem_integrated_DW.Switch_DIMS1[0] =
        LCWS_subsystem_integrated_DW.SFunction_DIMS2[0];
      LCWS_subsystem_integrated_DW.Switch_DIMS1[1] =
        LCWS_subsystem_integrated_DW.SFunction_DIMS2[1];
    }

    /* End of Switch: '<S22>/Switch' */

    /* DataTypeConversion: '<S22>/Data Type Conversion' */
    LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] =
      LCWS_subsystem_integrated_DW.Switch_DIMS1[0];
    LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1] =
      LCWS_subsystem_integrated_DW.Switch_DIMS1[1];
    i_0 = LCWS_subsystem_integrated_DW.Switch_DIMS1[0] *
      LCWS_subsystem_integrated_DW.Switch_DIMS1[1];
    if (0 <= (i_0 - 1))
    {
      memcpy(&LCWS_subsystem_integrated_B.vec_L[0], &vec_L[0], ((uint32_T)i_0) *
             (sizeof(real32_T)));
    }

    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/Constant21'
     *  DataTypeConversion: '<S22>/Data Type Conversion'
     */
    if (KbLCWS_ObtFilter)
    {
      LCWS_subsystem_integrated_DW.Switch1_DIMS1[0] =
        LCWS_subsystem_integrated_DW.SFunction_DIMS3_domv[0];
      LCWS_subsystem_integrated_DW.Switch1_DIMS1[1] =
        LCWS_subsystem_integrated_DW.SFunction_DIMS3_domv[1];
      i_0 = LCWS_subsystem_integrated_DW.SFunction_DIMS3_domv[0] *
        LCWS_subsystem_integrated_DW.SFunction_DIMS3_domv[1];
      if (0 <= (i_0 - 1))
      {
        memcpy(&vec_L[0], &rtb_vec_R_out_dv4e[0], ((uint32_T)i_0) * (sizeof
                (real32_T)));
      }
    }
    else
    {
      LCWS_subsystem_integrated_DW.Switch1_DIMS1[0] =
        LCWS_subsystem_integrated_DW.SFunction_DIMS3[0];
      LCWS_subsystem_integrated_DW.Switch1_DIMS1[1] =
        LCWS_subsystem_integrated_DW.SFunction_DIMS3[1];
      i_0 = LCWS_subsystem_integrated_DW.SFunction_DIMS3[0] *
        LCWS_subsystem_integrated_DW.SFunction_DIMS3[1];
      if (0 <= (i_0 - 1))
      {
        memcpy(&vec_L[0], &vec_R[0], ((uint32_T)i_0) * (sizeof(real32_T)));
      }
    }

    /* End of Switch: '<S22>/Switch1' */

    /* DataTypeConversion: '<S22>/Data Type Conversion1' */
    LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] =
      LCWS_subsystem_integrated_DW.Switch1_DIMS1[0];
    LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[1] =
      LCWS_subsystem_integrated_DW.Switch1_DIMS1[1];
    i_0 = LCWS_subsystem_integrated_DW.Switch1_DIMS1[0] *
      LCWS_subsystem_integrated_DW.Switch1_DIMS1[1];
    if (0 <= (i_0 - 1))
    {
      memcpy(&LCWS_subsystem_integrated_B.vec_R[0], &vec_L[0], ((uint32_T)i_0) *
             (sizeof(real32_T)));
    }

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Constant21'
     *  DataTypeConversion: '<S22>/Data Type Conversion1'
     *  MATLAB Function: '<S22>/CvrtObtVecFunction'
     *  MATLAB Function: '<S22>/CvrtObtVecFunction1'
     */
    if (KbLCWS_ObtFilter)
    {
      LCWS_subsystem_integrated_B.num_L = num_L;
    }
    else
    {
      LCWS_subsystem_integrated_B.num_L = num_L_0;
    }

    /* End of Switch: '<S22>/Switch2' */

    /* MATLAB Function: '<S22>/ObserveObtVecFunction2' */
    memset(&VaLCWS_Obt[0], 0, 33U * (sizeof(real32_T)));
    if (((int32_T)LCWS_subsystem_integrated_B.num_L) >= 1)
    {
      if (3 < ((int32_T)LCWS_subsystem_integrated_B.num_L))
      {
        b_0 = 3U;
      }
      else
      {
        b_0 = LCWS_subsystem_integrated_B.num_L;
      }

      for (i = 1U; i <= b_0; i = (uint16_T)(((uint32_T)i) + 1U))
      {
        i_0 = LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1];
        for (i_1 = 0; i_1 < i_0; i_1++)
        {
          tmp_data[i_1] = LCWS_subsystem_integrated_B.vec_L[(((int32_T)i) +
            (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * i_1)) -
            1];
        }

        for (i_1 = 0; i_1 < 11; i_1++)
        {
          VaLCWS_Obt[(((int32_T)i) + (3 * i_1)) - 1] = tmp_data[i_1];
        }
      }
    }

    /* End of MATLAB Function: '<S22>/ObserveObtVecFunction2' */

    /* Gain: '<S22>/Gain2' */
    VnLCWS_num_L = (uint16_T)((((uint32_T)((uint16_T)32768U)) * ((uint32_T)
      LCWS_subsystem_integrated_B.num_L)) >> 15);

    /* Switch: '<S22>/Switch3' incorporates:
     *  Constant: '<S22>/Constant21'
     *  MATLAB Function: '<S22>/CvrtObtVecFunction'
     *  MATLAB Function: '<S22>/CvrtObtVecFunction1'
     */
    if (KbLCWS_ObtFilter)
    {
      LCWS_subsystem_integrated_B.num_R = num_R;
    }
    else
    {
      LCWS_subsystem_integrated_B.num_R = num_R_0;
    }

    /* End of Switch: '<S22>/Switch3' */

    /* Gain: '<S22>/Gain1' */
    VnLCWS_num_R = (uint16_T)((((uint32_T)((uint16_T)32768U)) * ((uint32_T)
      LCWS_subsystem_integrated_B.num_R)) >> 15);

    /* MATLAB Function: '<S22>/ObserveObtVecFunction1' incorporates:
     *  Inport: '<Root>/VsOBFU_DataBus'
     */
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
      VaLCWS_type[i_0] = 0U;
    }

    if (((int32_T)VsOBFU_DataBus.num_obstacles) >= 1)
    {
      if (((int32_T)VsOBFU_DataBus.num_obstacles) < 10)
      {
        b_0 = VsOBFU_DataBus.num_obstacles;
      }
      else
      {
        b_0 = 10U;
      }

      for (i = 1U; i <= b_0; i = (uint16_T)(((uint32_T)i) + 1U))
      {
        i_0 = ((int32_T)i) - 1;
        VaLCWS_position_zone_in[i_0] = VsOBFU_DataBus.obstacles[i_0].
          position_zone;
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
        VaLCWS_motion_status_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1]
          .motion_status;
        VaLCWS_nearest_point_rel_x_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)
          i) - 1].nearest_point_rel.x;
        VaLCWS_nearest_point_rel_y_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)
          i) - 1].nearest_point_rel.y;
        tmp = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].type;
        if (tmp < 0)
        {
          tmp = 0;
        }

        VaLCWS_type[i_0] = (uint8_T)tmp;
      }
    }

    /* End of MATLAB Function: '<S22>/ObserveObtVecFunction1' */

    /* Gain: '<S22>/Gain3' incorporates:
     *  Inport: '<Root>/VsOBFU_DataBus'
     */
    VnLCWS_num_in = (uint16_T)((((uint32_T)((uint16_T)32768U)) * ((uint32_T)
      VsOBFU_DataBus.num_obstacles)) >> 15);
  }
  else
  {
    if (LCWS_subsystem_integrated_DW.CvrtObtVecFunctionEnabled_MODE)
    {
      LCWS_subsystem_integrated_DW.CvrtObtVecFunctionEnabled_MODE = false;
    }
  }

  /* End of Logic: '<S21>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S5>/CvrtObtVecFunctionEnabled' */

  /* Gain: '<S21>/Gain2' */
  VfLCWS_curvature = 1.0F * rtb_KfLCWS_d_BSDLargerZone_FarD;

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/VsCOMM_JAC_Bus_FedBck_Data'
   */
  rtb_Compare_dy3b =
    (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Light.VCU1_ICPV_DirIndicationLH ==
     ((uint8_T)1U));

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/VsCOMM_JAC_Bus_FedBck_Data'
   */
  rtb_Compare_iafx =
    (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Light.VCU1_ICPV_DirIndicationRH ==
     ((uint8_T)1U));

  /* Gain: '<S21>/Gain1' incorporates:
   *  Inport: '<Root>/VsCOMM_JAC_Bus_FedBck_Data'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtBus Selector2Outport4'
   */
  VfLCWS_speed_in = 1.0F *
    VsCOMM_JAC_Bus_FedBck_Data.FedBck_VehDynmc.VCU1_ICPV_VehSpd;

  /* Gain: '<S21>/Gain3' incorporates:
   *  Inport: '<Root>/VsCOMM_JAC_Bus_FedBck_Data'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtBus Selector2Outport5'
   */
  VfLCWS_gear_in = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)
    VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos)) >> 7);

  /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */

  /* Chart: '<S4>/DtmnChart' incorporates:
   *  BusCreator: '<S20>/Bus Creator1'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S20>/Constant17'
   *  Constant: '<S20>/Constant18'
   *  Constant: '<S20>/Constant19'
   *  Constant: '<S20>/Constant20'
   *  Constant: '<S20>/Constant21'
   *  Constant: '<S20>/Constant26'
   *  Constant: '<S20>/Constant27'
   *  Inport: '<Root>/VsCOMM_JAC_Bus_FedBck_Data'
   *  Inport: '<Root>/VsDCSN_DataBus'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  Logic: '<S4>/Logical Operator2'
   *  Logic: '<S4>/Logical Operator3'
   *  Logic: '<S4>/Logical Operator4'
   *  Logic: '<S4>/Logical Operator6'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  RelationalOperator: '<S4>/Relational Operator2'
   *  RelationalOperator: '<S4>/Relational Operator3'
   *  RelationalOperator: '<S4>/Relational Operator4'
   *  RelationalOperator: '<S4>/Relational Operator5'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtBus Selector2Outport4'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtBus Selector2Outport5'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtBus Selector4Outport1'
   */
  if (((uint32_T)LCWS_subsystem_integrated_DW.is_c3_LCWS_subsystem_integrated) ==
      LCWS_subsystem_integrate_IN_Off)
  {
    enable = false;
    active_status = LCWS_OFF;
  }
  else if (((uint32_T)LCWS_subsystem_integrated_DW.is_On) ==
           LCWS_subsystem_integ_IN_Passive)
  {
    enable = false;
    active_status = LCWS_PASSIVE;
  }
  else if (((uint32_T)LCWS_subsystem_integrated_DW.is_Positive) ==
           LCWS_subsystem_integr_IN_Active)
  {
    enable = true;
    active_status = LCWS_ACTIVE;
  }
  else
  {
    enable = false;
    active_status = LCWS_INACTIVE;
  }

  if (((uint32_T)LCWS_subsystem_integrated_DW.is_c3_LCWS_subsystem_integrated) ==
      LCWS_subsystem_integrate_IN_Off)
  {
    /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
    if ((VsDCSN_DataBus.EnablingFlags_Group.lcw_feature_enable) && KbLCWS_Switch)
    {
      LCWS_subsystem_integrated_DW.is_c3_LCWS_subsystem_integrated =
        LCWS_subsystem_integrated_IN_On;
      LCWS_subsystem_integrated_DW.is_On = LCWS_subsystem_integ_IN_Passive;
    }

    /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
  }
  else
  {
    /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
    if ((!VsDCSN_DataBus.EnablingFlags_Group.lcw_feature_enable) ||
        (!KbLCWS_Switch))
    {
      LCWS_subsystem_integrated_DW.is_On = LCWS_subsyst_IN_NO_ACTIVE_CHILD;
      LCWS_subsystem_integrated_DW.is_Positive = LCWS_subsyst_IN_NO_ACTIVE_CHILD;
      LCWS_subsystem_integrated_DW.is_c3_LCWS_subsystem_integrated =
        LCWS_subsystem_integrate_IN_Off;
    }
    else if (((uint32_T)LCWS_subsystem_integrated_DW.is_On) ==
             LCWS_subsystem_integ_IN_Passive)
    {
      if (((VsCOMM_JAC_Bus_FedBck_Data.FedBck_VehDynmc.VCU1_ICPV_VehSpd >=
            KfLCWS_v_EnbleVehSpdThrshLo) &&
           (VsCOMM_JAC_Bus_FedBck_Data.FedBck_VehDynmc.VCU1_ICPV_VehSpd <
            KfLCWS_v_EnbleVehSpdThrshHi)) &&
          (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos ==
           ((uint8_T)1U)))
      {
        LCWS_subsystem_integrated_DW.is_On = LCWS_subsystem_inte_IN_Positive;
        LCWS_subsystem_integrated_DW.is_Positive =
          LCWS_subsystem_inte_IN_Inactive;
      }
    }
    else if (((VsCOMM_JAC_Bus_FedBck_Data.FedBck_VehDynmc.VCU1_ICPV_VehSpd <
               KfLCWS_v_DisbleVehSpdThrshLo) ||
              (VsCOMM_JAC_Bus_FedBck_Data.FedBck_VehDynmc.VCU1_ICPV_VehSpd >
               KfLCWS_v_DisbleVehSpdThrshHi)) ||
             (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos !=
              ((uint8_T)1U)))
    {
      LCWS_subsystem_integrated_DW.is_Positive = LCWS_subsyst_IN_NO_ACTIVE_CHILD;
      LCWS_subsystem_integrated_DW.is_On = LCWS_subsystem_integ_IN_Passive;
    }
    else if (((uint32_T)LCWS_subsystem_integrated_DW.is_Positive) ==
             LCWS_subsystem_integr_IN_Active)
    {
      if (((LCWS_subsystem_integrated_B.num_L == ((uint16_T)0U)) &&
           (LCWS_subsystem_integrated_B.num_R == ((uint16_T)0U))) ||
          (rtb_curvature > KfLCWS_c_DisbleCurveThrshMax))
      {
        LCWS_subsystem_integrated_DW.is_Positive =
          LCWS_subsystem_inte_IN_Inactive;
      }
    }
    else
    {
      if (((LCWS_subsystem_integrated_B.num_L != ((uint16_T)0U)) ||
           (LCWS_subsystem_integrated_B.num_R != ((uint16_T)0U))) &&
          (rtb_curvature < KfLCWS_c_EnbleCurveThrshMax))
      {
        LCWS_subsystem_integrated_DW.is_Positive =
          LCWS_subsystem_integr_IN_Active;
      }
    }

    /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
  }

  /* End of Chart: '<S4>/DtmnChart' */

  /* Outputs for Enabled SubSystem: '<S1>/CalcLLCWEnabledSubsystem' incorporates:
   *  EnablePort: '<S2>/LLCWEnable'
   */
  if (enable)
  {
    if (!LCWS_subsystem_integrated_DW.CalcLLCWEnabledSubsystem_MODE)
    {
      /* SystemReset for Chart: '<S2>/DtmnWarningChart' */
      LCWS_subsystem_integrated_DW.is_UnSafe_pitt =
        LCWS_subsyst_IN_NO_ACTIVE_CHILD;

      /* Chart: '<S2>/DtmnWarningChart' */
      LCWS_subsystem_integrated_DW.is_c4_LCWS_subsystem_integrated =
        LCWS_subsystem_integrat_IN_Safe;
      LCWS_subsystem_integrated_DW.CalcLLCWEnabledSubsystem_MODE = true;
    }

    /* MATLAB Function: '<S2>/Calc_LBSWFunction' incorporates:
     *  BusCreator: '<S20>/Bus Creator'
     *  Constant: '<S20>/Constant10'
     *  Constant: '<S20>/Constant2'
     *  Constant: '<S20>/Constant3'
     *  Constant: '<S20>/Constant4'
     *  Constant: '<S20>/Constant5'
     *  Constant: '<S20>/Constant6'
     *  Constant: '<S20>/Constant7'
     *  Constant: '<S20>/Constant8'
     *  Constant: '<S20>/Constant9'
     */
    BSW = 4U;
    LCWS_subsystem_integrated_B.bswL_ID = 0;

    /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
    rtb_KfLCWS_d_BSDLargerZone_FarD = KfLCWS_d_BSDZone_FrontDis;
    rtb_curvature = KfLCWS_d_BSDLargerZone_FrontDis;
    BSD_near1 = KfLCWS_d_BSDZone_NearDis;
    BSD_near2 = KfLCWS_d_BSDLargerZone_NearDis;
    BSD_far1 = KfLCWS_d_BSDZone_FarDis;
    i_0 = (int32_T)KfLCWS_d_BSDLargerZone_FarDis;
    y = KfLCWS_d_BSDZone_BackDis;
    BSD_back2 = KfLCWS_d_BSDLargerZone_BackDis;
    if (((((KfLCWS_d_BSDZone_FrontDis < 0.0F) || (KfLCWS_d_BSDZone_FrontDis >
            KfLCWS_d_BSDZone_Eye95Dis)) || (KfLCWS_d_BSDLargerZone_FrontDis <
           -1.0F)) || (KfLCWS_d_BSDLargerZone_FrontDis >
                       KfLCWS_d_BSDZone_Eye95Dis)) ||
        (KfLCWS_d_BSDLargerZone_FrontDis >= KfLCWS_d_BSDZone_FrontDis))
    {
      rtb_KfLCWS_d_BSDLargerZone_FarD = 1.0F;
      rtb_curvature = 0.0F;
    }

    if (((((KfLCWS_d_BSDZone_NearDis < -0.5F) || (KfLCWS_d_BSDZone_NearDis >
            0.5F)) || (KfLCWS_d_BSDLargerZone_NearDis < -0.5F)) ||
         (KfLCWS_d_BSDLargerZone_NearDis > 0.5F)) ||
        (KfLCWS_d_BSDLargerZone_NearDis >= KfLCWS_d_BSDZone_NearDis))
    {
      BSD_near1 = 0.3F;
      BSD_near2 = 0.0F;
    }

    if (((((KfLCWS_d_BSDZone_FarDis < 3.0F) || (KfLCWS_d_BSDZone_FarDis > 6.0F))
          || (KfLCWS_d_BSDLargerZone_FarDis < 3)) ||
         (KfLCWS_d_BSDLargerZone_FarDis > 6)) || (((real32_T)
          KfLCWS_d_BSDLargerZone_FarDis) <= KfLCWS_d_BSDZone_FarDis))
    {
      BSD_far1 = 4.0F;
      i_0 = 5;
    }

    if (((((KfLCWS_d_BSDZone_BackDis < 3.0F) || (KfLCWS_d_BSDZone_BackDis >
            30.0F)) || (KfLCWS_d_BSDLargerZone_BackDis < 3.0F)) ||
         (KfLCWS_d_BSDLargerZone_BackDis > 30.0F)) ||
        (KfLCWS_d_BSDLargerZone_BackDis <= KfLCWS_d_BSDZone_BackDis))
    {
      y = 5.0F;
      BSD_back2 = 6.0F;
    }

    /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
    if (((int32_T)LCWS_subsystem_integrated_B.num_L) <
        LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
    {
      num_L = LCWS_subsystem_integrated_B.num_L;
    }
    else
    {
      num_L = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0];
    }

    i = 1U;
    num_R = 1U;
    exitg1 = false;
    while ((!exitg1) && (num_R <= num_L))
    {
      i = num_R;
      obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0]) - 1],
                   LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 2)) - 1],
                   LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 3)) - 1],
                   LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 5)) - 1],
                   LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1], A,
                   B, C, unusedU1);
      if ((A[0] < (-rtb_KfLCWS_d_BSDLargerZone_FarD)) && (B[0] <
           (-rtb_KfLCWS_d_BSDLargerZone_FarD)))
      {
        tmp_0 = BSD_near1 + (KfLCWS_d_VehWidth * 0.5F);
        if ((B[1] > tmp_0) && (C[1] > tmp_0))
        {
          tmp_0 = BSD_far1 + (KfLCWS_d_VehWidth * 0.5F);
          if ((B[1] < tmp_0) || (C[1] < tmp_0))
          {
            tmp_0 = (-KfLCWS_d_VehLenth) - y;
            if (((A[0] > tmp_0) || (B[0] > tmp_0)) &&
                ((LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                   (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 7))
                  - 1] != 1.0F) || ((LCWS_subsystem_integrated_B.vec_L
                   [(((int32_T)num_R) +
                     (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] *
                      7)) - 1] == 1.0F) && (((real32_T)fabs((real_T)
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                      (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] *
                       4)) - 1])) < KfLCWS_v_OncomRelSpdThrshHi_in))))
            {
              BSW = 1U;
              tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_L[((int32_T)
                num_R) - 1]);
              if (tmp_0 < 2.14748365E+9F)
              {
                if (tmp_0 >= -2.14748365E+9F)
                {
                  LCWS_subsystem_integrated_B.bswL_ID = (int32_T)tmp_0;
                }
                else
                {
                  LCWS_subsystem_integrated_B.bswL_ID = MIN_int32_T;
                }
              }
              else
              {
                LCWS_subsystem_integrated_B.bswL_ID = MAX_int32_T;
              }

              exitg1 = true;
            }
            else
            {
              num_R = (uint16_T)(((uint32_T)num_R) + 1U);
            }
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
        else
        {
          num_R = (uint16_T)(((uint32_T)num_R) + 1U);
        }
      }
      else
      {
        num_R = (uint16_T)(((uint32_T)num_R) + 1U);
      }
    }

    if (((int32_T)BSW) != 1)
    {
      if (((int32_T)LCWS_subsystem_integrated_B.num_L) <
          LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
      {
        num_L = LCWS_subsystem_integrated_B.num_L;
      }
      else
      {
        num_L = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1
          [0];
      }

      num_R = 1U;
      exitg1 = false;
      while ((!exitg1) && (num_R <= num_L))
      {
        obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0]) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 2)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 3)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 5)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1],
                     A, B, C, unusedU1);
        if ((A[0] < (-rtb_curvature)) && (B[0] < (-rtb_curvature)))
        {
          tmp_0 = BSD_near2 + (KfLCWS_d_VehWidth * 0.5F);
          if ((B[1] > tmp_0) && (C[1] > tmp_0))
          {
            tmp_0 = ((real32_T)i_0) + (KfLCWS_d_VehWidth * 0.5F);
            if ((B[1] < tmp_0) || (C[1] < tmp_0))
            {
              tmp_0 = (-KfLCWS_d_VehLenth) - BSD_back2;
              if (((A[0] > tmp_0) || (B[0] > tmp_0)) &&
                  ((LCWS_subsystem_integrated_B.vec_L[(((int32_T)i) +
                     (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] *
                      7)) - 1] != 1.0F) || ((LCWS_subsystem_integrated_B.vec_L
                     [(((int32_T)i) +
                       (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0]
                        * 7)) - 1] == 1.0F) && (((real32_T)fabs((real_T)
                       LCWS_subsystem_integrated_B.vec_L[(((int32_T)i) +
                        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0]
                         * 4)) - 1])) < KfLCWS_v_OncomRelSpdThrshHi_out))))
              {
                BSW = 2U;
                tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_L[((int32_T)
                  num_R) - 1]);
                if (tmp_0 < 2.14748365E+9F)
                {
                  if (tmp_0 >= -2.14748365E+9F)
                  {
                    LCWS_subsystem_integrated_B.bswL_ID = (int32_T)tmp_0;
                  }
                  else
                  {
                    LCWS_subsystem_integrated_B.bswL_ID = MIN_int32_T;
                  }
                }
                else
                {
                  LCWS_subsystem_integrated_B.bswL_ID = MAX_int32_T;
                }

                exitg1 = true;
              }
              else
              {
                num_R = (uint16_T)(((uint32_T)num_R) + 1U);
              }
            }
            else
            {
              num_R = (uint16_T)(((uint32_T)num_R) + 1U);
            }
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
        else
        {
          num_R = (uint16_T)(((uint32_T)num_R) + 1U);
        }
      }
    }

    if ((((int32_T)BSW) != 1) && (((int32_T)BSW) != 2))
    {
      if (((int32_T)LCWS_subsystem_integrated_B.num_L) <
          LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
      {
        i = LCWS_subsystem_integrated_B.num_L;
      }
      else
      {
        i = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0];
      }

      num_L = 1U;
      exitg1 = false;
      while ((!exitg1) && (num_L <= i))
      {
        obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0]) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 2)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 3)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 5)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1],
                     A, B, C, unusedU1);
        if ((((A[0] > 0.0F) && (B[0] > 0.0F)) && (C[0] > 0.0F)) && (unusedU1[0] >
             0.0F))
        {
          b = true;
        }
        else if ((((A[0] < ((-KfLCWS_d_VehLenth) - 30.0F)) && (B[0] <
                    ((-KfLCWS_d_VehLenth) - 30.0F))) && (C[0] <
                   ((-KfLCWS_d_VehLenth) - 30.0F))) && (unusedU1[0] <
                  ((-KfLCWS_d_VehLenth) - 30.0F)))
        {
          b = true;
        }
        else
        {
          tmp_0 = 6.0F + (KfLCWS_d_VehWidth * 0.5F);
          if ((((A[1] > tmp_0) && (B[1] > tmp_0)) && (C[1] > tmp_0)) &&
              (unusedU1[1] > tmp_0))
          {
            b = true;
          }
          else
          {
            b = ((A[1] < (KfLCWS_d_VehWidth * 0.5F)) && ((B[1] <
                   (KfLCWS_d_VehWidth * 0.5F)) && ((C[1] < (KfLCWS_d_VehWidth *
                     0.5F)) && (unusedU1[1] < (KfLCWS_d_VehWidth * 0.5F)))));
          }
        }

        if (!b)
        {
          BSW = 3U;
          tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_L[((int32_T)num_L) -
                            1]);
          if (tmp_0 < 2.14748365E+9F)
          {
            if (tmp_0 >= -2.14748365E+9F)
            {
              LCWS_subsystem_integrated_B.bswL_ID = (int32_T)tmp_0;
            }
            else
            {
              LCWS_subsystem_integrated_B.bswL_ID = MIN_int32_T;
            }
          }
          else
          {
            LCWS_subsystem_integrated_B.bswL_ID = MAX_int32_T;
          }

          exitg1 = true;
        }
        else
        {
          num_L = (uint16_T)(((uint32_T)num_L) + 1U);
        }
      }
    }

    /* DataTypeConversion: '<S2>/DataTypeConversion' incorporates:
     *  MATLAB Function: '<S2>/Calc_LBSWFunction'
     */
    BSW_nwgt = (EnumLCWS_warningArea)BSW;

    /* RateTransition: '<S2>/Rate Transition1' incorporates:
     *  MATLAB Function: '<S2>/Calc_LBSWFunction'
     */
    ViLCWS_bswLL = (EnumLCWS_warningArea)BSW;

    /* Gain: '<S2>/Gain' */
    ViLCWS_bswL_ID = mul_s32_loSR(1073741824,
      LCWS_subsystem_integrated_B.bswL_ID, 30U);

    /* Gain: '<S2>/Gain2' incorporates:
     *  MATLAB Function: '<S2>/Calc_LBSWFunction'
     */
    ViLCWS_bswL = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)BSW)) >> 7);

    /* MATLAB Function: '<S2>/Calc_LCVWFunction' incorporates:
     *  BusCreator: '<S20>/Bus Creator'
     *  Constant: '<S20>/Constant11'
     *  Constant: '<S20>/Constant12'
     *  Constant: '<S20>/Constant2'
     *  Constant: '<S20>/Constant3'
     *  Constant: '<S20>/Constant4'
     *  Constant: '<S20>/Constant5'
     */
    BSW = 4U;
    LCWS_subsystem_integrated_B.cvwL_ID = 0;

    /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
    rtb_KfLCWS_d_BSDLargerZone_FarD = KfLCWS_d_CVZone_FrontDis;
    rtb_curvature = KfLCWS_d_CVLargerZone_FrontDis;
    BSD_near1 = KfLCWS_d_BSDZone_NearDis;
    BSD_near2 = KfLCWS_d_BSDLargerZone_NearDis;
    BSD_far1 = KfLCWS_d_BSDZone_FarDis;
    i_0 = (int32_T)KfLCWS_d_BSDLargerZone_FarDis;
    if (((((KfLCWS_d_CVZone_FrontDis > 3.0F) || (KfLCWS_d_CVZone_FrontDis < 0.0F))
          || (KfLCWS_d_CVLargerZone_FrontDis > 3.0F)) ||
         (KfLCWS_d_CVLargerZone_FrontDis < 0.0F)) ||
        (KfLCWS_d_CVLargerZone_FrontDis >= KfLCWS_d_CVZone_FrontDis))
    {
      rtb_KfLCWS_d_BSDLargerZone_FarD = 2.0F;
      rtb_curvature = 1.0F;
    }

    if (((((KfLCWS_d_BSDZone_NearDis < -0.5F) || (KfLCWS_d_BSDZone_NearDis >
            0.5F)) || (KfLCWS_d_BSDLargerZone_NearDis < -0.5F)) ||
         (KfLCWS_d_BSDLargerZone_NearDis > 0.5F)) ||
        (KfLCWS_d_BSDLargerZone_NearDis >= KfLCWS_d_BSDZone_NearDis))
    {
      BSD_near1 = 0.3F;
      BSD_near2 = 0.0F;
    }

    if (((((KfLCWS_d_BSDZone_FarDis < 3.0F) || (KfLCWS_d_BSDZone_FarDis > 6.0F))
          || (KfLCWS_d_BSDLargerZone_FarDis < 3)) ||
         (KfLCWS_d_BSDLargerZone_FarDis > 6)) || (((real32_T)
          KfLCWS_d_BSDLargerZone_FarDis) <= KfLCWS_d_BSDZone_FarDis))
    {
      BSD_far1 = 4.0F;
      i_0 = 5;
    }

    /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
    if (((int32_T)LCWS_subsystem_integrated_B.num_L) <
        LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
    {
      num_L = LCWS_subsystem_integrated_B.num_L;
    }
    else
    {
      num_L = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0];
    }

    i = 1U;
    num_R = 1U;
    exitg1 = false;
    while ((!exitg1) && (num_R <= num_L))
    {
      i = num_R;
      y = LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 2)) - 1];
      if (LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
           (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10)) - 1]
          < (-KfLCWS_v_LatSpdThr))
      {
        y = LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 2)) - 1] -
          (LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
            (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1]
           * KfLCWS_r_ObtWidthProportion);
      }

      if (LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
           (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10)) - 1]
          > KfLCWS_v_LatSpdThr)
      {
        y += LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1] *
          KfLCWS_r_ObtWidthProportion;
      }

      obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0]) - 1], y,
                   LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 3)) - 1],
                   LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 5)) - 1],
                   LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1], A,
                   B, C, unusedU1);
      y = 100.0F;
      if (((real_T)LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
            (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4)) - 1])
          > 0.001)
      {
        B_0[0] = B[0] - (-KfLCWS_d_VehLenth);
        B_0[1] = B[1] - (KfLCWS_d_VehWidth * 0.5F);
        y = norm_TbqwX7rn(B_0) / LCWS_subsystem_integrated_B.vec_L[(((int32_T)
          num_R) + (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4))
          - 1];
      }

      tmp_0 = (-rtb_KfLCWS_d_BSDLargerZone_FarD) - KfLCWS_d_VehLenth;
      if ((A[0] < tmp_0) && (B[0] < tmp_0))
      {
        tmp_0 = BSD_near1 + (KfLCWS_d_VehWidth * 0.5F);
        if ((B[1] > tmp_0) && (C[1] > tmp_0))
        {
          tmp_0 = BSD_far1 + (KfLCWS_d_VehWidth * 0.5F);
          if (((B[1] < tmp_0) || (C[1] < tmp_0)) && (y <
               KfLCWS_t_TTCThrshLowLevel))
          {
            BSW = 1U;
            tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_L[((int32_T)num_R)
                              - 1]);
            if (tmp_0 < 2.14748365E+9F)
            {
              if (tmp_0 >= -2.14748365E+9F)
              {
                LCWS_subsystem_integrated_B.cvwL_ID = (int32_T)tmp_0;
              }
              else
              {
                LCWS_subsystem_integrated_B.cvwL_ID = MIN_int32_T;
              }
            }
            else
            {
              LCWS_subsystem_integrated_B.cvwL_ID = MAX_int32_T;
            }

            exitg1 = true;
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
        else
        {
          num_R = (uint16_T)(((uint32_T)num_R) + 1U);
        }
      }
      else
      {
        num_R = (uint16_T)(((uint32_T)num_R) + 1U);
      }
    }

    if (((int32_T)BSW) != 1)
    {
      if (((int32_T)LCWS_subsystem_integrated_B.num_L) <
          LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
      {
        num_L = LCWS_subsystem_integrated_B.num_L;
      }
      else
      {
        num_L = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1
          [0];
      }

      num_R = 1U;
      exitg1 = false;
      while ((!exitg1) && (num_R <= num_L))
      {
        y = LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 2)) - 1];
        if (LCWS_subsystem_integrated_B.vec_L[(((int32_T)i) +
             (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10)) -
            1] < (-KfLCWS_v_LatSpdThr))
        {
          y = LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
            (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 2)) - 1]
            - (LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6))
               - 1] * KfLCWS_r_ObtWidthProportion);
        }

        if (LCWS_subsystem_integrated_B.vec_L[(((int32_T)i) +
             (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10)) -
            1] > KfLCWS_v_LatSpdThr)
        {
          y += LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
            (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1]
            * KfLCWS_r_ObtWidthProportion;
        }

        obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0]) - 1], y,
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 3)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 5)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1],
                     A, B, C, unusedU1);
        y = 100.0F;
        if (((real_T)LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
              (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4)) -
             1]) > 0.001)
        {
          B_0[0] = B[0] - (-KfLCWS_d_VehLenth);
          B_0[1] = B[1] - (KfLCWS_d_VehWidth * 0.5F);
          y = norm_TbqwX7rn(B_0) / LCWS_subsystem_integrated_B.vec_L[(((int32_T)
            num_R) + (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] *
                      4)) - 1];
        }

        tmp_0 = (-rtb_curvature) - KfLCWS_d_VehLenth;
        if ((A[0] < tmp_0) && (B[0] < tmp_0))
        {
          tmp_0 = BSD_near2 + (KfLCWS_d_VehWidth * 0.5F);
          if ((B[1] > tmp_0) && (C[1] > tmp_0))
          {
            tmp_0 = ((real32_T)i_0) + (KfLCWS_d_VehWidth * 0.5F);
            if (((B[1] < tmp_0) || (C[1] < tmp_0)) && (y <
                 KfLCWS_t_TTCLargerThrsh_LowLevel))
            {
              BSW = 2U;
              tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_L[((int32_T)
                num_R) - 1]);
              if (tmp_0 < 2.14748365E+9F)
              {
                if (tmp_0 >= -2.14748365E+9F)
                {
                  LCWS_subsystem_integrated_B.cvwL_ID = (int32_T)tmp_0;
                }
                else
                {
                  LCWS_subsystem_integrated_B.cvwL_ID = MIN_int32_T;
                }
              }
              else
              {
                LCWS_subsystem_integrated_B.cvwL_ID = MAX_int32_T;
              }

              exitg1 = true;
            }
            else
            {
              num_R = (uint16_T)(((uint32_T)num_R) + 1U);
            }
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
        else
        {
          num_R = (uint16_T)(((uint32_T)num_R) + 1U);
        }
      }
    }

    if ((((int32_T)BSW) != 1) && (((int32_T)BSW) != 2))
    {
      if (((int32_T)LCWS_subsystem_integrated_B.num_L) <
          LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
      {
        i = LCWS_subsystem_integrated_B.num_L;
      }
      else
      {
        i = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0];
      }

      num_L = 1U;
      exitg1 = false;
      while ((!exitg1) && (num_L <= i))
      {
        obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0]) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 2)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 3)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 5)) - 1],
                     LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1],
                     A, B, C, unusedU1);
        y = 100.0F;
        if (((real_T)LCWS_subsystem_integrated_B.vec_L[(((int32_T)num_L) +
              (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4)) -
             1]) > 0.001)
        {
          B_0[0] = B[0] - (-KfLCWS_d_VehLenth);
          B_0[1] = B[1] - (KfLCWS_d_VehWidth * 0.5F);
          y = norm_TbqwX7rn(B_0) / LCWS_subsystem_integrated_B.vec_L[(((int32_T)
            num_L) + (LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] *
                      4)) - 1];
        }

        if (((y > 7.5F) && (A[0] < (-30.0F - KfLCWS_d_VehLenth))) && (B[0] <
             (-30.0F - KfLCWS_d_VehLenth)))
        {
          b = true;
        }
        else if ((unusedU1[0] > (-KfLCWS_d_VehLenth)) && (C[0] >
                  (-KfLCWS_d_VehLenth)))
        {
          b = true;
        }
        else if (unusedU1[0] > (-30.0F - KfLCWS_d_VehLenth))
        {
          if (C[0] > (-30.0F - KfLCWS_d_VehLenth))
          {
            if ((B[1] < (KfLCWS_d_VehWidth * 0.5F)) && (C[1] <
                 (KfLCWS_d_VehWidth * 0.5F)))
            {
              b = true;
            }
            else
            {
              b = ((A[1] > (6.0F + (KfLCWS_d_VehWidth * 0.5F))) && (unusedU1[1] >
                    (6.0F + (KfLCWS_d_VehWidth * 0.5F))));
            }
          }
          else
          {
            b = false;
          }
        }
        else
        {
          b = false;
        }

        if (!b)
        {
          BSW = 3U;
          tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_L[((int32_T)num_L) -
                            1]);
          if (tmp_0 < 2.14748365E+9F)
          {
            if (tmp_0 >= -2.14748365E+9F)
            {
              LCWS_subsystem_integrated_B.cvwL_ID = (int32_T)tmp_0;
            }
            else
            {
              LCWS_subsystem_integrated_B.cvwL_ID = MIN_int32_T;
            }
          }
          else
          {
            LCWS_subsystem_integrated_B.cvwL_ID = MAX_int32_T;
          }

          exitg1 = true;
        }
        else
        {
          num_L = (uint16_T)(((uint32_T)num_L) + 1U);
        }
      }
    }

    /* Gain: '<S2>/Gain1' */
    ViLCWS_cvwL_ID = mul_s32_loSR(1073741824,
      LCWS_subsystem_integrated_B.cvwL_ID, 30U);

    /* Gain: '<S2>/Gain3' incorporates:
     *  MATLAB Function: '<S2>/Calc_LCVWFunction'
     */
    ViLCWS_cvwL = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)BSW)) >> 7);

    /* Chart: '<S2>/DtmnWarningChart' incorporates:
     *  Constant: '<S21>/Constant2'
     *  MATLAB Function: '<S2>/Calc_LCVWFunction'
     */
    if (((uint32_T)LCWS_subsystem_integrated_DW.is_c4_LCWS_subsystem_integrated)
        == LCWS_subsystem_integrat_IN_Safe)
    {
      LCWS_subsystem_integrated_B.warning_left1 = false;
      LCWS_subsystem_integrated_B.warning_left2 = false;
      LCWS_subsystem_integrated_B.left_warning_status = LCWS_NO_WARNING;
    }
    else if (((uint32_T)LCWS_subsystem_integrated_DW.is_UnSafe_pitt) ==
             LCWS_subs_IN_Warning_left1level)
    {
      LCWS_subsystem_integrated_B.warning_left1 = true;
      LCWS_subsystem_integrated_B.left_warning_status = LCWS_WARNING_LOW_LEVEL;
    }
    else
    {
      LCWS_subsystem_integrated_B.warning_left2 = true;
      LCWS_subsystem_integrated_B.left_warning_status = LCWS_WARNING_HIGH_LEVEL;
    }

    if (((uint32_T)LCWS_subsystem_integrated_DW.is_c4_LCWS_subsystem_integrated)
        == LCWS_subsystem_integrat_IN_Safe)
    {
      if ((((uint32_T)BSW_nwgt) == WARNING_S_AREA) || (((uint32_T)BSW) ==
           WARNING_S_AREA))
      {
        LCWS_subsystem_integrated_DW.is_c4_LCWS_subsystem_integrated =
          LCWS_subsystem_integr_IN_UnSafe;
        LCWS_subsystem_integrated_DW.is_UnSafe_pitt =
          LCWS_subs_IN_Warning_left1level;
      }
    }
    else if (((((((uint32_T)BSW_nwgt) != WARNING_S_AREA) && (((uint32_T)BSW_nwgt)
      != WARNING_L_AREA)) && (((uint32_T)BSW) != WARNING_S_AREA)) && (((uint32_T)
                BSW) != WARNING_L_AREA)) || ((((uint32_T)BSW) == NO_WARNING_AREA)
              && (((uint32_T)BSW_nwgt) == NO_WARNING_AREA)))
    {
      LCWS_subsystem_integrated_DW.is_UnSafe_pitt =
        LCWS_subsyst_IN_NO_ACTIVE_CHILD;
      LCWS_subsystem_integrated_DW.is_c4_LCWS_subsystem_integrated =
        LCWS_subsystem_integrat_IN_Safe;
    }
    else if (((uint32_T)LCWS_subsystem_integrated_DW.is_UnSafe_pitt) ==
             LCWS_subs_IN_Warning_left1level)
    {
      if (false)
      {
        LCWS_subsystem_integrated_DW.is_UnSafe_pitt =
          LCWS_subs_IN_Warning_left2level;
      }
    }
    else
    {
      if (!false)
      {
        LCWS_subsystem_integrated_DW.is_UnSafe_pitt =
          LCWS_subs_IN_Warning_left1level;
      }
    }

    /* RateTransition: '<S2>/Rate Transition' */
    VeLCWS_left_warning_status = LCWS_subsystem_integrated_B.left_warning_status;
  }
  else
  {
    if (LCWS_subsystem_integrated_DW.CalcLLCWEnabledSubsystem_MODE)
    {
      LCWS_subsystem_integrated_DW.CalcLLCWEnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/CalcLLCWEnabledSubsystem' */

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S21>/Constant'
   *  Logic: '<S6>/Logical Operator'
   */
  rtb_LogicalOperator1 = ((false) || (!enable));

  /* Switch: '<S6>/Switch6' incorporates:
   *  Constant: '<S6>/Constant6'
   */
  if (rtb_LogicalOperator1)
  {
    VsLCWS_DataBus.bswL_ID = 0;
  }
  else
  {
    VsLCWS_DataBus.bswL_ID = LCWS_subsystem_integrated_B.bswL_ID;
  }

  /* End of Switch: '<S6>/Switch6' */

  /* Switch: '<S6>/Switch7' incorporates:
   *  Constant: '<S6>/Constant7'
   */
  if (rtb_LogicalOperator1)
  {
    VsLCWS_DataBus.cvwL_ID = 0;
  }
  else
  {
    VsLCWS_DataBus.cvwL_ID = LCWS_subsystem_integrated_B.cvwL_ID;
  }

  /* End of Switch: '<S6>/Switch7' */

  /* Outputs for Enabled SubSystem: '<S1>/CalcRLCWEnabledSubsystem' incorporates:
   *  EnablePort: '<S3>/RLCWEnable'
   */
  if (enable)
  {
    if (!LCWS_subsystem_integrated_DW.CalcRLCWEnabledSubsystem_MODE)
    {
      /* SystemReset for Chart: '<S3>/DtmnWarningChart' */
      LCWS_subsystem_integrated_DW.is_UnSafe = LCWS_subsyst_IN_NO_ACTIVE_CHILD;

      /* Chart: '<S3>/DtmnWarningChart' */
      LCWS_subsystem_integrated_DW.is_c5_LCWS_subsystem_integrated =
        LCWS_subsystem_integrat_IN_Safe;
      LCWS_subsystem_integrated_DW.CalcRLCWEnabledSubsystem_MODE = true;
    }

    /* MATLAB Function: '<S3>/CalcRBSWFunction' incorporates:
     *  BusCreator: '<S20>/Bus Creator'
     *  Constant: '<S20>/Constant10'
     *  Constant: '<S20>/Constant2'
     *  Constant: '<S20>/Constant3'
     *  Constant: '<S20>/Constant4'
     *  Constant: '<S20>/Constant5'
     *  Constant: '<S20>/Constant6'
     *  Constant: '<S20>/Constant7'
     *  Constant: '<S20>/Constant8'
     *  Constant: '<S20>/Constant9'
     */
    BSW = 4U;
    LCWS_subsystem_integrated_B.bswR_ID = 0;

    /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
    rtb_KfLCWS_d_BSDLargerZone_FarD = KfLCWS_d_BSDZone_FrontDis;
    rtb_curvature = KfLCWS_d_BSDLargerZone_FrontDis;
    BSD_near1 = KfLCWS_d_BSDZone_NearDis;
    BSD_near2 = KfLCWS_d_BSDLargerZone_NearDis;
    BSD_far1 = KfLCWS_d_BSDZone_FarDis;
    i_0 = (int32_T)KfLCWS_d_BSDLargerZone_FarDis;
    y = KfLCWS_d_BSDZone_BackDis;
    BSD_back2 = KfLCWS_d_BSDLargerZone_BackDis;
    if (((((KfLCWS_d_BSDZone_FrontDis < 0.0F) || (KfLCWS_d_BSDZone_FrontDis >
            KfLCWS_d_BSDZone_Eye95Dis)) || (KfLCWS_d_BSDLargerZone_FrontDis <
           -1.0F)) || (KfLCWS_d_BSDLargerZone_FrontDis >
                       KfLCWS_d_BSDZone_Eye95Dis)) ||
        (KfLCWS_d_BSDLargerZone_FrontDis >= KfLCWS_d_BSDZone_FrontDis))
    {
      rtb_KfLCWS_d_BSDLargerZone_FarD = 1.0F;
      rtb_curvature = 0.0F;
    }

    if (((((KfLCWS_d_BSDZone_NearDis < -0.5F) || (KfLCWS_d_BSDZone_NearDis >
            0.5F)) || (KfLCWS_d_BSDLargerZone_NearDis < -0.5F)) ||
         (KfLCWS_d_BSDLargerZone_NearDis > 0.5F)) ||
        (KfLCWS_d_BSDLargerZone_NearDis >= KfLCWS_d_BSDZone_NearDis))
    {
      BSD_near1 = 0.3F;
      BSD_near2 = 0.0F;
    }

    if (((((KfLCWS_d_BSDZone_FarDis < 3.0F) || (KfLCWS_d_BSDZone_FarDis > 6.0F))
          || (KfLCWS_d_BSDLargerZone_FarDis < 3)) ||
         (KfLCWS_d_BSDLargerZone_FarDis > 6)) || (((real32_T)
          KfLCWS_d_BSDLargerZone_FarDis) <= KfLCWS_d_BSDZone_FarDis))
    {
      BSD_far1 = 4.0F;
      i_0 = 5;
    }

    if (((((KfLCWS_d_BSDZone_BackDis < 3.0F) || (KfLCWS_d_BSDZone_BackDis >
            30.0F)) || (KfLCWS_d_BSDLargerZone_BackDis < 3.0F)) ||
         (KfLCWS_d_BSDLargerZone_BackDis > 30.0F)) ||
        (KfLCWS_d_BSDLargerZone_BackDis <= KfLCWS_d_BSDZone_BackDis))
    {
      y = 5.0F;
      BSD_back2 = 6.0F;
    }

    /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
    if (((int32_T)LCWS_subsystem_integrated_B.num_R) <
        LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
    {
      num_L = LCWS_subsystem_integrated_B.num_R;
    }
    else
    {
      num_L = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
    }

    i = 1U;
    num_R = 1U;
    exitg1 = false;
    while ((!exitg1) && (num_R <= num_L))
    {
      i = num_R;
      obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0]) - 1],
                   LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 2)) - 1],
                   LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 3)) - 1],
                   LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 5)) - 1],
                   LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1], A,
                   B, unusedU1, C);
      if ((A[0] < (-rtb_KfLCWS_d_BSDLargerZone_FarD)) && (B[0] <
           (-rtb_KfLCWS_d_BSDLargerZone_FarD)))
      {
        tmp_0 = (-BSD_near1) - (KfLCWS_d_VehWidth * 0.5F);
        if ((A[1] < tmp_0) && (C[1] < tmp_0))
        {
          tmp_0 = (-BSD_far1) - (KfLCWS_d_VehWidth * 0.5F);
          if ((A[1] > tmp_0) || (C[1] > tmp_0))
          {
            tmp_0 = (-KfLCWS_d_VehLenth) - y;
            if (((A[0] > tmp_0) || (B[0] > tmp_0)) &&
                ((LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                   (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] *
                    7)) - 1] != 1.0F) || ((LCWS_subsystem_integrated_B.vec_R
                   [(((int32_T)num_R) +
                     (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] *
                      7)) - 1] == 1.0F) && (((real32_T)fabs((real_T)
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                      (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0]
                       * 4)) - 1])) < KfLCWS_v_OncomRelSpdThrshHi_in))))
            {
              BSW = 1U;
              tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_R[((int32_T)
                num_R) - 1]);
              if (tmp_0 < 2.14748365E+9F)
              {
                if (tmp_0 >= -2.14748365E+9F)
                {
                  LCWS_subsystem_integrated_B.bswR_ID = (int32_T)tmp_0;
                }
                else
                {
                  LCWS_subsystem_integrated_B.bswR_ID = MIN_int32_T;
                }
              }
              else
              {
                LCWS_subsystem_integrated_B.bswR_ID = MAX_int32_T;
              }

              exitg1 = true;
            }
            else
            {
              num_R = (uint16_T)(((uint32_T)num_R) + 1U);
            }
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
        else
        {
          num_R = (uint16_T)(((uint32_T)num_R) + 1U);
        }
      }
      else
      {
        num_R = (uint16_T)(((uint32_T)num_R) + 1U);
      }
    }

    if (((int32_T)BSW) != 1)
    {
      if (((int32_T)LCWS_subsystem_integrated_B.num_R) <
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
      {
        num_L = LCWS_subsystem_integrated_B.num_R;
      }
      else
      {
        num_L = (uint16_T)
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
      }

      num_R = 1U;
      exitg1 = false;
      while ((!exitg1) && (num_R <= num_L))
      {
        obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0]) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 2)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 3)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 5)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1],
                     A, B, unusedU1, C);
        if ((A[0] < (-rtb_curvature)) && (B[0] < (-rtb_curvature)))
        {
          tmp_0 = (-BSD_near2) - (KfLCWS_d_VehWidth * 0.5F);
          if ((A[1] < tmp_0) && (C[1] < tmp_0))
          {
            tmp_0 = (-((real32_T)i_0)) - (KfLCWS_d_VehWidth * 0.5F);
            if ((A[1] > tmp_0) || (C[1] > tmp_0))
            {
              tmp_0 = (-KfLCWS_d_VehLenth) - BSD_back2;
              if (((A[0] > tmp_0) || (B[0] > tmp_0)) &&
                  ((LCWS_subsystem_integrated_B.vec_R[(((int32_T)i) +
                     (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] *
                      7)) - 1] != 1.0F) || ((LCWS_subsystem_integrated_B.vec_R
                     [(((int32_T)i) +
                       (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0]
                        * 7)) - 1] == 1.0F) && (((real32_T)fabs((real_T)
                       LCWS_subsystem_integrated_B.vec_R[(((int32_T)i) +
                        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1
                         [0] * 4)) - 1])) < KfLCWS_v_OncomRelSpdThrshHi_out))))
              {
                BSW = 2U;
                tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_R[((int32_T)
                  num_R) - 1]);
                if (tmp_0 < 2.14748365E+9F)
                {
                  if (tmp_0 >= -2.14748365E+9F)
                  {
                    LCWS_subsystem_integrated_B.bswR_ID = (int32_T)tmp_0;
                  }
                  else
                  {
                    LCWS_subsystem_integrated_B.bswR_ID = MIN_int32_T;
                  }
                }
                else
                {
                  LCWS_subsystem_integrated_B.bswR_ID = MAX_int32_T;
                }

                exitg1 = true;
              }
              else
              {
                num_R = (uint16_T)(((uint32_T)num_R) + 1U);
              }
            }
            else
            {
              num_R = (uint16_T)(((uint32_T)num_R) + 1U);
            }
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
        else
        {
          num_R = (uint16_T)(((uint32_T)num_R) + 1U);
        }
      }
    }

    if ((((int32_T)BSW) != 1) && (((int32_T)BSW) != 2))
    {
      if (((int32_T)LCWS_subsystem_integrated_B.num_R) <
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
      {
        i = LCWS_subsystem_integrated_B.num_R;
      }
      else
      {
        i = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
      }

      num_L = 1U;
      exitg1 = false;
      while ((!exitg1) && (num_L <= i))
      {
        obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0]) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 2)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 3)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 5)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1],
                     A, B, unusedU1, C);
        if ((((A[0] > 0.0F) && (B[0] > 0.0F)) && (unusedU1[0] > 0.0F)) && (C[0] >
             0.0F))
        {
          b = true;
        }
        else if ((((A[0] < ((-KfLCWS_d_VehLenth) - 30.0F)) && (B[0] <
                    ((-KfLCWS_d_VehLenth) - 30.0F))) && (unusedU1[0] <
                   ((-KfLCWS_d_VehLenth) - 30.0F))) && (C[0] <
                  ((-KfLCWS_d_VehLenth) - 30.0F)))
        {
          b = true;
        }
        else
        {
          tmp_0 = -6.0F - (KfLCWS_d_VehWidth * 0.5F);
          if ((((A[1] < tmp_0) && (B[1] < tmp_0)) && (unusedU1[1] < tmp_0)) &&
              (C[1] < tmp_0))
          {
            b = true;
          }
          else
          {
            rtb_KfLCWS_d_BSDLargerZone_FarD = (-KfLCWS_d_VehWidth) * 0.5F;
            b = ((A[1] > rtb_KfLCWS_d_BSDLargerZone_FarD) && ((B[1] >
                   rtb_KfLCWS_d_BSDLargerZone_FarD) && ((unusedU1[1] >
                    rtb_KfLCWS_d_BSDLargerZone_FarD) && (C[1] >
                    rtb_KfLCWS_d_BSDLargerZone_FarD))));
          }
        }

        if (!b)
        {
          BSW = 3U;
          tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_R[((int32_T)num_L) -
                            1]);
          if (tmp_0 < 2.14748365E+9F)
          {
            if (tmp_0 >= -2.14748365E+9F)
            {
              LCWS_subsystem_integrated_B.bswR_ID = (int32_T)tmp_0;
            }
            else
            {
              LCWS_subsystem_integrated_B.bswR_ID = MIN_int32_T;
            }
          }
          else
          {
            LCWS_subsystem_integrated_B.bswR_ID = MAX_int32_T;
          }

          exitg1 = true;
        }
        else
        {
          num_L = (uint16_T)(((uint32_T)num_L) + 1U);
        }
      }
    }

    /* DataTypeConversion: '<S3>/Data_Type_Conversion' incorporates:
     *  MATLAB Function: '<S3>/CalcRBSWFunction'
     */
    BSW_nwgt = (EnumLCWS_warningArea)BSW;

    /* Gain: '<S3>/Gain2' */
    ViLCWS_bswR_ID = mul_s32_loSR(1073741824,
      LCWS_subsystem_integrated_B.bswR_ID, 30U);

    /* Gain: '<S3>/Gain3' incorporates:
     *  MATLAB Function: '<S3>/CalcRBSWFunction'
     */
    ViLCWS_bswR = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)BSW)) >> 7);

    /* MATLAB Function: '<S3>/CalcRCVWFunction' incorporates:
     *  BusCreator: '<S20>/Bus Creator'
     *  Constant: '<S20>/Constant11'
     *  Constant: '<S20>/Constant12'
     *  Constant: '<S20>/Constant2'
     *  Constant: '<S20>/Constant3'
     *  Constant: '<S20>/Constant4'
     *  Constant: '<S20>/Constant5'
     */
    BSW = 4U;
    LCWS_subsystem_integrated_B.cvwR_ID = 0;

    /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
    rtb_KfLCWS_d_BSDLargerZone_FarD = KfLCWS_d_CVZone_FrontDis;
    rtb_curvature = KfLCWS_d_CVLargerZone_FrontDis;
    BSD_near1 = KfLCWS_d_BSDZone_NearDis;
    BSD_near2 = KfLCWS_d_BSDLargerZone_NearDis;
    BSD_far1 = KfLCWS_d_BSDZone_FarDis;
    i_0 = (int32_T)KfLCWS_d_BSDLargerZone_FarDis;
    if (((((KfLCWS_d_CVZone_FrontDis > 3.0F) || (KfLCWS_d_CVZone_FrontDis < 0.0F))
          || (KfLCWS_d_CVLargerZone_FrontDis > 3.0F)) ||
         (KfLCWS_d_CVLargerZone_FrontDis < 0.0F)) ||
        (KfLCWS_d_CVLargerZone_FrontDis >= KfLCWS_d_CVZone_FrontDis))
    {
      rtb_KfLCWS_d_BSDLargerZone_FarD = 2.0F;
      rtb_curvature = 1.0F;
    }

    if (((((KfLCWS_d_BSDZone_NearDis < 0.0F) || (KfLCWS_d_BSDZone_NearDis > 0.5F))
          || (KfLCWS_d_BSDLargerZone_NearDis < 0.0F)) ||
         (KfLCWS_d_BSDLargerZone_NearDis > 0.5F)) ||
        (KfLCWS_d_BSDLargerZone_NearDis >= KfLCWS_d_BSDZone_NearDis))
    {
      BSD_near1 = 0.3F;
      BSD_near2 = 0.1F;
    }

    if (((((KfLCWS_d_BSDZone_FarDis < 3.0F) || (KfLCWS_d_BSDZone_FarDis > 6.0F))
          || (KfLCWS_d_BSDLargerZone_FarDis < 3)) ||
         (KfLCWS_d_BSDLargerZone_FarDis > 6)) || (((real32_T)
          KfLCWS_d_BSDLargerZone_FarDis) <= KfLCWS_d_BSDZone_FarDis))
    {
      BSD_far1 = 4.0F;
      i_0 = 5;
    }

    /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
    if (((int32_T)LCWS_subsystem_integrated_B.num_R) <
        LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
    {
      num_L = LCWS_subsystem_integrated_B.num_R;
    }
    else
    {
      num_L = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
    }

    i = 1U;
    num_R = 1U;
    exitg1 = false;
    while ((!exitg1) && (num_R <= num_L))
    {
      i = num_R;
      y = LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 2)) - 1];
      if (LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
           (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 10)) - 1]
          < (-KfLCWS_v_LatSpdThr))
      {
        y = LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 2)) - 1]
          - (LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
              (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) -
             1] * KfLCWS_r_ObtWidthProportion);
      }

      if (LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
           (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 10)) - 1]
          > KfLCWS_v_LatSpdThr)
      {
        y += LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1] *
          KfLCWS_r_ObtWidthProportion;
      }

      obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0]) - 1], y,
                   LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 3)) - 1],
                   LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 5)) - 1],
                   LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
        (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1], A,
                   B, unusedU1, C);
      y = 100.0F;
      if (((real_T)LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
            (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 4)) - 1])
          > 0.001)
      {
        B_0[0] = A[0] - (-KfLCWS_d_VehLenth);
        B_0[1] = A[1] - (KfLCWS_d_VehWidth * 0.5F);
        y = norm_TbqwX7rn(B_0) / LCWS_subsystem_integrated_B.vec_R[(((int32_T)
          num_R) + (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] *
                    4)) - 1];
      }

      tmp_0 = (-rtb_KfLCWS_d_BSDLargerZone_FarD) - KfLCWS_d_VehLenth;
      if ((A[0] < tmp_0) && (B[0] < tmp_0))
      {
        tmp_0 = (-BSD_near1) - (KfLCWS_d_VehWidth * 0.5F);
        if ((A[1] < tmp_0) && (C[1] < tmp_0))
        {
          tmp_0 = (-BSD_far1) - (KfLCWS_d_VehWidth * 0.5F);
          if (((A[1] > tmp_0) || (C[1] > tmp_0)) && (y <
               KfLCWS_t_TTCThrshLowLevel))
          {
            BSW = 1U;
            tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_R[((int32_T)num_R)
                              - 1]);
            if (tmp_0 < 2.14748365E+9F)
            {
              if (tmp_0 >= -2.14748365E+9F)
              {
                LCWS_subsystem_integrated_B.cvwR_ID = (int32_T)tmp_0;
              }
              else
              {
                LCWS_subsystem_integrated_B.cvwR_ID = MIN_int32_T;
              }
            }
            else
            {
              LCWS_subsystem_integrated_B.cvwR_ID = MAX_int32_T;
            }

            exitg1 = true;
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
        else
        {
          num_R = (uint16_T)(((uint32_T)num_R) + 1U);
        }
      }
      else
      {
        num_R = (uint16_T)(((uint32_T)num_R) + 1U);
      }
    }

    if (((int32_T)BSW) != 1)
    {
      if (((int32_T)LCWS_subsystem_integrated_B.num_R) <
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
      {
        num_L = LCWS_subsystem_integrated_B.num_R;
      }
      else
      {
        num_L = (uint16_T)
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
      }

      num_R = 1U;
      exitg1 = false;
      while ((!exitg1) && (num_R <= num_L))
      {
        y = LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 2)) - 1];
        if (LCWS_subsystem_integrated_B.vec_R[(((int32_T)i) +
             (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 10)) -
            1] < (-KfLCWS_v_LatSpdThr))
        {
          y = LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
            (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 2)) - 1]
            - (LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6))
               - 1] * KfLCWS_r_ObtWidthProportion);
        }

        if (LCWS_subsystem_integrated_B.vec_R[(((int32_T)i) +
             (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 10)) -
            1] > KfLCWS_v_LatSpdThr)
        {
          y += LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
            (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1]
            * KfLCWS_r_ObtWidthProportion;
        }

        obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0]) - 1], y,
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 3)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 5)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1],
                     A, B, unusedU1, C);
        y = 100.0F;
        if (((real_T)LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
              (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 4)) -
             1]) > 0.001)
        {
          B_0[0] = A[0] - (-KfLCWS_d_VehLenth);
          B_0[1] = A[1] - (KfLCWS_d_VehWidth * 0.5F);
          y = norm_TbqwX7rn(B_0) / LCWS_subsystem_integrated_B.vec_R[(((int32_T)
            num_R) + (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] *
                      4)) - 1];
        }

        tmp_0 = (-rtb_curvature) - KfLCWS_d_VehLenth;
        if ((A[0] < tmp_0) && (B[0] < tmp_0))
        {
          tmp_0 = (-BSD_near2) - (KfLCWS_d_VehWidth * 0.5F);
          if ((A[1] < tmp_0) && (C[1] < tmp_0))
          {
            tmp_0 = (-((real32_T)i_0)) - (KfLCWS_d_VehWidth * 0.5F);
            if (((A[1] > tmp_0) || (C[1] > tmp_0)) && (y <
                 KfLCWS_t_TTCLargerThrsh_LowLevel))
            {
              BSW = 2U;
              tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_R[((int32_T)
                num_R) - 1]);
              if (tmp_0 < 2.14748365E+9F)
              {
                if (tmp_0 >= -2.14748365E+9F)
                {
                  LCWS_subsystem_integrated_B.cvwR_ID = (int32_T)tmp_0;
                }
                else
                {
                  LCWS_subsystem_integrated_B.cvwR_ID = MIN_int32_T;
                }
              }
              else
              {
                LCWS_subsystem_integrated_B.cvwR_ID = MAX_int32_T;
              }

              exitg1 = true;
            }
            else
            {
              num_R = (uint16_T)(((uint32_T)num_R) + 1U);
            }
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
        else
        {
          num_R = (uint16_T)(((uint32_T)num_R) + 1U);
        }
      }
    }

    if ((((int32_T)BSW) != 1) && (((int32_T)BSW) != 2))
    {
      if (((int32_T)LCWS_subsystem_integrated_B.num_R) <
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
      {
        i = LCWS_subsystem_integrated_B.num_R;
      }
      else
      {
        i = (uint16_T)LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
      }

      num_L = 1U;
      exitg1 = false;
      while ((!exitg1) && (num_L <= i))
      {
        obt_3pO7kBnK(LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0]) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 2)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 3)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 5)) - 1],
                     LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
          (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1],
                     A, B, unusedU1, C);
        y = 100.0F;
        if (((real_T)LCWS_subsystem_integrated_B.vec_R[(((int32_T)num_L) +
              (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 4)) -
             1]) > 0.001)
        {
          B_0[0] = A[0] - (-KfLCWS_d_VehLenth);
          B_0[1] = A[1] - (KfLCWS_d_VehWidth * 0.5F);
          y = norm_TbqwX7rn(B_0) / LCWS_subsystem_integrated_B.vec_R[(((int32_T)
            num_L) + (LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] *
                      4)) - 1];
        }

        if (((y > 7.5F) && (A[0] < (-30.0F - KfLCWS_d_VehLenth))) && (B[0] <
             (-30.0F - KfLCWS_d_VehLenth)))
        {
          b = true;
        }
        else if ((C[0] > (-KfLCWS_d_VehLenth)) && (unusedU1[0] >
                  (-KfLCWS_d_VehLenth)))
        {
          b = true;
        }
        else if (C[0] > (-30.0F - KfLCWS_d_VehLenth))
        {
          if (unusedU1[0] > (-30.0F - KfLCWS_d_VehLenth))
          {
            if ((B[1] > ((-KfLCWS_d_VehWidth) * 0.5F)) && (unusedU1[1] >
                 ((-KfLCWS_d_VehWidth) * 0.5F)))
            {
              b = true;
            }
            else
            {
              b = ((A[1] < (-6.0F - (KfLCWS_d_VehWidth * 0.5F))) && (C[1] <
                    (-6.0F - (KfLCWS_d_VehWidth * 0.5F))));
            }
          }
          else
          {
            b = false;
          }
        }
        else
        {
          b = false;
        }

        if (!b)
        {
          BSW = 3U;
          tmp_0 = rt_roundf(LCWS_subsystem_integrated_B.vec_R[((int32_T)num_L) -
                            1]);
          if (tmp_0 < 2.14748365E+9F)
          {
            if (tmp_0 >= -2.14748365E+9F)
            {
              LCWS_subsystem_integrated_B.cvwR_ID = (int32_T)tmp_0;
            }
            else
            {
              LCWS_subsystem_integrated_B.cvwR_ID = MIN_int32_T;
            }
          }
          else
          {
            LCWS_subsystem_integrated_B.cvwR_ID = MAX_int32_T;
          }

          exitg1 = true;
        }
        else
        {
          num_L = (uint16_T)(((uint32_T)num_L) + 1U);
        }
      }
    }

    /* Gain: '<S3>/Gain1' */
    ViLCWS_cvwR_ID = mul_s32_loSR(1073741824,
      LCWS_subsystem_integrated_B.cvwR_ID, 30U);

    /* Gain: '<S3>/Gain4' incorporates:
     *  MATLAB Function: '<S3>/CalcRCVWFunction'
     */
    ViLCWS_cvwR = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)BSW)) >> 7);

    /* Chart: '<S3>/DtmnWarningChart' incorporates:
     *  Constant: '<S21>/Constant3'
     *  DataTypeConversion: '<S3>/Data_Type_Conversion3'
     *  MATLAB Function: '<S3>/CalcRCVWFunction'
     */
    if (((uint32_T)LCWS_subsystem_integrated_DW.is_c5_LCWS_subsystem_integrated)
        == LCWS_subsystem_integrat_IN_Safe)
    {
      LCWS_subsystem_integrated_B.warning_right1 = false;
      LCWS_subsystem_integrated_B.warning_right2 = false;
      LCWS_subsystem_integrated_B.right_warning_status = LCWS_NO_WARNING;
    }
    else if (((uint32_T)LCWS_subsystem_integrated_DW.is_UnSafe) ==
             LCWS_subsystem_IN_Warning1level)
    {
      LCWS_subsystem_integrated_B.warning_right1 = true;
      LCWS_subsystem_integrated_B.right_warning_status = LCWS_WARNING_LOW_LEVEL;
    }
    else
    {
      LCWS_subsystem_integrated_B.warning_right2 = true;
      LCWS_subsystem_integrated_B.right_warning_status = LCWS_WARNING_HIGH_LEVEL;
    }

    if (((uint32_T)LCWS_subsystem_integrated_DW.is_c5_LCWS_subsystem_integrated)
        == LCWS_subsystem_integrat_IN_Safe)
    {
      if ((((uint32_T)BSW_nwgt) == WARNING_S_AREA) || (((uint32_T)BSW) ==
           WARNING_S_AREA))
      {
        LCWS_subsystem_integrated_DW.is_c5_LCWS_subsystem_integrated =
          LCWS_subsystem_integr_IN_UnSafe;
        LCWS_subsystem_integrated_DW.is_UnSafe = LCWS_subsystem_IN_Warning1level;
      }
    }
    else if (((((((uint32_T)BSW_nwgt) != WARNING_S_AREA) && (((uint32_T)BSW_nwgt)
      != WARNING_L_AREA)) && (((uint32_T)BSW) != WARNING_S_AREA)) && (((uint32_T)
                BSW) != WARNING_L_AREA)) || ((((uint32_T)BSW) == NO_WARNING_AREA)
              && (((uint32_T)BSW_nwgt) == NO_WARNING_AREA)))
    {
      LCWS_subsystem_integrated_DW.is_UnSafe = LCWS_subsyst_IN_NO_ACTIVE_CHILD;
      LCWS_subsystem_integrated_DW.is_c5_LCWS_subsystem_integrated =
        LCWS_subsystem_integrat_IN_Safe;
    }
    else if (((uint32_T)LCWS_subsystem_integrated_DW.is_UnSafe) ==
             LCWS_subsystem_IN_Warning1level)
    {
      if (false)
      {
        LCWS_subsystem_integrated_DW.is_UnSafe = LCWS_subsystem_IN_Warning2level;
      }
    }
    else
    {
      if (!false)
      {
        LCWS_subsystem_integrated_DW.is_UnSafe = LCWS_subsystem_IN_Warning1level;
      }
    }

    /* RateTransition: '<S3>/Rate Transition' */
    VeLCWS_right_warning_status =
      LCWS_subsystem_integrated_B.right_warning_status;
  }
  else
  {
    if (LCWS_subsystem_integrated_DW.CalcRLCWEnabledSubsystem_MODE)
    {
      LCWS_subsystem_integrated_DW.CalcRLCWEnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/CalcRLCWEnabledSubsystem' */

  /* Switch: '<S6>/Switch8' incorporates:
   *  Constant: '<S6>/Constant8'
   */
  if (rtb_LogicalOperator1)
  {
    VsLCWS_DataBus.bswR_ID = 0;
  }
  else
  {
    VsLCWS_DataBus.bswR_ID = LCWS_subsystem_integrated_B.bswR_ID;
  }

  /* End of Switch: '<S6>/Switch8' */

  /* Switch: '<S6>/Switch9' incorporates:
   *  Constant: '<S6>/Constant9'
   */
  if (rtb_LogicalOperator1)
  {
    VsLCWS_DataBus.cvwR_ID = 0;
  }
  else
  {
    VsLCWS_DataBus.cvwR_ID = LCWS_subsystem_integrated_B.cvwR_ID;
  }

  /* End of Switch: '<S6>/Switch9' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (rtb_LogicalOperator1)
  {
    VsLCWS_DataBus.warning_left_low = false;
  }
  else
  {
    VsLCWS_DataBus.warning_left_low = LCWS_subsystem_integrated_B.warning_left1;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  if (rtb_LogicalOperator1)
  {
    VsLCWS_DataBus.warning_left_high = false;
  }
  else
  {
    VsLCWS_DataBus.warning_left_high = LCWS_subsystem_integrated_B.warning_left2;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  if (rtb_LogicalOperator1)
  {
    VsLCWS_DataBus.warning_right_low = false;
  }
  else
  {
    VsLCWS_DataBus.warning_right_low =
      LCWS_subsystem_integrated_B.warning_right1;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  if (rtb_LogicalOperator1)
  {
    VsLCWS_DataBus.warning_right_high = false;
  }
  else
  {
    VsLCWS_DataBus.warning_right_high =
      LCWS_subsystem_integrated_B.warning_right2;
  }

  /* End of Switch: '<S6>/Switch3' */

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Constant4'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_left_warning_status = LCWS_NO_WARNING;
  }
  else
  {
    rtb_left_warning_status = LCWS_subsystem_integrated_B.left_warning_status;
  }

  /* End of Switch: '<S6>/Switch4' */

  /* Switch: '<S6>/Switch5' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_right_warning_status = LCWS_NO_WARNING;
  }
  else
  {
    rtb_right_warning_status = LCWS_subsystem_integrated_B.right_warning_status;
  }

  /* End of Switch: '<S6>/Switch5' */

  /* BusCreator: '<S6>/Bus_Creator' */
  VsLCWS_DataBus.active_status = active_status;
  VsLCWS_DataBus.left_warning_status = rtb_left_warning_status;
  VsLCWS_DataBus.right_warning_status = rtb_right_warning_status;

  /* RateTransition: '<S6>/Rate Transition1' */
  VeLCWS_right_warning_status_out = rtb_right_warning_status;

  /* RateTransition: '<S6>/Rate Transition' */
  VeLCWS_left_warning_status_out = rtb_left_warning_status;

  /* RateTransition: '<S4>/Rate Transition' */
  VeLCWS_active_status = active_status;

  /* End of Outputs for SubSystem: '<Root>/LCWS_Subsystem' */
}

/* Model initialize function */
void LCWS_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &LCWS_subsystem_integrated_B), 0,
                sizeof(B_LCWS_subsystem_integrated_T));

  {
    LCWS_subsystem_integrated_B.right_warning_status = LCWS_NO_WARNING;
    LCWS_subsystem_integrated_B.left_warning_status = LCWS_NO_WARNING;
  }

  /* exported global signals */
  VsLCWS_DataBus = LCWS_subsystem_integrated_rtZLCWS_DataBus;
  VfLCWS_curvature = 0.0F;
  VfLCWS_speed_in = 0.0F;

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

  ViLCWS_bswR_ID = 0;
  ViLCWS_cvwR_ID = 0;
  ViLCWS_bswL_ID = 0;
  ViLCWS_cvwL_ID = 0;
  VnLCWS_num_L = ((uint16_T)0U);
  VnLCWS_num_R = ((uint16_T)0U);
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

  VfLCWS_gear_in = 0U;

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_type[i] = 0U;
    }
  }

  ViLCWS_bswR = ((uint8_T)0U);
  ViLCWS_cvwR = ((uint8_T)0U);
  ViLCWS_bswL = ((uint8_T)0U);
  ViLCWS_cvwL = ((uint8_T)0U);
  VeLCWS_active_status = LCWS_OFF;
  VeLCWS_right_warning_status_out = LCWS_NO_WARNING;
  VeLCWS_left_warning_status_out = LCWS_NO_WARNING;
  VeLCWS_right_warning_status = LCWS_NO_WARNING;
  VeLCWS_left_warning_status = LCWS_NO_WARNING;
  ViLCWS_bswLL = WARNING_HLEVEL_AREA;

  /* states (dwork) */
  (void) memset((void *)&LCWS_subsystem_integrated_DW, 0,
                sizeof(DW_LCWS_subsystem_integrated_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/LCWS_Subsystem' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/input_Subsystem' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/CvrtObtVecFunctionEnabled' */
  /* SystemInitialize for Outport: '<S22>/vec_L' */
  LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] = 0;

  /* SystemInitialize for Outport: '<S22>/vec_R' */
  LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] = 0;

  /* SystemInitialize for Outport: '<S22>/vec_L' */
  LCWS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1] = 0;

  /* SystemInitialize for Outport: '<S22>/vec_R' */
  LCWS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[1] = 0;

  /* End of SystemInitialize for SubSystem: '<S5>/CvrtObtVecFunctionEnabled' */
  /* End of SystemInitialize for SubSystem: '<S1>/input_Subsystem' */

  /* SystemInitialize for Chart: '<S4>/DtmnChart' */
  LCWS_subsystem_integrated_DW.is_On = LCWS_subsyst_IN_NO_ACTIVE_CHILD;
  LCWS_subsystem_integrated_DW.is_Positive = LCWS_subsyst_IN_NO_ACTIVE_CHILD;

  /* Chart: '<S4>/DtmnChart' */
  LCWS_subsystem_integrated_DW.is_c3_LCWS_subsystem_integrated =
    LCWS_subsystem_integrate_IN_Off;

  /* SystemInitialize for Enabled SubSystem: '<S1>/CalcLLCWEnabledSubsystem' */
  /* SystemInitialize for Chart: '<S2>/DtmnWarningChart' */
  LCWS_subsystem_integrated_DW.is_UnSafe_pitt = LCWS_subsyst_IN_NO_ACTIVE_CHILD;

  /* Chart: '<S2>/DtmnWarningChart' */
  LCWS_subsystem_integrated_DW.is_c4_LCWS_subsystem_integrated =
    LCWS_subsystem_integrat_IN_Safe;

  /* End of SystemInitialize for SubSystem: '<S1>/CalcLLCWEnabledSubsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/CalcRLCWEnabledSubsystem' */
  /* SystemInitialize for Chart: '<S3>/DtmnWarningChart' */
  LCWS_subsystem_integrated_DW.is_UnSafe = LCWS_subsyst_IN_NO_ACTIVE_CHILD;

  /* Chart: '<S3>/DtmnWarningChart' */
  LCWS_subsystem_integrated_DW.is_c5_LCWS_subsystem_integrated =
    LCWS_subsystem_integrat_IN_Safe;

  /* End of SystemInitialize for SubSystem: '<S1>/CalcRLCWEnabledSubsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/LCWS_Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
