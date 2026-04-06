/*
 * heli_day4.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_day4".
 *
 * Model version              : 11.3
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Mar 10 14:18:35 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_day4.h"
#include "heli_day4_private.h"
#include "heli_day4_dt.h"

/* Block signals (default storage) */
B_heli_day4_T heli_day4_B;

/* Continuous states */
X_heli_day4_T heli_day4_X;

/* Block states (default storage) */
DW_heli_day4_T heli_day4_DW;

/* Real-time model */
static RT_MODEL_heli_day4_T heli_day4_M_;
RT_MODEL_heli_day4_T *const heli_day4_M = &heli_day4_M_;

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

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
  heli_day4_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void heli_day4_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_TmpSignalConversionAtToFile[8];
  real_T tmp[6];
  real_T lastTime;
  real_T rtb_Backgain;
  real_T rtb_Clock;
  real_T rtb_Derivative;
  real_T *lastU;
  int32_T i;
  int32_T i_0;
  int8_T rtAction;
  if (rtmIsMajorTimeStep(heli_day4_M)) {
    /* set solver stop time */
    if (!(heli_day4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_day4_M->solverInfo,
                            ((heli_day4_M->Timing.clockTickH0 + 1) *
        heli_day4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_day4_M->solverInfo,
                            ((heli_day4_M->Timing.clockTick0 + 1) *
        heli_day4_M->Timing.stepSize0 + heli_day4_M->Timing.clockTickH0 *
        heli_day4_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_day4_M)) {
    heli_day4_M->Timing.t[0] = rtsiGetT(&heli_day4_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_day4_DW.IfActionSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(heli_day4_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_day4/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_day4_DW.HILReadEncoderTimebase_Task, 1,
        &heli_day4_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_day4_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_day4_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          heli_day4_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* FromWorkspace: '<S6>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) heli_day4_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) heli_day4_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = heli_day4_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = heli_day4_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
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

    heli_day4_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&heli_day4_B.FromWorkspace[0])[elIdx] = pDataValues[currTimeIndex];
              pDataValues += 81;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&heli_day4_B.FromWorkspace[0])[elIdx] = pDataValues[currTimeIndex
                + 1];
              pDataValues += 81;
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
          for (elIdx = 0; elIdx < 2; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&heli_day4_B.FromWorkspace[0])[elIdx] = (real_T) rtInterpolate(d1,
              d2, f1, f2);
            pDataValues += 81;
          }
        }
      }
    }
  }

  /* FromWorkspace: '<S6>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *) heli_day4_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) heli_day4_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = heli_day4_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = heli_day4_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
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

    heli_day4_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 6; ++elIdx) {
              (&heli_day4_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 81;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 6; ++elIdx) {
              (&heli_day4_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 81;
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
          for (elIdx = 0; elIdx < 6; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&heli_day4_B.FromWorkspace1[0])[elIdx] = (real_T) rtInterpolate(d1,
              d2, f1, f2);
            pDataValues += 81;
          }
        }
      }
    }
  }

  if (rtmIsMajorTimeStep(heli_day4_M)) {
    /* Gain: '<S5>/Travel: Count to rad' incorporates:
     *  Gain: '<S5>/Travel_gain'
     */
    heli_day4_B.TravelCounttorad = heli_day4_P.travel_gain *
      rtb_HILReadEncoderTimebase_o1 * heli_day4_P.TravelCounttorad_Gain;

    /* Gain: '<S15>/Gain' */
    heli_day4_B.Gain = heli_day4_P.Gain_Gain * heli_day4_B.TravelCounttorad;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant'
     */
    heli_day4_B.Travel = heli_day4_P.Constant_Value + heli_day4_B.Gain;

    /* Gain: '<S5>/Pitch: Count to rad' */
    heli_day4_B.PitchCounttorad = heli_day4_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S12>/Gain' */
    heli_day4_B.Gain_i = heli_day4_P.Gain_Gain_a * heli_day4_B.PitchCounttorad;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  TransferFcn: '<S5>/Travel: Transfer Fcn'
   */
  heli_day4_B.Gain_d = (heli_day4_P.TravelTransferFcn_C *
                        heli_day4_X.TravelTransferFcn_CSTATE +
                        heli_day4_P.TravelTransferFcn_D *
                        heli_day4_B.TravelCounttorad) * heli_day4_P.Gain_Gain_l;

  /* Gain: '<S13>/Gain' incorporates:
   *  TransferFcn: '<S5>/Pitch: Transfer Fcn'
   */
  heli_day4_B.Gain_b = (heli_day4_P.PitchTransferFcn_C *
                        heli_day4_X.PitchTransferFcn_CSTATE +
                        heli_day4_P.PitchTransferFcn_D *
                        heli_day4_B.PitchCounttorad) * heli_day4_P.Gain_Gain_ae;
  if (rtmIsMajorTimeStep(heli_day4_M)) {
    /* Gain: '<S5>/Elevation: Count to rad' incorporates:
     *  Gain: '<S5>/Elevation_gain'
     */
    heli_day4_B.ElevationCounttorad = heli_day4_P.elevation_gain *
      rtb_HILReadEncoderTimebase_o3 * heli_day4_P.ElevationCounttorad_Gain;

    /* Gain: '<S10>/Gain' */
    heli_day4_B.Gain_e = heli_day4_P.Gain_Gain_lv *
      heli_day4_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    heli_day4_B.Elevation = heli_day4_B.Gain_e +
      heli_day4_P.elavation_offsetdeg_Value;
  }

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S5>/Elevation: Transfer Fcn'
   */
  heli_day4_B.Gain_dg = (heli_day4_P.ElevationTransferFcn_C *
    heli_day4_X.ElevationTransferFcn_CSTATE + heli_day4_P.ElevationTransferFcn_D
    * heli_day4_B.ElevationCounttorad) * heli_day4_P.Gain_Gain_n;

  /* Gain: '<S3>/Gain1' */
  heli_day4_B.Gain1[0] = heli_day4_P.Gain1_Gain * heli_day4_B.Travel;
  heli_day4_B.Gain1[1] = heli_day4_P.Gain1_Gain * heli_day4_B.Gain_d;
  heli_day4_B.Gain1[2] = heli_day4_P.Gain1_Gain * heli_day4_B.Gain_i;
  heli_day4_B.Gain1[3] = heli_day4_P.Gain1_Gain * heli_day4_B.Gain_b;
  heli_day4_B.Gain1[4] = heli_day4_P.Gain1_Gain * heli_day4_B.Elevation;
  heli_day4_B.Gain1[5] = heli_day4_P.Gain1_Gain * heli_day4_B.Gain_dg;

  /* Sum: '<S6>/Sum3' */
  for (i = 0; i < 6; i++) {
    tmp[i] = heli_day4_B.Gain1[i] - heli_day4_B.FromWorkspace1[i];
  }

  /* End of Sum: '<S6>/Sum3' */
  for (i = 0; i < 2; i++) {
    /* Sum: '<S6>/Sum4' incorporates:
     *  Gain: '<S6>/Gain1'
     */
    rtb_Clock = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Clock += heli_day4_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    heli_day4_B.pitch_ref[i] = heli_day4_B.FromWorkspace[i] - rtb_Clock;

    /* End of Sum: '<S6>/Sum4' */
  }

  /* Gain: '<S2>/Gain1' */
  heli_day4_B.Gain1_e[0] = heli_day4_P.Gain1_Gain_f * heli_day4_B.Travel;
  heli_day4_B.Gain1_e[1] = heli_day4_P.Gain1_Gain_f * heli_day4_B.Gain_d;
  heli_day4_B.Gain1_e[2] = heli_day4_P.Gain1_Gain_f * heli_day4_B.Gain_i;
  heli_day4_B.Gain1_e[3] = heli_day4_P.Gain1_Gain_f * heli_day4_B.Gain_b;
  heli_day4_B.Gain1_e[4] = heli_day4_P.Gain1_Gain_f * heli_day4_B.Elevation;
  heli_day4_B.Gain1_e[5] = heli_day4_P.Gain1_Gain_f * heli_day4_B.Gain_dg;
  if (rtmIsMajorTimeStep(heli_day4_M)) {
    /* SignalConversion generated from: '<Root>/To File1' */
    rtb_TmpSignalConversionAtToFile[0] = heli_day4_B.pitch_ref[0];
    rtb_TmpSignalConversionAtToFile[1] = heli_day4_B.pitch_ref[1];
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtToFile[i + 2] = heli_day4_B.Gain1_e[i];
    }

    /* End of SignalConversion generated from: '<Root>/To File1' */

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++heli_day4_DW.ToFile1_IWORK.Decimation % 1) &&
          (heli_day4_DW.ToFile1_IWORK.Count * (8 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) heli_day4_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[8 + 1];
          heli_day4_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = heli_day4_M->Timing.t[1];
          u[1] = rtb_TmpSignalConversionAtToFile[0];
          u[2] = rtb_TmpSignalConversionAtToFile[1];
          u[3] = rtb_TmpSignalConversionAtToFile[2];
          u[4] = rtb_TmpSignalConversionAtToFile[3];
          u[5] = rtb_TmpSignalConversionAtToFile[4];
          u[6] = rtb_TmpSignalConversionAtToFile[5];
          u[7] = rtb_TmpSignalConversionAtToFile[6];
          u[8] = rtb_TmpSignalConversionAtToFile[7];
          if (fwrite(u, sizeof(real_T), 8 + 1, fp) != 8 + 1) {
            rtmSetErrorStatus(heli_day4_M,
                              "Error writing to MAT-file q_111111_r_0k10k1.mat");
            return;
          }

          if (((++heli_day4_DW.ToFile1_IWORK.Count) * (8 + 1))+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file q_111111_r_0k10k1.mat.\n");
          }
        }
      }
    }
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Vd_bias'
   *  Gain: '<S7>/K_pd'
   *  Gain: '<S7>/K_pp'
   *  Sum: '<S7>/Sum2'
   *  Sum: '<S7>/Sum3'
   */
  rtb_Clock = ((heli_day4_B.pitch_ref[0] - heli_day4_B.Gain1_e[2]) *
               heli_day4_P.K_pp - heli_day4_P.K_pd * heli_day4_B.Gain1_e[3]) +
    heli_day4_P.Vd_ff;

  /* Integrator: '<S4>/Integrator' */
  /* Limited  Integrator  */
  if (heli_day4_X.Integrator_CSTATE >= heli_day4_P.Integrator_UpperSat) {
    heli_day4_X.Integrator_CSTATE = heli_day4_P.Integrator_UpperSat;
  } else {
    if (heli_day4_X.Integrator_CSTATE <= heli_day4_P.Integrator_LowerSat) {
      heli_day4_X.Integrator_CSTATE = heli_day4_P.Integrator_LowerSat;
    }
  }

  /* Sum: '<S4>/Sum' */
  rtb_Derivative = heli_day4_B.pitch_ref[1] - heli_day4_B.Gain1_e[4];

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Vs_bias'
   *  Gain: '<S4>/K_ed'
   *  Gain: '<S4>/K_ep'
   *  Integrator: '<S4>/Integrator'
   *  Sum: '<S4>/Sum1'
   */
  rtb_Backgain = ((heli_day4_P.K_ep * rtb_Derivative +
                   heli_day4_X.Integrator_CSTATE) - heli_day4_P.K_ed *
                  heli_day4_B.Gain1_e[5]) + heli_day4_P.Vs_ff;

  /* If: '<S4>/If' incorporates:
   *  Clock: '<S4>/Clock'
   *  Gain: '<S4>/K_ei'
   *  Inport: '<S9>/In1'
   */
  if (rtmIsMajorTimeStep(heli_day4_M)) {
    rtAction = (int8_T)!(heli_day4_M->Timing.t[0] >= 2.0);
    heli_day4_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = heli_day4_DW.If_ActiveSubsystem;
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    heli_day4_B.In1 = heli_day4_P.K_ei * rtb_Derivative;
    if (rtmIsMajorTimeStep(heli_day4_M)) {
      srUpdateBC(heli_day4_DW.IfActionSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
  }

  /* End of If: '<S4>/If' */
  if (rtmIsMajorTimeStep(heli_day4_M)) {
  }

  /* Derivative: '<S5>/Derivative' */
  rtb_Derivative = heli_day4_M->Timing.t[0];
  if ((heli_day4_DW.TimeStampA >= rtb_Derivative) && (heli_day4_DW.TimeStampB >=
       rtb_Derivative)) {
    rtb_Derivative = 0.0;
  } else {
    lastTime = heli_day4_DW.TimeStampA;
    lastU = &heli_day4_DW.LastUAtTimeA;
    if (heli_day4_DW.TimeStampA < heli_day4_DW.TimeStampB) {
      if (heli_day4_DW.TimeStampB < rtb_Derivative) {
        lastTime = heli_day4_DW.TimeStampB;
        lastU = &heli_day4_DW.LastUAtTimeB;
      }
    } else {
      if (heli_day4_DW.TimeStampA >= rtb_Derivative) {
        lastTime = heli_day4_DW.TimeStampB;
        lastU = &heli_day4_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (heli_day4_B.PitchCounttorad - *lastU) / (rtb_Derivative -
      lastTime);
  }

  /* End of Derivative: '<S5>/Derivative' */

  /* Gain: '<S14>/Gain' */
  heli_day4_B.Gain_l = heli_day4_P.Gain_Gain_a1 * rtb_Derivative;
  if (rtmIsMajorTimeStep(heli_day4_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Derivative = (rtb_Backgain - rtb_Clock) * heli_day4_P.Backgain_Gain;

  /* Saturate: '<S5>/Back motor: Saturation' */
  if (rtb_Derivative > heli_day4_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S5>/Back motor: Saturation' */
    heli_day4_B.BackmotorSaturation = heli_day4_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Derivative < heli_day4_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S5>/Back motor: Saturation' */
    heli_day4_B.BackmotorSaturation = heli_day4_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Back motor: Saturation' */
    heli_day4_B.BackmotorSaturation = rtb_Derivative;
  }

  /* End of Saturate: '<S5>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_day4_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Derivative = (rtb_Clock + rtb_Backgain) * heli_day4_P.Frontgain_Gain;

  /* Saturate: '<S5>/Front motor: Saturation' */
  if (rtb_Derivative > heli_day4_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S5>/Front motor: Saturation' */
    heli_day4_B.FrontmotorSaturation = heli_day4_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Derivative < heli_day4_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S5>/Front motor: Saturation' */
    heli_day4_B.FrontmotorSaturation = heli_day4_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Front motor: Saturation' */
    heli_day4_B.FrontmotorSaturation = rtb_Derivative;
  }

  /* End of Saturate: '<S5>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_day4_M)) {
    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: heli_day4/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_day4_DW.HILWriteAnalog_Buffer[0] = heli_day4_B.FrontmotorSaturation;
      heli_day4_DW.HILWriteAnalog_Buffer[1] = heli_day4_B.BackmotorSaturation;
      result = hil_write_analog(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILWriteAnalog_channels, 2,
        &heli_day4_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void heli_day4_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S5>/Derivative' */
  if (heli_day4_DW.TimeStampA == (rtInf)) {
    heli_day4_DW.TimeStampA = heli_day4_M->Timing.t[0];
    lastU = &heli_day4_DW.LastUAtTimeA;
  } else if (heli_day4_DW.TimeStampB == (rtInf)) {
    heli_day4_DW.TimeStampB = heli_day4_M->Timing.t[0];
    lastU = &heli_day4_DW.LastUAtTimeB;
  } else if (heli_day4_DW.TimeStampA < heli_day4_DW.TimeStampB) {
    heli_day4_DW.TimeStampA = heli_day4_M->Timing.t[0];
    lastU = &heli_day4_DW.LastUAtTimeA;
  } else {
    heli_day4_DW.TimeStampB = heli_day4_M->Timing.t[0];
    lastU = &heli_day4_DW.LastUAtTimeB;
  }

  *lastU = heli_day4_B.PitchCounttorad;

  /* End of Update for Derivative: '<S5>/Derivative' */
  if (rtmIsMajorTimeStep(heli_day4_M)) {
    rt_ertODEUpdateContinuousStates(&heli_day4_M->solverInfo);
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
  if (!(++heli_day4_M->Timing.clockTick0)) {
    ++heli_day4_M->Timing.clockTickH0;
  }

  heli_day4_M->Timing.t[0] = rtsiGetSolverStopTime(&heli_day4_M->solverInfo);

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
    if (!(++heli_day4_M->Timing.clockTick1)) {
      ++heli_day4_M->Timing.clockTickH1;
    }

    heli_day4_M->Timing.t[1] = heli_day4_M->Timing.clockTick1 *
      heli_day4_M->Timing.stepSize1 + heli_day4_M->Timing.clockTickH1 *
      heli_day4_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void heli_day4_derivatives(void)
{
  XDot_heli_day4_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_heli_day4_T *) heli_day4_M->derivs);

  /* Derivatives for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_day4_P.TravelTransferFcn_A *
    heli_day4_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_day4_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_day4_P.PitchTransferFcn_A *
    heli_day4_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_day4_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_day4_P.ElevationTransferFcn_A *
    heli_day4_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_day4_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  lsat = (heli_day4_X.Integrator_CSTATE <= heli_day4_P.Integrator_LowerSat);
  usat = (heli_day4_X.Integrator_CSTATE >= heli_day4_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (heli_day4_B.In1 > 0.0)) || (usat &&
       (heli_day4_B.In1 < 0.0))) {
    _rtXdot->Integrator_CSTATE = heli_day4_B.In1;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S4>/Integrator' */
}

/* Model initialize function */
void heli_day4_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_day4/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_day4_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_day4_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_day4_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_day4_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_day4_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_day4_M, _rt_error_message);
      return;
    }

    if ((heli_day4_P.HILInitialize_AIPStart && !is_switching) ||
        (heli_day4_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_day4_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (heli_day4_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_day4_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_day4_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_AIChannels, 8U,
        &heli_day4_DW.HILInitialize_AIMinimums[0],
        &heli_day4_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_day4_P.HILInitialize_AOPStart && !is_switching) ||
        (heli_day4_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_day4_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (heli_day4_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_day4_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_day4_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_AOChannels, 8U,
        &heli_day4_DW.HILInitialize_AOMinimums[0],
        &heli_day4_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_day4_P.HILInitialize_AOStart && !is_switching) ||
        (heli_day4_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_day4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_day4_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_AOChannels, 8U,
        &heli_day4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }

    if (heli_day4_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_day4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_day4_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_day4_DW.HILInitialize_Card, heli_day4_P.HILInitialize_AOChannels,
         8U, &heli_day4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_day4_P.HILInitialize_EIPStart && !is_switching) ||
        (heli_day4_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_day4_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_day4_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &heli_day4_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_day4_P.HILInitialize_EIStart && !is_switching) ||
        (heli_day4_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_day4_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_day4_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_EIChannels, 8U,
        &heli_day4_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_day4_P.HILInitialize_POPStart && !is_switching) ||
        (heli_day4_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_day4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_day4_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &heli_day4_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          heli_day4_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &heli_day4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            heli_day4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            heli_day4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_day4_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            heli_day4_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            heli_day4_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              heli_day4_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_day4_DW.HILInitialize_Card,
          &heli_day4_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_day4_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_day4_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_day4_DW.HILInitialize_Card,
          &heli_day4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_day4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_day4_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_day4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_day4_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &heli_day4_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_day4_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &heli_day4_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_day4_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &heli_day4_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_day4_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_day4_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_day4_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_day4_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_day4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_day4_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_POChannels, 8U,
        &heli_day4_DW.HILInitialize_POSortedFreqs[0],
        &heli_day4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_day4_P.HILInitialize_POStart && !is_switching) ||
        (heli_day4_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_day4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_day4_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(heli_day4_DW.HILInitialize_Card,
        heli_day4_P.HILInitialize_POChannels, 8U,
        &heli_day4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }

    if (heli_day4_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_day4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_day4_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_day4_DW.HILInitialize_Card, heli_day4_P.HILInitialize_POChannels,
         8U, &heli_day4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_day4/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_day4_DW.HILInitialize_Card,
      heli_day4_P.HILReadEncoderTimebase_SamplesI,
      heli_day4_P.HILReadEncoderTimebase_Channels, 3,
      &heli_day4_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (heli_day4_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (heli_day4_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_day4_M, _rt_error_message);
    }
  }

  /* Start for FromWorkspace: '<S6>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.52359877559829882,
      0.52359877559829882, 0.52359877559829882, 0.52359877559829882,
      0.52359877559829882, 0.52359877559829882, 0.52359877559829882,
      0.52359877559829882, 0.52359877559829882, 0.52359877559829882,
      0.52359877559829882, 0.37449566656725713, 0.10868936877298052,
      -0.10914569059026226, -0.27426436926260611, -0.39346349519276891,
      -0.47334858806917096, -0.52020676181099423, -0.52359877559829882,
      -0.52359877559829882, -0.51885771947031678, -0.487256810447684,
      -0.44678828762699013, -0.40066013406669382, -0.35157543677715308,
      -0.3017633123246341, -0.25302816593464744, -0.20679513769828478,
      -0.16415584669953134, -0.12591470754467626, -0.0926262305412986,
      -0.064625712121801862, -0.042046128961472674, -0.0248240059907154,
      -0.01267976670013579, -0.0050905755221296832, -0.0012403355837780977,
      -3.3389810453666768E-7, -3.0750824432236493E-7, -5.3534621936789514E-7,
      -5.3534621936789514E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.10546339174220898, 0.12241347149288674, 0.14124571743660863,
      0.16184485373878349, 0.18391457546126175, 0.20690386539389813,
      0.22989298156335236, 0.25144638982726714, 0.26940518921032769,
      0.28063143674134217, 0.28063070688815023, 0.26309179869257554,
      0.21924286164705595, 0.13702783805220514, 1.3241075919773827E-6,
      9.8490695415055366E-7, 1.6540789117718713E-6, 1.3412148156505815E-6,
      4.7110420557495393E-7, 1.186431527389083E-7, 9.2592359915357359E-7,
      -3.06212726807641E-7, -6.74257319119623E-8, -3.4226374498804956E-7,
      3.2586137003651472E-8, -1.1246782357159279E-6, -6.9749471803477472E-7,
      -3.5378998068411783E-7, -1.2304205860190267E-6, -1.0462385553145027E-6,
      -6.6727019995961638E-7, -7.8125751364400272E-7, -5.6010496342043428E-7,
      -4.4522527235665659E-7, -3.445016881323322E-7, -1.1041670992284127E-6,
      7.015140801494162E-7, 4.2970896848263055E-7, -2.4506730188090904E-7, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    heli_day4_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    heli_day4_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    heli_day4_DW.FromWorkspace_IWORK.PrevIndex = 0;
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
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1378421413625261, 3.1262155534579983,
      3.1033093000299643, 3.0666274151911783, 3.0144539223941584,
      2.9456562771175667, 2.8595077632935446, 2.7555515879651526,
      2.633505110490284, 2.4931956060320961, 2.334518576064299,
      2.1584793396934794, 1.9681193161535564, 1.7680402993676596,
      1.5635669702914412, 1.3600182527794151, 1.1622064600660897,
      0.97415180503283061, 0.798845093923304, 0.63836009920893055,
      0.49403929176815253, 0.36650571764057904, 0.25574875599432872,
      0.16123783879654022, 0.082040962744862278, 0.016936619243879791,
      -0.03548600761438233, -0.07674047388153038, -0.10837034254237785,
      -0.13188960156989568, -0.1487351536518032, -0.16023017671637377,
      -0.16755723986315441, -0.1717402689964975, -0.17363484404616189,
      -0.17392672635123724, -0.1731390195349132, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.015002048909068423,
      -0.046506351618112111, -0.091625013712135384, -0.14672753935514368,
      -0.20869397118807922, -0.27519058110636668, -0.34459405529608833,
      -0.41582470131356863, -0.48818590989947452, -0.56123801783275173,
      -0.63470811987118847, -0.70415694548328023, -0.76144009415969083,
      -0.80031606714358727, -0.81789331630487361, -0.81419487004810487,
      -0.79124717085330121, -0.75221862013303709, -0.70122684443810623,
      -0.64193997885749376, -0.577283229763112, -0.51013429651029385,
      -0.44302784658500111, -0.37804366879115403, -0.31678750420671176,
      -0.26041737400392995, -0.20969050743304851, -0.16501786506859223,
      -0.12651947464338986, -0.094077036110071219, -0.0673822083276302,
      -0.045980092258282208, -0.029308252587122594, -0.016732116533372293,
      -0.007578300198657544, -0.0011675292203014791, 0.0031508272652961654,
      0.0059617707452835388, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.10602875205865551, 0.22266037932317656, 0.31888147181640641,
      0.38944360631144165, 0.43795507377677839, 0.46997264230390062,
      0.4905172487754707, 0.5034310014147434, 0.5114213858602934,
      0.51630439857701838, 0.51925862127063693, 0.4908377753080222,
      0.40485541708098527, 0.27476052941387896, 0.12422928391259105,
      -0.026139205620383923, -0.16218557364998823, -0.27583889058154726,
      -0.36039039566923603, -0.41901692289389714, -0.4569692086860821,
      -0.47458301449494239, -0.47428275856136232, -0.45928334968128393,
      -0.43293517613197374, -0.3984025512123211, -0.35851811915539727,
      -0.31572917471311257, -0.27209192009657118, -0.22929076503330872,
      -0.18866884739203976, -0.15126198241333272, -0.11783019543327218,
      -0.088883326509686125, -0.0646956777988674, -0.04530888085280535,
      -0.03052049435964356, -0.019866674952000462, -0.012620955173827808, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.42411500823462206,
      0.46652650905808424, 0.38488436997291947, 0.28224853798014093,
      0.19404586986134689, 0.12807027410848898, 0.082178425886280423,
      0.051655010557090611, 0.031961537782199852, 0.019532050866899846,
      0.011816890774474412, -0.1136833838504592, -0.34392943290814765,
      -0.52037955066842523, -0.60212498200515152, -0.6014739581319,
      -0.54418547211841728, -0.45461326772623611, -0.3382060203507552,
      -0.23450610889864434, -0.15180914316873981, -0.070455223235441386,
      0.0012010237343203702, 0.059997635520313355, 0.10539269419724076,
      0.13813049967861049, 0.15953772822769538, 0.17115577776913896,
      0.1745490184661653, 0.17120462025304997, 0.16248767056507582,
      0.14962745991482815, 0.13372714792024215, 0.11578747569434426,
      0.0967505948432749, 0.0775471877842482, 0.059153545972647159,
      0.042615277630572379, 0.028982879112690624, 0.018989860991951747, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.42411500823462206,
      0.46652650905808424, 0.38488436997291947, 0.28224853798014093,
      0.19404586986134689, 0.12807027410848898, 0.082178425886280423,
      0.051655010557090611, 0.031961537782199852, 0.019532050866899846,
      0.011816890774474412, -0.1136833838504592, -0.34392943290814765,
      -0.52037955066842523, -0.60212498200515152, -0.6014739581319,
      -0.54418547211841728, -0.45461326772623611, -0.3382060203507552,
      -0.23450610889864434, -0.15180914316873981, -0.070455223235441386,
      0.0012010237343203702, 0.059997635520313355, 0.10539269419724076,
      0.13813049967861049, 0.15953772822769538, 0.17115577776913896,
      0.1745490184661653, 0.17120462025304997, 0.16248767056507582,
      0.14962745991482815, 0.13372714792024215, 0.11578747569434426,
      0.0967505948432749, 0.0775471877842482, 0.059153545972647159,
      0.042615277630572379, 0.028982879112690624, 0.018989860991951747, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.42411500823462206,
      0.46652650905808424, 0.38488436997291947, 0.28224853798014093,
      0.19404586986134689, 0.12807027410848898, 0.082178425886280423,
      0.051655010557090611, 0.031961537782199852, 0.019532050866899846,
      0.011816890774474412, -0.1136833838504592, -0.34392943290814765,
      -0.52037955066842523, -0.60212498200515152, -0.6014739581319,
      -0.54418547211841728, -0.45461326772623611, -0.3382060203507552,
      -0.23450610889864434, -0.15180914316873981, -0.070455223235441386,
      0.0012010237343203702, 0.059997635520313355, 0.10539269419724076,
      0.13813049967861049, 0.15953772822769538, 0.17115577776913896,
      0.1745490184661653, 0.17120462025304997, 0.16248767056507582,
      0.14962745991482815, 0.13372714792024215, 0.11578747569434426,
      0.0967505948432749, 0.0775471877842482, 0.059153545972647159,
      0.042615277630572379, 0.028982879112690624, 0.018989860991951747, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0 } ;

    heli_day4_DW.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    heli_day4_DW.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    heli_day4_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "q_111111_r_0k10k1.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_day4_M,
                        "Error creating .mat file q_111111_r_0k10k1.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 8 + 1, 0, "all_variables")) {
      rtmSetErrorStatus(heli_day4_M,
                        "Error writing mat file header to file q_111111_r_0k10k1.mat");
      return;
    }

    heli_day4_DW.ToFile1_IWORK.Count = 0;
    heli_day4_DW.ToFile1_IWORK.Decimation = -1;
    heli_day4_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for If: '<S4>/If' */
  heli_day4_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  heli_day4_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  heli_day4_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  heli_day4_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  heli_day4_X.Integrator_CSTATE = heli_day4_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  heli_day4_DW.TimeStampA = (rtInf);
  heli_day4_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void heli_day4_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_day4/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_day4_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_day4_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_day4_P.HILInitialize_AOTerminate && !is_switching) ||
        (heli_day4_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_day4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_day4_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((heli_day4_P.HILInitialize_POTerminate && !is_switching) ||
        (heli_day4_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_day4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_day4_P.HILInitialize_POFinal;
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
      result = hil_write(heli_day4_DW.HILInitialize_Card
                         , heli_day4_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , heli_day4_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_day4_DW.HILInitialize_AOVoltages[0]
                         , &heli_day4_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_day4_DW.HILInitialize_Card,
            heli_day4_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &heli_day4_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_day4_DW.HILInitialize_Card,
            heli_day4_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &heli_day4_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_day4_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_day4_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_day4_DW.HILInitialize_Card);
    hil_close(heli_day4_DW.HILInitialize_Card);
    heli_day4_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) heli_day4_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "q_111111_r_0k10k1.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_day4_M,
                          "Error closing MAT-file q_111111_r_0k10k1.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_day4_M,
                          "Error reopening MAT-file q_111111_r_0k10k1.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 8 + 1, heli_day4_DW.ToFile1_IWORK.Count,
           "all_variables")) {
        rtmSetErrorStatus(heli_day4_M,
                          "Error writing header for all_variables to MAT-file q_111111_r_0k10k1.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_day4_M,
                          "Error closing MAT-file q_111111_r_0k10k1.mat");
        return;
      }

      heli_day4_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
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
  heli_day4_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  heli_day4_update();
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
  heli_day4_initialize();
}

void MdlTerminate(void)
{
  heli_day4_terminate();
}

/* Registration function */
RT_MODEL_heli_day4_T *heli_day4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_day4_P.Integrator_UpperSat = rtInf;
  heli_day4_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)heli_day4_M, 0,
                sizeof(RT_MODEL_heli_day4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_day4_M->solverInfo,
                          &heli_day4_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_day4_M->solverInfo, &rtmGetTPtr(heli_day4_M));
    rtsiSetStepSizePtr(&heli_day4_M->solverInfo, &heli_day4_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_day4_M->solverInfo, &heli_day4_M->derivs);
    rtsiSetContStatesPtr(&heli_day4_M->solverInfo, (real_T **)
                         &heli_day4_M->contStates);
    rtsiSetNumContStatesPtr(&heli_day4_M->solverInfo,
      &heli_day4_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_day4_M->solverInfo,
      &heli_day4_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_day4_M->solverInfo,
      &heli_day4_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_day4_M->solverInfo,
      &heli_day4_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_day4_M->solverInfo, (&rtmGetErrorStatus
      (heli_day4_M)));
    rtsiSetRTModelPtr(&heli_day4_M->solverInfo, heli_day4_M);
  }

  rtsiSetSimTimeStep(&heli_day4_M->solverInfo, MAJOR_TIME_STEP);
  heli_day4_M->intgData.f[0] = heli_day4_M->odeF[0];
  heli_day4_M->contStates = ((real_T *) &heli_day4_X);
  rtsiSetSolverData(&heli_day4_M->solverInfo, (void *)&heli_day4_M->intgData);
  rtsiSetSolverName(&heli_day4_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_day4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    heli_day4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_day4_M->Timing.sampleTimes = (&heli_day4_M->Timing.sampleTimesArray[0]);
    heli_day4_M->Timing.offsetTimes = (&heli_day4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_day4_M->Timing.sampleTimes[0] = (0.0);
    heli_day4_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    heli_day4_M->Timing.offsetTimes[0] = (0.0);
    heli_day4_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(heli_day4_M, &heli_day4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_day4_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    heli_day4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_day4_M, -1);
  heli_day4_M->Timing.stepSize0 = 0.002;
  heli_day4_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  heli_day4_M->Sizes.checksums[0] = (2631206941U);
  heli_day4_M->Sizes.checksums[1] = (2742735317U);
  heli_day4_M->Sizes.checksums[2] = (3409695485U);
  heli_day4_M->Sizes.checksums[3] = (98325416U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    heli_day4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&heli_day4_DW.IfActionSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(heli_day4_M->extModeInfo,
      &heli_day4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_day4_M->extModeInfo, heli_day4_M->Sizes.checksums);
    rteiSetTPtr(heli_day4_M->extModeInfo, rtmGetTPtr(heli_day4_M));
  }

  heli_day4_M->solverInfoPtr = (&heli_day4_M->solverInfo);
  heli_day4_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_day4_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_day4_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  heli_day4_M->blockIO = ((void *) &heli_day4_B);

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_day4_B.FromWorkspace1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_day4_B.Gain1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_day4_B.Gain1_e[i] = 0.0;
    }

    heli_day4_B.FromWorkspace[0] = 0.0;
    heli_day4_B.FromWorkspace[1] = 0.0;
    heli_day4_B.TravelCounttorad = 0.0;
    heli_day4_B.Gain = 0.0;
    heli_day4_B.Travel = 0.0;
    heli_day4_B.Gain_d = 0.0;
    heli_day4_B.PitchCounttorad = 0.0;
    heli_day4_B.Gain_i = 0.0;
    heli_day4_B.Gain_b = 0.0;
    heli_day4_B.ElevationCounttorad = 0.0;
    heli_day4_B.Gain_e = 0.0;
    heli_day4_B.Elevation = 0.0;
    heli_day4_B.Gain_dg = 0.0;
    heli_day4_B.pitch_ref[0] = 0.0;
    heli_day4_B.pitch_ref[1] = 0.0;
    heli_day4_B.Gain_l = 0.0;
    heli_day4_B.BackmotorSaturation = 0.0;
    heli_day4_B.FrontmotorSaturation = 0.0;
    heli_day4_B.In1 = 0.0;
  }

  /* parameters */
  heli_day4_M->defaultParam = ((real_T *)&heli_day4_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_day4_X;
    heli_day4_M->contStates = (x);
    (void) memset((void *)&heli_day4_X, 0,
                  sizeof(X_heli_day4_T));
  }

  /* states (dwork) */
  heli_day4_M->dwork = ((void *) &heli_day4_DW);
  (void) memset((void *)&heli_day4_DW, 0,
                sizeof(DW_heli_day4_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_day4_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_day4_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_day4_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_day4_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_day4_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_day4_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_day4_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_day4_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_day4_DW.TimeStampA = 0.0;
  heli_day4_DW.LastUAtTimeA = 0.0;
  heli_day4_DW.TimeStampB = 0.0;
  heli_day4_DW.LastUAtTimeB = 0.0;
  heli_day4_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_day4_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_day4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_day4_M->Sizes.numContStates = (4);/* Number of continuous states */
  heli_day4_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  heli_day4_M->Sizes.numY = (0);       /* Number of model outputs */
  heli_day4_M->Sizes.numU = (0);       /* Number of model inputs */
  heli_day4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_day4_M->Sizes.numSampTimes = (2);/* Number of sample times */
  heli_day4_M->Sizes.numBlocks = (74); /* Number of blocks */
  heli_day4_M->Sizes.numBlockIO = (20);/* Number of block outputs */
  heli_day4_M->Sizes.numBlockPrms = (157);/* Sum of parameter "widths" */
  return heli_day4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
