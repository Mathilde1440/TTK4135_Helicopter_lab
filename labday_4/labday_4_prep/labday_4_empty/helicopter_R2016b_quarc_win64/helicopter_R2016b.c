/*
 * helicopter_R2016b.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "helicopter_R2016b".
 *
 * Model version              : 11.1
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Feb 24 14:28:43 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "helicopter_R2016b.h"
#include "helicopter_R2016b_private.h"
#include "helicopter_R2016b_dt.h"

/* Block signals (default storage) */
B_helicopter_R2016b_T helicopter_R2016b_B;

/* Continuous states */
X_helicopter_R2016b_T helicopter_R2016b_X;

/* Block states (default storage) */
DW_helicopter_R2016b_T helicopter_R2016b_DW;

/* Real-time model */
static RT_MODEL_helicopter_R2016b_T helicopter_R2016b_M_;
RT_MODEL_helicopter_R2016b_T *const helicopter_R2016b_M = &helicopter_R2016b_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  helicopter_R2016b_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helicopter_R2016b_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T lastTime;
  real_T rtb_Backgain;
  real_T rtb_Clock;
  real_T rtb_Derivative;
  real_T *lastU;
  int8_T rtAction;
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
    /* set solver stop time */
    if (!(helicopter_R2016b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helicopter_R2016b_M->solverInfo,
                            ((helicopter_R2016b_M->Timing.clockTickH0 + 1) *
        helicopter_R2016b_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helicopter_R2016b_M->solverInfo,
                            ((helicopter_R2016b_M->Timing.clockTick0 + 1) *
        helicopter_R2016b_M->Timing.stepSize0 +
        helicopter_R2016b_M->Timing.clockTickH0 *
        helicopter_R2016b_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helicopter_R2016b_M)) {
    helicopter_R2016b_M->Timing.t[0] = rtsiGetT(&helicopter_R2016b_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(helicopter_R2016b_DW.IfActionSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

    /* S-Function Block: helicopter_R2016b/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (helicopter_R2016b_DW.HILReadEncoderTimebase_Task, 1,
         &helicopter_R2016b_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          helicopter_R2016b_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          helicopter_R2016b_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          helicopter_R2016b_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* FromWorkspace: '<S6>/From Workspace2' */
  {
    real_T *pDataValues = (real_T *)
      helicopter_R2016b_DW.FromWorkspace2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helicopter_R2016b_DW.FromWorkspace2_PWORK.TimePtr;
    int_T currTimeIndex = helicopter_R2016b_DW.FromWorkspace2_IWORK.PrevIndex;
    real_T t = helicopter_R2016b_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helicopter_R2016b_DW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          helicopter_R2016b_B.FromWorkspace2 = pDataValues[currTimeIndex];
        } else {
          helicopter_R2016b_B.FromWorkspace2 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        helicopter_R2016b_B.FromWorkspace2 = (real_T) rtInterpolate(d1, d2, f1,
          f2);
        pDataValues += 141;
      }
    }
  }

  /* FromWorkspace: '<S6>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      helicopter_R2016b_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helicopter_R2016b_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = helicopter_R2016b_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helicopter_R2016b_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helicopter_R2016b_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              (&helicopter_R2016b_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 141;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              (&helicopter_R2016b_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 141;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 4; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&helicopter_R2016b_B.FromWorkspace1[0])[elIdx] = (real_T)
              rtInterpolate(d1, d2, f1, f2);
            pDataValues += 141;
          }
        }
      }
    }
  }

  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
    /* Gain: '<S5>/Travel: Count to rad' incorporates:
     *  Gain: '<S5>/Travel_gain'
     */
    helicopter_R2016b_B.TravelCounttorad = helicopter_R2016b_P.travel_gain *
      rtb_HILReadEncoderTimebase_o1 * helicopter_R2016b_P.TravelCounttorad_Gain;

    /* Gain: '<S15>/Gain' */
    helicopter_R2016b_B.Gain = helicopter_R2016b_P.Gain_Gain *
      helicopter_R2016b_B.TravelCounttorad;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant'
     */
    helicopter_R2016b_B.Travel = helicopter_R2016b_P.Constant_Value +
      helicopter_R2016b_B.Gain;

    /* Gain: '<S5>/Pitch: Count to rad' */
    helicopter_R2016b_B.PitchCounttorad =
      helicopter_R2016b_P.PitchCounttorad_Gain * rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S12>/Gain' */
    helicopter_R2016b_B.Gain_i = helicopter_R2016b_P.Gain_Gain_a *
      helicopter_R2016b_B.PitchCounttorad;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  TransferFcn: '<S5>/Travel: Transfer Fcn'
   */
  helicopter_R2016b_B.Gain_d = (helicopter_R2016b_P.TravelTransferFcn_C *
    helicopter_R2016b_X.TravelTransferFcn_CSTATE +
    helicopter_R2016b_P.TravelTransferFcn_D *
    helicopter_R2016b_B.TravelCounttorad) * helicopter_R2016b_P.Gain_Gain_l;

  /* Gain: '<S13>/Gain' incorporates:
   *  TransferFcn: '<S5>/Pitch: Transfer Fcn'
   */
  helicopter_R2016b_B.Gain_b = (helicopter_R2016b_P.PitchTransferFcn_C *
    helicopter_R2016b_X.PitchTransferFcn_CSTATE +
    helicopter_R2016b_P.PitchTransferFcn_D * helicopter_R2016b_B.PitchCounttorad)
    * helicopter_R2016b_P.Gain_Gain_ae;

  /* Gain: '<S3>/Gain1' */
  helicopter_R2016b_B.Gain1[0] = helicopter_R2016b_P.Gain1_Gain *
    helicopter_R2016b_B.Travel;
  helicopter_R2016b_B.Gain1[1] = helicopter_R2016b_P.Gain1_Gain *
    helicopter_R2016b_B.Gain_d;
  helicopter_R2016b_B.Gain1[2] = helicopter_R2016b_P.Gain1_Gain *
    helicopter_R2016b_B.Gain_i;
  helicopter_R2016b_B.Gain1[3] = helicopter_R2016b_P.Gain1_Gain *
    helicopter_R2016b_B.Gain_b;

  /* Sum: '<S6>/Sum4' incorporates:
   *  Constant: '<S6>/Constant'
   *  Product: '<S6>/MatrixMultiply'
   *  Sum: '<S6>/Sum3'
   */
  helicopter_R2016b_B.pitch_ref = helicopter_R2016b_B.FromWorkspace2 -
    ((((helicopter_R2016b_B.Gain1[0] - helicopter_R2016b_B.FromWorkspace1[0]) *
       helicopter_R2016b_P.K[0] + (helicopter_R2016b_B.Gain1[1] -
        helicopter_R2016b_B.FromWorkspace1[1]) * helicopter_R2016b_P.K[1]) +
      (helicopter_R2016b_B.Gain1[2] - helicopter_R2016b_B.FromWorkspace1[2]) *
      helicopter_R2016b_P.K[2]) + (helicopter_R2016b_B.Gain1[3] -
      helicopter_R2016b_B.FromWorkspace1[3]) * helicopter_R2016b_P.K[3]);
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
    /* Gain: '<S5>/Elevation: Count to rad' incorporates:
     *  Gain: '<S5>/Elevation_gain'
     */
    helicopter_R2016b_B.ElevationCounttorad = helicopter_R2016b_P.elevation_gain
      * rtb_HILReadEncoderTimebase_o3 *
      helicopter_R2016b_P.ElevationCounttorad_Gain;

    /* Gain: '<S10>/Gain' */
    helicopter_R2016b_B.Gain_e = helicopter_R2016b_P.Gain_Gain_lv *
      helicopter_R2016b_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    helicopter_R2016b_B.Elevation = helicopter_R2016b_B.Gain_e +
      helicopter_R2016b_P.elavation_offsetdeg_Value;
  }

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S5>/Elevation: Transfer Fcn'
   */
  helicopter_R2016b_B.Gain_dg = (helicopter_R2016b_P.ElevationTransferFcn_C *
    helicopter_R2016b_X.ElevationTransferFcn_CSTATE +
    helicopter_R2016b_P.ElevationTransferFcn_D *
    helicopter_R2016b_B.ElevationCounttorad) * helicopter_R2016b_P.Gain_Gain_n;

  /* Gain: '<S2>/Gain1' */
  helicopter_R2016b_B.Gain1_e[0] = helicopter_R2016b_P.Gain1_Gain_f *
    helicopter_R2016b_B.Travel;
  helicopter_R2016b_B.Gain1_e[1] = helicopter_R2016b_P.Gain1_Gain_f *
    helicopter_R2016b_B.Gain_d;
  helicopter_R2016b_B.Gain1_e[2] = helicopter_R2016b_P.Gain1_Gain_f *
    helicopter_R2016b_B.Gain_i;
  helicopter_R2016b_B.Gain1_e[3] = helicopter_R2016b_P.Gain1_Gain_f *
    helicopter_R2016b_B.Gain_b;
  helicopter_R2016b_B.Gain1_e[4] = helicopter_R2016b_P.Gain1_Gain_f *
    helicopter_R2016b_B.Elevation;
  helicopter_R2016b_B.Gain1_e[5] = helicopter_R2016b_P.Gain1_Gain_f *
    helicopter_R2016b_B.Gain_dg;
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
    /* Constant: '<Root>/elevation_ref' */
    helicopter_R2016b_B.elevation_ref = helicopter_R2016b_P.elevation_ref_Value;
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Vd_bias'
   *  Gain: '<S7>/K_pd'
   *  Gain: '<S7>/K_pp'
   *  Sum: '<S7>/Sum2'
   *  Sum: '<S7>/Sum3'
   */
  rtb_Clock = ((helicopter_R2016b_B.pitch_ref - helicopter_R2016b_B.Gain1_e[2]) *
               helicopter_R2016b_P.K_pp - helicopter_R2016b_P.K_pd *
               helicopter_R2016b_B.Gain1_e[3]) + helicopter_R2016b_P.Vd_ff;

  /* Integrator: '<S4>/Integrator' */
  /* Limited  Integrator  */
  if (helicopter_R2016b_X.Integrator_CSTATE >=
      helicopter_R2016b_P.Integrator_UpperSat) {
    helicopter_R2016b_X.Integrator_CSTATE =
      helicopter_R2016b_P.Integrator_UpperSat;
  } else {
    if (helicopter_R2016b_X.Integrator_CSTATE <=
        helicopter_R2016b_P.Integrator_LowerSat) {
      helicopter_R2016b_X.Integrator_CSTATE =
        helicopter_R2016b_P.Integrator_LowerSat;
    }
  }

  /* Sum: '<S4>/Sum' */
  rtb_Derivative = helicopter_R2016b_B.elevation_ref -
    helicopter_R2016b_B.Gain1_e[4];

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Vs_bias'
   *  Gain: '<S4>/K_ed'
   *  Gain: '<S4>/K_ep'
   *  Integrator: '<S4>/Integrator'
   *  Sum: '<S4>/Sum1'
   */
  rtb_Backgain = ((helicopter_R2016b_P.K_ep * rtb_Derivative +
                   helicopter_R2016b_X.Integrator_CSTATE) -
                  helicopter_R2016b_P.K_ed * helicopter_R2016b_B.Gain1_e[5]) +
    helicopter_R2016b_P.Vs_ff;

  /* If: '<S4>/If' incorporates:
   *  Clock: '<S4>/Clock'
   *  Gain: '<S4>/K_ei'
   *  Inport: '<S9>/In1'
   */
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
    rtAction = (int8_T)!(helicopter_R2016b_M->Timing.t[0] >= 2.0);
    helicopter_R2016b_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = helicopter_R2016b_DW.If_ActiveSubsystem;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    helicopter_R2016b_B.In1 = helicopter_R2016b_P.K_ei * rtb_Derivative;
    if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
      srUpdateBC(helicopter_R2016b_DW.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
  }

  /* End of If: '<S4>/If' */
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
  }

  /* Derivative: '<S5>/Derivative' */
  rtb_Derivative = helicopter_R2016b_M->Timing.t[0];
  if ((helicopter_R2016b_DW.TimeStampA >= rtb_Derivative) &&
      (helicopter_R2016b_DW.TimeStampB >= rtb_Derivative)) {
    rtb_Derivative = 0.0;
  } else {
    lastTime = helicopter_R2016b_DW.TimeStampA;
    lastU = &helicopter_R2016b_DW.LastUAtTimeA;
    if (helicopter_R2016b_DW.TimeStampA < helicopter_R2016b_DW.TimeStampB) {
      if (helicopter_R2016b_DW.TimeStampB < rtb_Derivative) {
        lastTime = helicopter_R2016b_DW.TimeStampB;
        lastU = &helicopter_R2016b_DW.LastUAtTimeB;
      }
    } else {
      if (helicopter_R2016b_DW.TimeStampA >= rtb_Derivative) {
        lastTime = helicopter_R2016b_DW.TimeStampB;
        lastU = &helicopter_R2016b_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (helicopter_R2016b_B.PitchCounttorad - *lastU) /
      (rtb_Derivative - lastTime);
  }

  /* End of Derivative: '<S5>/Derivative' */

  /* Gain: '<S14>/Gain' */
  helicopter_R2016b_B.Gain_l = helicopter_R2016b_P.Gain_Gain_a1 * rtb_Derivative;
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Derivative = (rtb_Backgain - rtb_Clock) *
    helicopter_R2016b_P.Backgain_Gain;

  /* Saturate: '<S5>/Back motor: Saturation' */
  if (rtb_Derivative > helicopter_R2016b_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S5>/Back motor: Saturation' */
    helicopter_R2016b_B.BackmotorSaturation =
      helicopter_R2016b_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Derivative < helicopter_R2016b_P.BackmotorSaturation_LowerSat)
  {
    /* Saturate: '<S5>/Back motor: Saturation' */
    helicopter_R2016b_B.BackmotorSaturation =
      helicopter_R2016b_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Back motor: Saturation' */
    helicopter_R2016b_B.BackmotorSaturation = rtb_Derivative;
  }

  /* End of Saturate: '<S5>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Derivative = (rtb_Clock + rtb_Backgain) *
    helicopter_R2016b_P.Frontgain_Gain;

  /* Saturate: '<S5>/Front motor: Saturation' */
  if (rtb_Derivative > helicopter_R2016b_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S5>/Front motor: Saturation' */
    helicopter_R2016b_B.FrontmotorSaturation =
      helicopter_R2016b_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Derivative < helicopter_R2016b_P.FrontmotorSaturation_LowerSat)
  {
    /* Saturate: '<S5>/Front motor: Saturation' */
    helicopter_R2016b_B.FrontmotorSaturation =
      helicopter_R2016b_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Front motor: Saturation' */
    helicopter_R2016b_B.FrontmotorSaturation = rtb_Derivative;
  }

  /* End of Saturate: '<S5>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: helicopter_R2016b/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helicopter_R2016b_DW.HILWriteAnalog_Buffer[0] =
        helicopter_R2016b_B.FrontmotorSaturation;
      helicopter_R2016b_DW.HILWriteAnalog_Buffer[1] =
        helicopter_R2016b_B.BackmotorSaturation;
      result = hil_write_analog(helicopter_R2016b_DW.HILInitialize_Card,
        helicopter_R2016b_P.HILWriteAnalog_channels, 2,
        &helicopter_R2016b_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void helicopter_R2016b_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S5>/Derivative' */
  if (helicopter_R2016b_DW.TimeStampA == (rtInf)) {
    helicopter_R2016b_DW.TimeStampA = helicopter_R2016b_M->Timing.t[0];
    lastU = &helicopter_R2016b_DW.LastUAtTimeA;
  } else if (helicopter_R2016b_DW.TimeStampB == (rtInf)) {
    helicopter_R2016b_DW.TimeStampB = helicopter_R2016b_M->Timing.t[0];
    lastU = &helicopter_R2016b_DW.LastUAtTimeB;
  } else if (helicopter_R2016b_DW.TimeStampA < helicopter_R2016b_DW.TimeStampB)
  {
    helicopter_R2016b_DW.TimeStampA = helicopter_R2016b_M->Timing.t[0];
    lastU = &helicopter_R2016b_DW.LastUAtTimeA;
  } else {
    helicopter_R2016b_DW.TimeStampB = helicopter_R2016b_M->Timing.t[0];
    lastU = &helicopter_R2016b_DW.LastUAtTimeB;
  }

  *lastU = helicopter_R2016b_B.PitchCounttorad;

  /* End of Update for Derivative: '<S5>/Derivative' */
  if (rtmIsMajorTimeStep(helicopter_R2016b_M)) {
    rt_ertODEUpdateContinuousStates(&helicopter_R2016b_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++helicopter_R2016b_M->Timing.clockTick0)) {
    ++helicopter_R2016b_M->Timing.clockTickH0;
  }

  helicopter_R2016b_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helicopter_R2016b_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++helicopter_R2016b_M->Timing.clockTick1)) {
      ++helicopter_R2016b_M->Timing.clockTickH1;
    }

    helicopter_R2016b_M->Timing.t[1] = helicopter_R2016b_M->Timing.clockTick1 *
      helicopter_R2016b_M->Timing.stepSize1 +
      helicopter_R2016b_M->Timing.clockTickH1 *
      helicopter_R2016b_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void helicopter_R2016b_derivatives(void)
{
  XDot_helicopter_R2016b_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_helicopter_R2016b_T *) helicopter_R2016b_M->derivs);

  /* Derivatives for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += helicopter_R2016b_P.TravelTransferFcn_A *
    helicopter_R2016b_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += helicopter_R2016b_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += helicopter_R2016b_P.PitchTransferFcn_A *
    helicopter_R2016b_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += helicopter_R2016b_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helicopter_R2016b_P.ElevationTransferFcn_A *
    helicopter_R2016b_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helicopter_R2016b_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  lsat = (helicopter_R2016b_X.Integrator_CSTATE <=
          helicopter_R2016b_P.Integrator_LowerSat);
  usat = (helicopter_R2016b_X.Integrator_CSTATE >=
          helicopter_R2016b_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (helicopter_R2016b_B.In1 > 0.0)) || (usat
       && (helicopter_R2016b_B.In1 < 0.0))) {
    _rtXdot->Integrator_CSTATE = helicopter_R2016b_B.In1;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S4>/Integrator' */
}

/* Model initialize function */
void helicopter_R2016b_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helicopter_R2016b/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &helicopter_R2016b_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (helicopter_R2016b_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(helicopter_R2016b_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
      return;
    }

    if ((helicopter_R2016b_P.HILInitialize_AIPStart && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &helicopter_R2016b_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (helicopter_R2016b_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &helicopter_R2016b_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = helicopter_R2016b_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (helicopter_R2016b_DW.HILInitialize_Card,
         helicopter_R2016b_P.HILInitialize_AIChannels, 8U,
         &helicopter_R2016b_DW.HILInitialize_AIMinimums[0],
         &helicopter_R2016b_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_R2016b_P.HILInitialize_AOPStart && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &helicopter_R2016b_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (helicopter_R2016b_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &helicopter_R2016b_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = helicopter_R2016b_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (helicopter_R2016b_DW.HILInitialize_Card,
         helicopter_R2016b_P.HILInitialize_AOChannels, 8U,
         &helicopter_R2016b_DW.HILInitialize_AOMinimums[0],
         &helicopter_R2016b_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_R2016b_P.HILInitialize_AOStart && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helicopter_R2016b_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_R2016b_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(helicopter_R2016b_DW.HILInitialize_Card,
        helicopter_R2016b_P.HILInitialize_AOChannels, 8U,
        &helicopter_R2016b_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }

    if (helicopter_R2016b_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helicopter_R2016b_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_R2016b_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (helicopter_R2016b_DW.HILInitialize_Card,
         helicopter_R2016b_P.HILInitialize_AOChannels, 8U,
         &helicopter_R2016b_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_R2016b_P.HILInitialize_EIPStart && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &helicopter_R2016b_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            helicopter_R2016b_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (helicopter_R2016b_DW.HILInitialize_Card,
         helicopter_R2016b_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &helicopter_R2016b_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_R2016b_P.HILInitialize_EIStart && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &helicopter_R2016b_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = helicopter_R2016b_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(helicopter_R2016b_DW.HILInitialize_Card,
        helicopter_R2016b_P.HILInitialize_EIChannels, 8U,
        &helicopter_R2016b_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_R2016b_P.HILInitialize_POPStart && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helicopter_R2016b_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = helicopter_R2016b_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(helicopter_R2016b_DW.HILInitialize_Card,
        helicopter_R2016b_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &helicopter_R2016b_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          helicopter_R2016b_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &helicopter_R2016b_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            helicopter_R2016b_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            helicopter_R2016b_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = helicopter_R2016b_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            helicopter_R2016b_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            helicopter_R2016b_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              helicopter_R2016b_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(helicopter_R2016b_DW.HILInitialize_Card,
          &helicopter_R2016b_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &helicopter_R2016b_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(helicopter_R2016b_DW.HILInitialize_Card,
          &helicopter_R2016b_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &helicopter_R2016b_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helicopter_R2016b_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            helicopter_R2016b_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &helicopter_R2016b_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = helicopter_R2016b_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &helicopter_R2016b_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = helicopter_R2016b_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(helicopter_R2016b_DW.HILInitialize_Card,
        helicopter_R2016b_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *)
        &helicopter_R2016b_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &helicopter_R2016b_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &helicopter_R2016b_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &helicopter_R2016b_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = helicopter_R2016b_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &helicopter_R2016b_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_R2016b_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(helicopter_R2016b_DW.HILInitialize_Card,
        helicopter_R2016b_P.HILInitialize_POChannels, 8U,
        &helicopter_R2016b_DW.HILInitialize_POSortedFreqs[0],
        &helicopter_R2016b_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }

    if ((helicopter_R2016b_P.HILInitialize_POStart && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_R2016b_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_R2016b_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(helicopter_R2016b_DW.HILInitialize_Card,
        helicopter_R2016b_P.HILInitialize_POChannels, 8U,
        &helicopter_R2016b_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }

    if (helicopter_R2016b_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_R2016b_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_R2016b_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (helicopter_R2016b_DW.HILInitialize_Card,
         helicopter_R2016b_P.HILInitialize_POChannels, 8U,
         &helicopter_R2016b_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

  /* S-Function Block: helicopter_R2016b/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (helicopter_R2016b_DW.HILInitialize_Card,
       helicopter_R2016b_P.HILReadEncoderTimebase_SamplesI,
       helicopter_R2016b_P.HILReadEncoderTimebase_Channels, 3,
       &helicopter_R2016b_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (helicopter_R2016b_DW.HILReadEncoderTimebase_Task,
         (t_buffer_overflow_mode)
         (helicopter_R2016b_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
    }
  }

  /* Start for FromWorkspace: '<S6>/From Workspace2' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.52359877559828194,
      0.52359877559827528, 0.52359877559826173, 0.52359877559821955,
      0.5194166825625931, 0.42622133274240004, 0.34125694134872953,
      0.26423581848618549, 0.19483784674924221, 0.13271580466738242,
      0.077500959700191441, 0.028808607576599976, -0.013756659690428052,
      -0.050596085340420038, -0.082112345851441781, -0.10870564192845217,
      -0.13077028334688218, -0.148691752626683, -0.16284422305864554,
      -0.1735885012883055, -0.18127036198715002, -0.18621924114503807,
      -0.18874725459049196, -0.1891485090991773, -0.18769867463869178,
      -0.18465478776080213, -0.18025525778618795, -0.17472004916137662,
      -0.16825101515408242, -0.16103235985659414, -0.15323120726124689,
      -0.14499825793767146, -0.13646851556319117, -0.1277620672235586,
      -0.1189849030019402, -0.11022976190257661, -0.10157699260657388,
      -0.093095418927063023, -0.084843201117066391, -0.076868685384560265,
      -0.06921123508513527, -0.061902038093902267, -0.054964885806190411,
      -0.048416920083067638, -0.042269345245244672, -0.036528102930385054,
      -0.031194508267471, -0.026265846391176073, -0.021735928822858686,
      -0.017595609686675395, -0.013833262113331135, -0.010435215514099982,
      -0.0073861546879270268, -0.0046694819585619829, -0.0022676437306214936,
      -0.00016242300697022483, 0.001664800471544825, 0.0032328207156824273,
      0.0045604047991716357, 0.0056661191499574048, 0.0065681809670169455,
      0.0072843329151349723, 0.0078317392732124569, 0.0082269017489496887,
      0.0084855932218087515, 0.0086228077349675969, 0.0086527251236163671,
      0.0085886887396888767, 0.0084431948104022325, 0.0082278920483682683,
      0.0079535902132747971, 0.0076302764080640184, 0.0072671379751224618,
      0.0068725909392877149, 0.0064543130235672486, 0.0060192803394369943,
      0.0055738069253999933, 0.0051235863738668952, 0.0046737348455442307,
      0.0042288348196652947, 0.0037929789632421551, 0.0033698135160726839,
      0.0029625805691164686, 0.0025741585436560577, 0.002207100027855069,
      0.0018636658494103342, 0.0015458537863300981, 0.0012554195358299713,
      0.00099388632291430579, 0.0007625376390496541, 0.00056238484266790678,
      0.0003940975955710746, 0.000257880584800696, 0.00015327596775760455,
      7.8871365664534565E-5, 3.1907920467921791E-5, 7.83509050439335E-6,
      1.1102230246251565E-16, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helicopter_R2016b_DW.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues0;
    helicopter_R2016b_DW.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues0;
    helicopter_R2016b_DW.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S6>/From Workspace1' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1378421413623174, 3.1262155534751837,
      3.1033093000740606, 3.0666274152458617, 3.0144838785936323,
      2.9464466510199641, 2.8631591064642139, 2.7660113465754432,
      2.6568349568082263, 2.5376691525632924, 2.4105985173624656,
      2.2776480113577442, 2.1407193971133847, 2.0015559419891522,
      1.8617257063252166, 1.7226167045941958, 1.5854394623975752,
      1.4512340541224666, 1.3208797510438774, 1.1951060898042063,
      1.0745046059336649, 0.95954075225560242, 0.85056569542401206,
      0.74782779343767447, 0.65148362709290075, 0.56160850375770344,
      0.47820638223088485, 0.40121918828411662, 0.33053550535914034,
      0.26599863582349503, 0.20741403651835064, 0.15455613879363175,
      0.10717456831377956, 0.064999783966784519, 0.027748158372780669,
      -0.0048734750474109714, -0.033163781607570414, -0.057423363354333339,
      -0.077951646515307366, -0.095044188880672273, -0.10899037752825601,
      -0.12007148742887197, -0.12855907193746169, -0.13471365682518718,
      -0.138783710321705, -0.14100486267343651, -0.14159934978602226,
      -0.14077565676798123, -0.1387283384543728, -0.13563799532099183,
      -0.13167138456244493, -0.12698164748949536, -0.12170863576545451,
      -0.11597932036619019, -0.1099082684856752, -0.10359817491051854,
      -0.097140435639377978, -0.0906157527513057, -0.084094760662379225,
      -0.07763866502902099, -0.071299886586289662, -0.06512270319352588,
      -0.059143884267967586, -0.053393312645496377, -0.0478945896911848,
      -0.042665620209590784, -0.037719174369530005, -0.033063424463786288,
      -0.028702454872581846, -0.024636744092580761, -0.020863618134467687,
      -0.017377674983968246, -0.014171180164403692, -0.011234433739797165,
      -0.0085561093556595271, -0.0061235661350294819, -0.0039231344313425164,
      -0.0019403765910392299, -0.00016032399896110991, 0.0014323082282886518,
      0.0028529274703852844, 0.00411688928113204, 0.0052393410267104479,
      0.0062350820028284045, 0.0071184385784508935, 0.0079031529747050511,
      0.008602284380273462, 0.0092281212471139913, 0.0097921038172641365,
      0.01030475623948004, 0.010775628088813393, 0.011213245776070496,
      0.011625075322408389, 0.012017499389567336, 0.012395813390555472,
      0.012764247921340177, 0.0131260272075535, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.015002048873869266,
      -0.046506351601756361, -0.091625013574466244, -0.14672753925536508,
      -0.20857414662465459, -0.27214891023551269, -0.33315017824124016,
      -0.38859103958289309, -0.43670555906560166, -0.47666321696700537,
      -0.50828254080036173, -0.53180202401528387, -0.54771445697202914,
      -0.556653820488875, -0.55932094266008092, -0.55643600691334538,
      -0.54870896879050057, -0.53682163310372755, -0.52141721231317606,
      -0.50309464497033929, -0.482405935491803, -0.45985541470540964,
      -0.43590022732633404, -0.41095160795136448, -0.38537666537615223,
      -0.35950049334131134, -0.3336084861091887, -0.30794877578768792,
      -0.28273473169925567, -0.25814747814278777, -0.23433839722158847,
      -0.21143159090050889, -0.18952628191755344, -0.16869913738723691,
      -0.1490065023770239, -0.1304865336833759, -0.11316122623947833,
      -0.097038326990775345, -0.082113132641483164, -0.068370169460284208,
      -0.055784754587934561, -0.0443244396070383, -0.03395033803678444,
      -0.024618339551165363, -0.016280213982899611, -0.0088846094049292966,
      -0.0023779484501559793, 0.0032947720749043948, 0.008189273252193421,
      0.012361372532060639, 0.015866443032642227, 0.018758948291552044,
      0.021092046897026668, 0.022917261597411195, 0.024284207521388278,
      0.02524037430033154, 0.025830957085445215, 0.026098731552179993,
      0.026083968356281774, 0.025824382533750308, 0.025355113770382832,
      0.024708733571660129, 0.023915275702758868, 0.023002286489991051,
      0.021994891817148768, 0.020915877925985434, 0.019785783360317381,
      0.018622999622795646, 0.017443878364856696, 0.016262843120085666,
      0.015092503832407681, 0.013943772601978021, 0.012825979278262949,
      0.011746985698437268, 0.010713297536595997, 0.0097301728824911657,
      0.0088017268147153743, 0.00793103136122559, 0.0071202103682786082,
      0.0063705289089717107, 0.0056824769684961423, 0.0050558472429761822,
      0.0044898069823389435, 0.00398296390447991, 0.0035334263024351656,
      0.0031388575850919745, 0.0027965256222691384, 0.0025033474673745552,
      0.00225593028061527, 0.0020506096888227277, 0.0018834873973554535,
      0.0017504707489992722, 0.0016473181853454753, 0.001569696268646258,
      0.0015132560039592779, 0.00147373812313755, 0.0014471171448535373,
      0.0014297882276798888, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.10602875210650342, 0.22266037941041428, 0.31888147187346916,
      0.38944360635742636, 0.43710819997699046, 0.449322148928611,
      0.43113366395110697, 0.39183483353987192, 0.34005504751169391,
      0.28240546557414581, 0.22347330459415404, 0.16622672474963707,
      0.11246299900118162, 0.063180007353000334, 0.01885020085648037,
      -0.020389623772658405, -0.054611754291797376, -0.08401514843185004,
      -0.10887256277586965, -0.12949690816984488, -0.14621989704986704,
      -0.15937846836291691, -0.16930611539520318, -0.1763273133468628,
      -0.18075392638688226, -0.18288290126090972, -0.18299481835587939,
      -0.18135303251496443, -0.1782032337829802, -0.17377331769541809,
      -0.16827349071857667, -0.16189655842063089, -0.15481835772247,
      -0.14719830318308302, -0.13918002315047884, -0.13089206553515348,
      -0.12244865608508376, -0.11395049420266423, -0.105485573383022,
      -0.097130015013540572, -0.088948905670333589, -0.080997129408902246,
      -0.073320187759328914, -0.06595500120612352, -0.058930686937243126,
      -0.052269308610711718, -0.045986594594856767, -0.040092622092860519,
      -0.034592465021828278, -0.029486804302079672, -0.02477249964156758,
      -0.020443122444181339, -0.016489449872918005, -0.01289992041702015,
      -0.0096610517269355434, -0.0067578216324085671, -0.0041740135530349276,
      -0.0018925276689966131, 0.00010434063538999894, 0.0018346534464414033,
      0.0033166123951068327, 0.0045683683828898758, 0.0056078571746068784,
      0.0064526590602939082, 0.007119880798369671, 0.0076260580793109378,
      0.0079870767829334222, 0.0082181113620651836, 0.008333578720558954,
      0.0083471060453991219, 0.0082715111051215873, 0.0081187936095347135,
      0.00790013630116082, 0.00762591452960093, 0.0073057131386949914,
      0.00694834957599999, 0.0065619022115787073, 0.0061537429266855792,
      0.0057305731065508958, 0.0052984622328849929, 0.0048628883316058635,
      0.0044287795761986937, 0.0040005563788493292, 0.0035821732999641309,
      0.0031771600810056588, 0.0027886610003805545, 0.0024194715675618372,
      0.0020720712276871556, 0.0017486501816710298, 0.0014511275253850098,
      0.0011811565285924086, 0.00094011086813250433, 0.00072904292344710964,
      0.00054860206166407188, 0.00039889823502992083, 0.00027929728877662541,
      0.00018814690738444551, 0.00012247416826771662, 7.78071456107865E-5, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.42411500824101744,
      0.46652650905316512, 0.3848843699389754, 0.28224853794406762,
      0.19065837444552622, 0.04885579580561665, -0.072753939903391546,
      -0.15719532166235495, -0.20711914409734544, -0.23059832778558398,
      -0.2357286439123249, -0.22898631936264607, -0.21505490300961153,
      -0.19713196648074938, -0.17731922598093722, -0.15695929852064483,
      -0.13688852205572938, -0.11761357657087426, -0.099429657358423754,
      -0.082497381545978049, -0.066891955517270008, -0.0526342852670849,
      -0.039710588134750507, -0.028084791810095575, -0.017706452167919658,
      -0.0085158994927147149, -0.00044766838228567178, 0.006567143362260261,
      0.012599194929983581, 0.017719664346490992, 0.021999307916818103,
      0.025507729195867253, 0.028312802795436687, 0.030480218149056316,
      0.032073120140136128, 0.033151830453129215, 0.033773637788230094,
      0.033992647531463589, 0.0338596832788479, 0.033422233469295508,
      0.032724437368893057, 0.031807105042220389, 0.030707766593865597,
      0.029460746213768235, 0.028097257058397829, 0.0266455133082828,
      0.025130856053289071, 0.023575890003709046, 0.022000628275538416,
      0.020422642877119028, 0.018857218644824, 0.017317508783086948,
      0.015814690290154622, 0.014358117822596128, 0.012955474757429719,
      0.011612920376997075, 0.010335232318654342, 0.0091259435344109418,
      0.0079874732184168941, 0.0069212512454617792, 0.0059278357929652145,
      0.0050070239486150409, 0.00415795516590067, 0.0033792075431326612,
      0.0026688869526393165, 0.0020247091219100909, 0.0014440748156477267,
      0.00092413831658853774, 0.00046186943393073689, 5.4109299310551421E-5,
      -0.00030237976095497424, -0.0006108699823193462, -0.0008746292335351961,
      -0.0010968870862556068, -0.0012808055634803822, -0.001429454250386386,
      -0.0015457894578216336, -0.0016326371395186802, -0.0016926792804228378,
      -0.0017284434947112898, -0.0017422956055739417, -0.0017364350211809155,
      -0.00171289278976559, -0.0016735323154109586, -0.0016200528758680264,
      -0.0015539963225417871, -0.0014767577309762489, -0.0013896013593489068,
      -0.0012936841841055884, -0.0011900906252374477, -0.0010798839871190603,
      -0.00096418264185264791, -0.0008442717786558276, -0.000721763447158974,
      -0.000598815306524415, -0.00047840378502121147, -0.00036460152556895629,
      -0.00026269095646634714, -0.00017866809062766837, -0.0001170708853596173,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helicopter_R2016b_DW.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    helicopter_R2016b_DW.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    helicopter_R2016b_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for If: '<S4>/If' */
  helicopter_R2016b_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  helicopter_R2016b_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  helicopter_R2016b_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  helicopter_R2016b_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  helicopter_R2016b_X.Integrator_CSTATE = helicopter_R2016b_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  helicopter_R2016b_DW.TimeStampA = (rtInf);
  helicopter_R2016b_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void helicopter_R2016b_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helicopter_R2016b/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(helicopter_R2016b_DW.HILInitialize_Card);
    hil_monitor_stop_all(helicopter_R2016b_DW.HILInitialize_Card);
    is_switching = false;
    if ((helicopter_R2016b_P.HILInitialize_AOTerminate && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helicopter_R2016b_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helicopter_R2016b_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((helicopter_R2016b_P.HILInitialize_POTerminate && !is_switching) ||
        (helicopter_R2016b_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helicopter_R2016b_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helicopter_R2016b_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(helicopter_R2016b_DW.HILInitialize_Card
                         , helicopter_R2016b_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , helicopter_R2016b_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &helicopter_R2016b_DW.HILInitialize_AOVoltages[0]
                         , &helicopter_R2016b_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (helicopter_R2016b_DW.HILInitialize_Card,
             helicopter_R2016b_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &helicopter_R2016b_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(helicopter_R2016b_DW.HILInitialize_Card,
            helicopter_R2016b_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &helicopter_R2016b_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helicopter_R2016b_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(helicopter_R2016b_DW.HILInitialize_Card);
    hil_monitor_delete_all(helicopter_R2016b_DW.HILInitialize_Card);
    hil_close(helicopter_R2016b_DW.HILInitialize_Card);
    helicopter_R2016b_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  helicopter_R2016b_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  helicopter_R2016b_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  helicopter_R2016b_initialize();
}

void MdlTerminate(void)
{
  helicopter_R2016b_terminate();
}

/* Registration function */
RT_MODEL_helicopter_R2016b_T *helicopter_R2016b(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helicopter_R2016b_P.Integrator_UpperSat = rtInf;
  helicopter_R2016b_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helicopter_R2016b_M, 0,
                sizeof(RT_MODEL_helicopter_R2016b_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helicopter_R2016b_M->solverInfo,
                          &helicopter_R2016b_M->Timing.simTimeStep);
    rtsiSetTPtr(&helicopter_R2016b_M->solverInfo, &rtmGetTPtr
                (helicopter_R2016b_M));
    rtsiSetStepSizePtr(&helicopter_R2016b_M->solverInfo,
                       &helicopter_R2016b_M->Timing.stepSize0);
    rtsiSetdXPtr(&helicopter_R2016b_M->solverInfo, &helicopter_R2016b_M->derivs);
    rtsiSetContStatesPtr(&helicopter_R2016b_M->solverInfo, (real_T **)
                         &helicopter_R2016b_M->contStates);
    rtsiSetNumContStatesPtr(&helicopter_R2016b_M->solverInfo,
      &helicopter_R2016b_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&helicopter_R2016b_M->solverInfo,
      &helicopter_R2016b_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&helicopter_R2016b_M->solverInfo,
      &helicopter_R2016b_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&helicopter_R2016b_M->solverInfo,
      &helicopter_R2016b_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&helicopter_R2016b_M->solverInfo, (&rtmGetErrorStatus
      (helicopter_R2016b_M)));
    rtsiSetRTModelPtr(&helicopter_R2016b_M->solverInfo, helicopter_R2016b_M);
  }

  rtsiSetSimTimeStep(&helicopter_R2016b_M->solverInfo, MAJOR_TIME_STEP);
  helicopter_R2016b_M->intgData.f[0] = helicopter_R2016b_M->odeF[0];
  helicopter_R2016b_M->contStates = ((real_T *) &helicopter_R2016b_X);
  rtsiSetSolverData(&helicopter_R2016b_M->solverInfo, (void *)
                    &helicopter_R2016b_M->intgData);
  rtsiSetSolverName(&helicopter_R2016b_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helicopter_R2016b_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helicopter_R2016b_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helicopter_R2016b_M->Timing.sampleTimes =
      (&helicopter_R2016b_M->Timing.sampleTimesArray[0]);
    helicopter_R2016b_M->Timing.offsetTimes =
      (&helicopter_R2016b_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helicopter_R2016b_M->Timing.sampleTimes[0] = (0.0);
    helicopter_R2016b_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    helicopter_R2016b_M->Timing.offsetTimes[0] = (0.0);
    helicopter_R2016b_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helicopter_R2016b_M, &helicopter_R2016b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helicopter_R2016b_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helicopter_R2016b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helicopter_R2016b_M, -1);
  helicopter_R2016b_M->Timing.stepSize0 = 0.002;
  helicopter_R2016b_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  helicopter_R2016b_M->Sizes.checksums[0] = (2811110454U);
  helicopter_R2016b_M->Sizes.checksums[1] = (3915466196U);
  helicopter_R2016b_M->Sizes.checksums[2] = (3973261655U);
  helicopter_R2016b_M->Sizes.checksums[3] = (3616650940U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    helicopter_R2016b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &helicopter_R2016b_DW.IfActionSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(helicopter_R2016b_M->extModeInfo,
      &helicopter_R2016b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helicopter_R2016b_M->extModeInfo,
                        helicopter_R2016b_M->Sizes.checksums);
    rteiSetTPtr(helicopter_R2016b_M->extModeInfo, rtmGetTPtr(helicopter_R2016b_M));
  }

  helicopter_R2016b_M->solverInfoPtr = (&helicopter_R2016b_M->solverInfo);
  helicopter_R2016b_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&helicopter_R2016b_M->solverInfo, 0.002);
  rtsiSetSolverMode(&helicopter_R2016b_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helicopter_R2016b_M->blockIO = ((void *) &helicopter_R2016b_B);

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      helicopter_R2016b_B.Gain1_e[i] = 0.0;
    }

    helicopter_R2016b_B.FromWorkspace2 = 0.0;
    helicopter_R2016b_B.FromWorkspace1[0] = 0.0;
    helicopter_R2016b_B.FromWorkspace1[1] = 0.0;
    helicopter_R2016b_B.FromWorkspace1[2] = 0.0;
    helicopter_R2016b_B.FromWorkspace1[3] = 0.0;
    helicopter_R2016b_B.TravelCounttorad = 0.0;
    helicopter_R2016b_B.Gain = 0.0;
    helicopter_R2016b_B.Travel = 0.0;
    helicopter_R2016b_B.Gain_d = 0.0;
    helicopter_R2016b_B.PitchCounttorad = 0.0;
    helicopter_R2016b_B.Gain_i = 0.0;
    helicopter_R2016b_B.Gain_b = 0.0;
    helicopter_R2016b_B.Gain1[0] = 0.0;
    helicopter_R2016b_B.Gain1[1] = 0.0;
    helicopter_R2016b_B.Gain1[2] = 0.0;
    helicopter_R2016b_B.Gain1[3] = 0.0;
    helicopter_R2016b_B.pitch_ref = 0.0;
    helicopter_R2016b_B.ElevationCounttorad = 0.0;
    helicopter_R2016b_B.Gain_e = 0.0;
    helicopter_R2016b_B.Elevation = 0.0;
    helicopter_R2016b_B.Gain_dg = 0.0;
    helicopter_R2016b_B.elevation_ref = 0.0;
    helicopter_R2016b_B.Gain_l = 0.0;
    helicopter_R2016b_B.BackmotorSaturation = 0.0;
    helicopter_R2016b_B.FrontmotorSaturation = 0.0;
    helicopter_R2016b_B.In1 = 0.0;
  }

  /* parameters */
  helicopter_R2016b_M->defaultParam = ((real_T *)&helicopter_R2016b_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helicopter_R2016b_X;
    helicopter_R2016b_M->contStates = (x);
    (void) memset((void *)&helicopter_R2016b_X, 0,
                  sizeof(X_helicopter_R2016b_T));
  }

  /* states (dwork) */
  helicopter_R2016b_M->dwork = ((void *) &helicopter_R2016b_DW);
  (void) memset((void *)&helicopter_R2016b_DW, 0,
                sizeof(DW_helicopter_R2016b_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_R2016b_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_R2016b_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_R2016b_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_R2016b_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_R2016b_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_R2016b_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_R2016b_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      helicopter_R2016b_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  helicopter_R2016b_DW.TimeStampA = 0.0;
  helicopter_R2016b_DW.LastUAtTimeA = 0.0;
  helicopter_R2016b_DW.TimeStampB = 0.0;
  helicopter_R2016b_DW.LastUAtTimeB = 0.0;
  helicopter_R2016b_DW.HILWriteAnalog_Buffer[0] = 0.0;
  helicopter_R2016b_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helicopter_R2016b_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  helicopter_R2016b_M->Sizes.numContStates = (4);/* Number of continuous states */
  helicopter_R2016b_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  helicopter_R2016b_M->Sizes.numY = (0);/* Number of model outputs */
  helicopter_R2016b_M->Sizes.numU = (0);/* Number of model inputs */
  helicopter_R2016b_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helicopter_R2016b_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helicopter_R2016b_M->Sizes.numBlocks = (74);/* Number of blocks */
  helicopter_R2016b_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  helicopter_R2016b_M->Sizes.numBlockPrms = (150);/* Sum of parameter "widths" */
  return helicopter_R2016b_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
