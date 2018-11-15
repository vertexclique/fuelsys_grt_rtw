/*
 * fuelsys.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "fuelsys".
 *
 * Model version              : 1.743
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Nov 15 01:39:51 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Specified
 * Code generation objective: Execution efficiency
 * Validation result: Passed (1), Warnings (3), Error (0)
 */

#include "fuelsys.h"
#include "fuelsys_private.h"

/* Named constants for Chart: '<S6>/control_logic' */
#define fuelsys_IN_A                   ((uint8_T)1U)
#define fuelsys_IN_Four                ((uint8_T)1U)
#define fuelsys_IN_Fuel_Disabled       ((uint8_T)1U)
#define fuelsys_IN_Low_Emissions       ((uint8_T)1U)
#define fuelsys_IN_Multi               ((uint8_T)1U)
#define fuelsys_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define fuelsys_IN_None                ((uint8_T)2U)
#define fuelsys_IN_Normal              ((uint8_T)1U)
#define fuelsys_IN_O2_failure          ((uint8_T)1U)
#define fuelsys_IN_O2_normal           ((uint8_T)2U)
#define fuelsys_IN_O2_warmup           ((uint8_T)3U)
#define fuelsys_IN_One                 ((uint8_T)3U)
#define fuelsys_IN_Overspeed           ((uint8_T)1U)
#define fuelsys_IN_Rich_Mixture        ((uint8_T)2U)
#define fuelsys_IN_Running             ((uint8_T)2U)
#define fuelsys_IN_Shutdown            ((uint8_T)2U)
#define fuelsys_IN_Single_Failure      ((uint8_T)1U)
#define fuelsys_IN_Three               ((uint8_T)2U)
#define fuelsys_IN_Two                 ((uint8_T)3U)
#define fuelsys_IN_Warmup              ((uint8_T)2U)
#define fuelsys_IN_fail                ((uint8_T)1U)
#define fuelsys_IN_normal              ((uint8_T)2U)
#define fuelsys_entry_to_Multi         (23)
#define fuelsys_event_DEC              (0)
#define fuelsys_event_INC              (1)
#define fuelsys_exit_from_Multi        (24)

/* Block signals (default storage) */
B_fuelsys_T fuelsys_B;

/* Continuous states */
X_fuelsys_T fuelsys_X;

/* Block states (default storage) */
DW_fuelsys_T fuelsys_DW;

/* Real-time model */
RT_MODEL_fuelsys_T fuelsys_M_;
RT_MODEL_fuelsys_T *const fuelsys_M = &fuelsys_M_;

/* Forward declaration for local functions */
static void fuelsys_Fueling_Mode(void);
static void fuelsys_Fail(void);
static void rate_scheduler(void);
real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[], uint32_T
                   maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real32_T look2_iflf_linlca(real32_T u0, real32_T u1, const real32_T bp0[], const
  real32_T bp1[], const real32_T table[], const uint32_T maxIndex[], uint32_T
  stride)
{
  real32_T y;
  real32_T frac;
  uint32_T bpIndices[2];
  real32_T fractions[2];
  real32_T yR_1d;
  uint32_T offset_1d;
  uint32_T bpIdx;

  /* Column-major Lookup 2-D
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[0U] >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    bpIdx = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[1U] >> 1U; u1 < bp1[bpIdx]; bpIdx--) {
    }

    while (u1 >= bp1[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (u1 - bp1[bpIdx]) / (bp1[bpIdx + 1U] - bp1[bpIdx]);
  } else {
    bpIdx = maxIndex[1U];
    frac = 0.0F;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  offset_1d = bpIdx * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[offset_1d];
  } else {
    y = (table[offset_1d + 1U] - table[offset_1d]) * fractions[0U] +
      table[offset_1d];
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yR_1d = table[bpIdx];
    } else {
      yR_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
    }

    y += (yR_1d - y) * frac;
  }

  return y;
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (fuelsys_M->Timing.TaskCounters.TID[2])++;
  if ((fuelsys_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    fuelsys_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  fuelsys_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  fuelsys_step();
  fuelsys_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  fuelsys_step();
  fuelsys_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (rtIsNaN(u0) || rtIsInf(u0) || (rtIsNaN(u1) || rtIsInf(u1))) {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = fabs(u0 / u1);
      if (fabs(u1_0 - floor(u1_0 + 0.5)) <= DBL_EPSILON * u1_0) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for Chart: '<S6>/control_logic' */
static void fuelsys_Fueling_Mode(void)
{
  /* During 'Fueling_Mode': '<S18>:21' */
  switch (fuelsys_DW.is_Fueling_Mode) {
   case fuelsys_IN_Fuel_Disabled:
    fuelsys_B.fuel_mode = DISABLED;

    /* During 'Fuel_Disabled': '<S18>:22' */
    switch (fuelsys_DW.is_Fuel_Disabled) {
     case fuelsys_IN_Overspeed:
      /* During 'Overspeed': '<S18>:24' */
      if ((fuelsys_DW.is_Speed == fuelsys_IN_normal) &&
          (fuelsys_B.RateTransition.speed < 603.0F)) {
        /* Transition: '<S18>:54' */
        if (fuelsys_DW.is_Fail != fuelsys_IN_Multi) {
          /* Transition: '<S18>:55' */
          fuelsys_DW.is_Fuel_Disabled = fuelsys_IN_NO_ACTIVE_CHILD;
          fuelsys_DW.is_Fueling_Mode = fuelsys_IN_Running;

          /* Entry Internal 'Running': '<S18>:23' */
          switch (fuelsys_DW.was_Running) {
           case fuelsys_IN_Low_Emissions:
            fuelsys_DW.is_Running = fuelsys_IN_Low_Emissions;
            fuelsys_DW.was_Running = fuelsys_IN_Low_Emissions;

            /* Entry 'Low_Emissions': '<S18>:25' */
            fuelsys_B.fuel_mode = LOW;

            /* Entry Internal 'Low_Emissions': '<S18>:25' */
            switch (fuelsys_DW.was_Low_Emissions) {
             case fuelsys_IN_Normal:
              fuelsys_DW.is_Low_Emissions = fuelsys_IN_Normal;
              fuelsys_DW.was_Low_Emissions = fuelsys_IN_Normal;
              break;

             case fuelsys_IN_Warmup:
              fuelsys_DW.is_Low_Emissions = fuelsys_IN_Warmup;
              fuelsys_DW.was_Low_Emissions = fuelsys_IN_Warmup;
              break;

             default:
              fuelsys_DW.is_Low_Emissions = fuelsys_IN_NO_ACTIVE_CHILD;
              break;
            }
            break;

           case fuelsys_IN_Rich_Mixture:
            fuelsys_DW.is_Running = fuelsys_IN_Rich_Mixture;
            fuelsys_DW.was_Running = fuelsys_IN_Rich_Mixture;

            /* Entry 'Rich_Mixture': '<S18>:26' */
            fuelsys_B.fuel_mode = RICH;

            /* Entry Internal 'Rich_Mixture': '<S18>:26' */
            fuelsys_DW.is_Rich_Mixture = fuelsys_IN_Single_Failure;
            break;

           default:
            fuelsys_DW.is_Running = fuelsys_IN_NO_ACTIVE_CHILD;
            break;
          }
        } else {
          if (fuelsys_DW.is_Fail == fuelsys_IN_Multi) {
            /* Transition: '<S18>:60' */
            fuelsys_DW.is_Fuel_Disabled = fuelsys_IN_Shutdown;
          }
        }
      }
      break;

     case fuelsys_IN_Shutdown:
      /* During 'Shutdown': '<S18>:29' */
      if (fuelsys_DW.sfEvent == fuelsys_exit_from_Multi) {
        /* Transition: '<S18>:63' */
        fuelsys_DW.is_Fuel_Disabled = fuelsys_IN_NO_ACTIVE_CHILD;
        fuelsys_DW.is_Fueling_Mode = fuelsys_IN_Running;
        fuelsys_DW.is_Running = fuelsys_IN_Rich_Mixture;
        fuelsys_DW.was_Running = fuelsys_IN_Rich_Mixture;

        /* Entry 'Rich_Mixture': '<S18>:26' */
        fuelsys_B.fuel_mode = RICH;

        /* Entry Internal 'Rich_Mixture': '<S18>:26' */
        fuelsys_DW.is_Rich_Mixture = fuelsys_IN_Single_Failure;
      }
      break;

     default:
      /* Unreachable state, for coverage only */
      fuelsys_DW.is_Fuel_Disabled = fuelsys_IN_NO_ACTIVE_CHILD;
      break;
    }
    break;

   case fuelsys_IN_Running:
    /* During 'Running': '<S18>:23' */
    if (fuelsys_DW.sfEvent == fuelsys_entry_to_Multi) {
      /* Transition: '<S18>:61' */
      /* Exit Internal 'Running': '<S18>:23' */
      /* Exit Internal 'Low_Emissions': '<S18>:25' */
      fuelsys_DW.is_Low_Emissions = fuelsys_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'Rich_Mixture': '<S18>:26' */
      fuelsys_DW.is_Rich_Mixture = fuelsys_IN_NO_ACTIVE_CHILD;
      fuelsys_DW.is_Running = fuelsys_IN_NO_ACTIVE_CHILD;
      fuelsys_DW.is_Fueling_Mode = fuelsys_IN_Fuel_Disabled;

      /* Entry 'Fuel_Disabled': '<S18>:22' */
      fuelsys_B.fuel_mode = DISABLED;
      fuelsys_DW.is_Fuel_Disabled = fuelsys_IN_Shutdown;
    } else if (fuelsys_B.RateTransition.speed > 628.0F) {
      /* Transition: '<S18>:53' */
      /* Exit Internal 'Running': '<S18>:23' */
      /* Exit Internal 'Low_Emissions': '<S18>:25' */
      fuelsys_DW.is_Low_Emissions = fuelsys_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'Rich_Mixture': '<S18>:26' */
      fuelsys_DW.is_Rich_Mixture = fuelsys_IN_NO_ACTIVE_CHILD;
      fuelsys_DW.is_Running = fuelsys_IN_NO_ACTIVE_CHILD;
      fuelsys_DW.is_Fueling_Mode = fuelsys_IN_Fuel_Disabled;

      /* Entry 'Fuel_Disabled': '<S18>:22' */
      fuelsys_B.fuel_mode = DISABLED;
      fuelsys_DW.is_Fuel_Disabled = fuelsys_IN_Overspeed;
    } else {
      switch (fuelsys_DW.is_Running) {
       case fuelsys_IN_Low_Emissions:
        fuelsys_B.fuel_mode = LOW;

        /* During 'Low_Emissions': '<S18>:25' */
        switch (fuelsys_DW.is_Low_Emissions) {
         case fuelsys_IN_Normal:
          /* During 'Normal': '<S18>:28' */
          if (fuelsys_DW.is_Fail == fuelsys_IN_One) {
            /* Transition: '<S18>:56' */
            fuelsys_DW.is_Low_Emissions = fuelsys_IN_NO_ACTIVE_CHILD;
            fuelsys_DW.is_Running = fuelsys_IN_Rich_Mixture;
            fuelsys_DW.was_Running = fuelsys_IN_Rich_Mixture;

            /* Entry 'Rich_Mixture': '<S18>:26' */
            fuelsys_B.fuel_mode = RICH;
            fuelsys_DW.is_Rich_Mixture = fuelsys_IN_Single_Failure;
          }
          break;

         case fuelsys_IN_Warmup:
          /* During 'Warmup': '<S18>:30' */
          if (fuelsys_DW.is_A == fuelsys_IN_O2_normal) {
            /* Transition: '<S18>:62' */
            if (fuelsys_DW.is_Fail == fuelsys_IN_One) {
              /* Transition: '<S18>:59' */
              fuelsys_DW.is_Low_Emissions = fuelsys_IN_NO_ACTIVE_CHILD;
              fuelsys_DW.is_Running = fuelsys_IN_Rich_Mixture;
              fuelsys_DW.was_Running = fuelsys_IN_Rich_Mixture;

              /* Entry 'Rich_Mixture': '<S18>:26' */
              fuelsys_B.fuel_mode = RICH;
              fuelsys_DW.is_Rich_Mixture = fuelsys_IN_Single_Failure;
            } else {
              /* Transition: '<S18>:58' */
              fuelsys_DW.is_Low_Emissions = fuelsys_IN_Normal;
              fuelsys_DW.was_Low_Emissions = fuelsys_IN_Normal;
            }
          }
          break;

         default:
          /* Unreachable state, for coverage only */
          fuelsys_DW.is_Low_Emissions = fuelsys_IN_NO_ACTIVE_CHILD;
          break;
        }
        break;

       case fuelsys_IN_Rich_Mixture:
        fuelsys_B.fuel_mode = RICH;

        /* During 'Rich_Mixture': '<S18>:26' */
        if ((fuelsys_DW.is_Rich_Mixture == fuelsys_IN_Single_Failure) &&
            (fuelsys_DW.is_Fail == fuelsys_IN_None)) {
          /* During 'Single_Failure': '<S18>:27' */
          /* Transition: '<S18>:57' */
          fuelsys_DW.is_Rich_Mixture = fuelsys_IN_NO_ACTIVE_CHILD;
          fuelsys_DW.is_Running = fuelsys_IN_Low_Emissions;
          fuelsys_DW.was_Running = fuelsys_IN_Low_Emissions;

          /* Entry 'Low_Emissions': '<S18>:25' */
          fuelsys_B.fuel_mode = LOW;
          fuelsys_DW.is_Low_Emissions = fuelsys_IN_Normal;
          fuelsys_DW.was_Low_Emissions = fuelsys_IN_Normal;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        fuelsys_DW.is_Running = fuelsys_IN_NO_ACTIVE_CHILD;
        break;
      }
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    fuelsys_DW.is_Fueling_Mode = fuelsys_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<S6>/control_logic' */
static void fuelsys_Fail(void)
{
  int32_T b_previousEvent;

  /* During 'Fail': '<S18>:14' */
  switch (fuelsys_DW.is_Fail) {
   case fuelsys_IN_Multi:
    /* During 'Multi': '<S18>:15' */
    switch (fuelsys_DW.is_Multi) {
     case fuelsys_IN_Four:
      /* During 'Four': '<S18>:17' */
      if (fuelsys_DW.sfEvent == fuelsys_event_DEC) {
        /* Transition: '<S18>:49' */
        fuelsys_DW.is_Multi = fuelsys_IN_Three;
      }
      break;

     case fuelsys_IN_Three:
      /* During 'Three': '<S18>:16' */
      if (fuelsys_DW.sfEvent == fuelsys_event_INC) {
        /* Transition: '<S18>:45' */
        fuelsys_DW.is_Multi = fuelsys_IN_Four;
      } else {
        if (fuelsys_DW.sfEvent == fuelsys_event_DEC) {
          /* Transition: '<S18>:50' */
          fuelsys_DW.is_Multi = fuelsys_IN_Two;
        }
      }
      break;

     case fuelsys_IN_Two:
      /* During 'Two': '<S18>:18' */
      if (fuelsys_DW.sfEvent == fuelsys_event_DEC) {
        /* Transition: '<S18>:51' */
        fuelsys_DW.is_Multi = fuelsys_IN_NO_ACTIVE_CHILD;
        fuelsys_DW.is_Fail = fuelsys_IN_NO_ACTIVE_CHILD;
        b_previousEvent = fuelsys_DW.sfEvent;
        fuelsys_DW.sfEvent = fuelsys_exit_from_Multi;
        if (fuelsys_DW.is_active_Fueling_Mode != 0U) {
          fuelsys_Fueling_Mode();
        }

        fuelsys_DW.sfEvent = b_previousEvent;
        fuelsys_DW.is_Fail = fuelsys_IN_One;
      } else {
        if (fuelsys_DW.sfEvent == fuelsys_event_INC) {
          /* Transition: '<S18>:47' */
          fuelsys_DW.is_Multi = fuelsys_IN_Three;
        }
      }
      break;

     default:
      /* Unreachable state, for coverage only */
      fuelsys_DW.is_Multi = fuelsys_IN_NO_ACTIVE_CHILD;
      break;
    }
    break;

   case fuelsys_IN_None:
    /* During 'None': '<S18>:20' */
    if (fuelsys_DW.sfEvent == fuelsys_event_INC) {
      /* Transition: '<S18>:46' */
      fuelsys_DW.is_Fail = fuelsys_IN_One;
    }
    break;

   case fuelsys_IN_One:
    /* During 'One': '<S18>:19' */
    if (fuelsys_DW.sfEvent == fuelsys_event_INC) {
      /* Transition: '<S18>:48' */
      fuelsys_DW.is_Fail = fuelsys_IN_Multi;
      b_previousEvent = fuelsys_DW.sfEvent;
      fuelsys_DW.sfEvent = fuelsys_entry_to_Multi;
      if (fuelsys_DW.is_active_Fueling_Mode != 0U) {
        fuelsys_Fueling_Mode();
      }

      fuelsys_DW.sfEvent = b_previousEvent;
      fuelsys_DW.is_Multi = fuelsys_IN_Two;
    } else {
      if (fuelsys_DW.sfEvent == fuelsys_event_DEC) {
        /* Transition: '<S18>:52' */
        fuelsys_DW.is_Fail = fuelsys_IN_None;
      }
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    fuelsys_DW.is_Fail = fuelsys_IN_NO_ACTIVE_CHILD;
    break;
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void fuelsys_step(void)
{
  int32_T b_previousEvent;
  real32_T denAccum;
  real32_T rtb_throttle;
  real32_T rtb_ego;
  real_T rtb_y_j;
  real32_T rtb_MultiportSwitch;
  real_T rtb_pratio;
  real_T rtb_LimittoPositive;
  real_T tmp;
  if (rtmIsMajorTimeStep(fuelsys_M)) {
    /* set solver stop time */
    if (!(fuelsys_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&fuelsys_M->solverInfo,
                            ((fuelsys_M->Timing.clockTickH0 + 1) *
        fuelsys_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&fuelsys_M->solverInfo,
                            ((fuelsys_M->Timing.clockTick0 + 1) *
        fuelsys_M->Timing.stepSize0 + fuelsys_M->Timing.clockTickH0 *
        fuelsys_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(fuelsys_M)) {
    fuelsys_M->Timing.t[0] = rtsiGetT(&fuelsys_M->solverInfo);
  }

  /* Lookup_n-D: '<S3>/Look-Up Table1' incorporates:
   *  Clock: '<S3>/Clock'
   *  Constant: '<S3>/Constant'
   *  Math: '<S3>/Math Function'
   *  S-Function (sfun_tstart): '<S3>/startTime'
   *  Sum: '<S3>/Sum'
   */
  fuelsys_B.LookUpTable1 = look1_binlx(rt_remd_snf(fuelsys_M->Timing.t[0] - (0.0),
    4.0), fuelsys_ConstP.LookUpTable1_bp01Data,
    fuelsys_ConstP.LookUpTable1_tableData, 2U);

  /* StateSpace: '<S10>/State Space' */
  fuelsys_B.StateSpace = 0.0;
  fuelsys_B.StateSpace += 3.0 * fuelsys_X.StateSpace_CSTATE;

  /* MATLAB Function: '<S7>/EGO Sensor' */
  /* MATLAB Function 'Engine Gas Dynamics/Mixing & Combustion/EGO Sensor': '<S9>:1' */
  /* '<S9>:1:4' */
  fuelsys_B.y = (1.0 - tanh((fuelsys_B.StateSpace - 14.6) * 4.0)) / 2.0;
  if (rtmIsMajorTimeStep(fuelsys_M) &&
      fuelsys_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S4>/DTC1' */
    rtb_throttle = (real32_T)fuelsys_B.LookUpTable1;
  }

  /* Integrator: '<S11>/p0 = 0.589 bar' */
  fuelsys_B.p00589bar = fuelsys_X.p00589bar_CSTATE;
  if (rtmIsMajorTimeStep(fuelsys_M) &&
      fuelsys_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S4>/DTC3' */
    rtb_ego = (real32_T)fuelsys_B.y;

    /* RateTransition: '<S4>/Rate Transition' incorporates:
     *  BusCreator: '<S4>/Bus Creator'
     *  DataTypeConversion: '<S4>/DTC4'
     */
    if (rtmIsMajorTimeStep(fuelsys_M) &&
        fuelsys_M->Timing.TaskCounters.TID[2] == 0) {
      fuelsys_B.RateTransition.throttle = rtb_throttle;
      fuelsys_B.RateTransition.speed = 300.0F;
      fuelsys_B.RateTransition.ego = rtb_ego;
      fuelsys_B.RateTransition.map = (real32_T)fuelsys_B.p00589bar;
    }

    /* End of RateTransition: '<S4>/Rate Transition' */
  }

  if (rtmIsMajorTimeStep(fuelsys_M) &&
      fuelsys_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/fuel_rate_control' */
    /* Chart: '<S6>/control_logic' incorporates:
     *  Lookup_n-D: '<S22>/Pressure Estimation'
     *  Lookup_n-D: '<S24>/Throttle Estimation'
     */
    /* Gateway: fuel_rate_control/control_logic */
    fuelsys_DW.sfEvent = -1;
    if (fuelsys_DW.temporalCounter_i1 < 511U) {
      fuelsys_DW.temporalCounter_i1++;
    }

    /* During: fuel_rate_control/control_logic */
    if (fuelsys_DW.is_active_c1_fuelsys == 0U) {
      /* Entry: fuel_rate_control/control_logic */
      fuelsys_DW.is_active_c1_fuelsys = 1U;

      /* Entry Internal: fuel_rate_control/control_logic */
      fuelsys_DW.is_active_O2 = 1U;

      /* Entry Internal 'O2': '<S18>:1' */
      /* Transition: '<S18>:180' */
      fuelsys_DW.is_O2 = fuelsys_IN_A;

      /* Entry Internal 'A': '<S18>:171' */
      /* Transition: '<S18>:35' */
      fuelsys_DW.is_A = fuelsys_IN_O2_warmup;
      fuelsys_DW.temporalCounter_i1 = 0U;
      fuelsys_DW.is_active_Pressure = 1U;

      /* Entry 'Pressure': '<S18>:2' */
      /* Entry Internal 'Pressure': '<S18>:2' */
      /* Transition: '<S18>:34' */
      fuelsys_DW.is_Pressure = fuelsys_IN_normal;
      fuelsys_DW.is_active_Throttle = 1U;

      /* Entry 'Throttle': '<S18>:8' */
      /* Entry Internal 'Throttle': '<S18>:8' */
      /* Transition: '<S18>:39' */
      fuelsys_DW.is_Throttle = fuelsys_IN_normal;
      fuelsys_DW.is_active_Speed = 1U;

      /* Entry 'Speed': '<S18>:9' */
      /* Entry Internal 'Speed': '<S18>:9' */
      /* Transition: '<S18>:41' */
      fuelsys_DW.is_Speed = fuelsys_IN_normal;
      fuelsys_DW.is_active_Fail = 1U;

      /* Entry Internal 'Fail': '<S18>:14' */
      /* Transition: '<S18>:44' */
      fuelsys_DW.is_Fail = fuelsys_IN_None;
      fuelsys_DW.is_active_Fueling_Mode = 1U;

      /* Entry Internal 'Fueling_Mode': '<S18>:21' */
      /* Transition: '<S18>:64' */
      fuelsys_B.es_o = fuelsys_B.RateTransition;
      fuelsys_DW.is_Fueling_Mode = fuelsys_IN_Running;
      fuelsys_DW.is_Running = fuelsys_IN_Low_Emissions;
      fuelsys_DW.was_Running = fuelsys_IN_Low_Emissions;

      /* Entry 'Low_Emissions': '<S18>:25' */
      fuelsys_B.fuel_mode = LOW;
      fuelsys_DW.is_Low_Emissions = fuelsys_IN_Warmup;
      fuelsys_DW.was_Low_Emissions = fuelsys_IN_Warmup;
    } else {
      if ((fuelsys_DW.is_active_O2 != 0U) && (fuelsys_DW.is_O2 == fuelsys_IN_A))
      {
        /* During 'O2': '<S18>:1' */
        /* During 'A': '<S18>:171' */
        fuelsys_B.es_o.ego = fuelsys_B.RateTransition.ego;
        switch (fuelsys_DW.is_A) {
         case fuelsys_IN_O2_failure:
          /* During 'O2_failure': '<S18>:3' */
          if (fuelsys_B.RateTransition.ego < 1.2F) {
            /* Transition: '<S18>:32' */
            fuelsys_DW.is_A = fuelsys_IN_NO_ACTIVE_CHILD;

            /* Event: '<S18>:91' */
            b_previousEvent = fuelsys_DW.sfEvent;
            fuelsys_DW.sfEvent = fuelsys_event_DEC;
            if (fuelsys_DW.is_active_Fail != 0U) {
              fuelsys_Fail();
            }

            fuelsys_DW.sfEvent = b_previousEvent;
            fuelsys_DW.is_A = fuelsys_IN_O2_normal;
            fuelsys_B.O2_normal = true;
          }
          break;

         case fuelsys_IN_O2_normal:
          /* During 'O2_normal': '<S18>:7' */
          if (fuelsys_B.RateTransition.ego > 1.2F) {
            /* Transition: '<S18>:33' */
            fuelsys_B.O2_normal = false;
            fuelsys_DW.is_A = fuelsys_IN_NO_ACTIVE_CHILD;

            /* Event: '<S18>:92' */
            b_previousEvent = fuelsys_DW.sfEvent;
            fuelsys_DW.sfEvent = fuelsys_event_INC;
            if (fuelsys_DW.is_active_Fail != 0U) {
              fuelsys_Fail();
            }

            fuelsys_DW.sfEvent = b_previousEvent;
            fuelsys_DW.is_A = fuelsys_IN_O2_failure;
          }
          break;

         case fuelsys_IN_O2_warmup:
          /* During 'O2_warmup': '<S18>:4' */
          if (fuelsys_DW.temporalCounter_i1 >= 480) {
            /* Transition: '<S18>:36' */
            fuelsys_DW.is_A = fuelsys_IN_O2_normal;
            fuelsys_B.O2_normal = true;
          }
          break;

         default:
          /* Unreachable state, for coverage only */
          fuelsys_DW.is_A = fuelsys_IN_NO_ACTIVE_CHILD;
          break;
        }
      }

      if (fuelsys_DW.is_active_Pressure != 0U) {
        /* During 'Pressure': '<S18>:2' */
        switch (fuelsys_DW.is_Pressure) {
         case fuelsys_IN_fail:
          /* During 'fail': '<S18>:6' */
          if ((fuelsys_B.RateTransition.map > 0.05F) &&
              (fuelsys_B.RateTransition.map < 0.95F)) {
            /* Transition: '<S18>:37' */
            fuelsys_DW.is_Pressure = fuelsys_IN_NO_ACTIVE_CHILD;

            /* Event: '<S18>:91' */
            b_previousEvent = fuelsys_DW.sfEvent;
            fuelsys_DW.sfEvent = fuelsys_event_DEC;
            if (fuelsys_DW.is_active_Fail != 0U) {
              fuelsys_Fail();
            }

            fuelsys_DW.sfEvent = b_previousEvent;
            fuelsys_DW.is_Pressure = fuelsys_IN_normal;
          } else {
            /* Outputs for Function Call SubSystem: '<S18>/Pressure.map_estimate' */
            /* Simulink Function 'map_estimate': '<S18>:112' */
            fuelsys_B.es_o.map = look2_iflf_linlca
              (fuelsys_B.RateTransition.speed, fuelsys_B.RateTransition.throttle,
               fuelsys_ConstP.pooled2, fuelsys_ConstP.pooled3,
               fuelsys_ConstP.PressureEstimation_tableData,
               fuelsys_ConstP.PressureEstimation_maxIndex, 18U);

            /* End of Outputs for SubSystem: '<S18>/Pressure.map_estimate' */
          }
          break;

         case fuelsys_IN_normal:
          /* During 'normal': '<S18>:5' */
          if ((fuelsys_B.RateTransition.map > 0.95F) ||
              (fuelsys_B.RateTransition.map < 0.05F)) {
            /* Transition: '<S18>:31' */
            fuelsys_DW.is_Pressure = fuelsys_IN_NO_ACTIVE_CHILD;

            /* Event: '<S18>:92' */
            b_previousEvent = fuelsys_DW.sfEvent;
            fuelsys_DW.sfEvent = fuelsys_event_INC;
            if (fuelsys_DW.is_active_Fail != 0U) {
              fuelsys_Fail();
            }

            fuelsys_DW.sfEvent = b_previousEvent;
            fuelsys_DW.is_Pressure = fuelsys_IN_fail;
          } else {
            fuelsys_B.es_o.map = fuelsys_B.RateTransition.map;
          }
          break;

         default:
          /* Unreachable state, for coverage only */
          fuelsys_DW.is_Pressure = fuelsys_IN_NO_ACTIVE_CHILD;
          break;
        }
      }

      if (fuelsys_DW.is_active_Throttle != 0U) {
        /* During 'Throttle': '<S18>:8' */
        switch (fuelsys_DW.is_Throttle) {
         case fuelsys_IN_fail:
          /* During 'fail': '<S18>:11' */
          if ((fuelsys_B.RateTransition.throttle > 3.0F) &&
              (fuelsys_B.RateTransition.throttle < 90.0F)) {
            /* Transition: '<S18>:42' */
            fuelsys_DW.is_Throttle = fuelsys_IN_NO_ACTIVE_CHILD;

            /* Event: '<S18>:91' */
            b_previousEvent = fuelsys_DW.sfEvent;
            fuelsys_DW.sfEvent = fuelsys_event_DEC;
            if (fuelsys_DW.is_active_Fail != 0U) {
              fuelsys_Fail();
            }

            fuelsys_DW.sfEvent = b_previousEvent;
            fuelsys_DW.is_Throttle = fuelsys_IN_normal;
          } else {
            /* Outputs for Function Call SubSystem: '<S18>/Throttle.throttle_estimate' */
            /* Simulink Function 'throttle_estimate': '<S18>:107' */
            fuelsys_B.es_o.throttle = look2_iflf_linlca
              (fuelsys_B.RateTransition.speed, fuelsys_B.RateTransition.map,
               fuelsys_ConstP.pooled2, fuelsys_ConstP.pooled4,
               fuelsys_ConstP.ThrottleEstimation_tableData,
               fuelsys_ConstP.pooled9, 18U);

            /* End of Outputs for SubSystem: '<S18>/Throttle.throttle_estimate' */
          }
          break;

         case fuelsys_IN_normal:
          /* During 'normal': '<S18>:10' */
          if ((fuelsys_B.RateTransition.throttle > 90.0F) ||
              (fuelsys_B.RateTransition.throttle < 3.0F)) {
            /* Transition: '<S18>:38' */
            fuelsys_DW.is_Throttle = fuelsys_IN_NO_ACTIVE_CHILD;

            /* Event: '<S18>:92' */
            b_previousEvent = fuelsys_DW.sfEvent;
            fuelsys_DW.sfEvent = fuelsys_event_INC;
            if (fuelsys_DW.is_active_Fail != 0U) {
              fuelsys_Fail();
            }

            fuelsys_DW.sfEvent = b_previousEvent;
            fuelsys_DW.is_Throttle = fuelsys_IN_fail;
          } else {
            fuelsys_B.es_o.throttle = fuelsys_B.RateTransition.throttle;
          }
          break;

         default:
          /* Unreachable state, for coverage only */
          fuelsys_DW.is_Throttle = fuelsys_IN_NO_ACTIVE_CHILD;
          break;
        }
      }

      if (fuelsys_DW.is_active_Speed != 0U) {
        /* During 'Speed': '<S18>:9' */
        switch (fuelsys_DW.is_Speed) {
         case fuelsys_IN_fail:
          /* During 'fail': '<S18>:13' */
          if (fuelsys_B.RateTransition.speed > 0.0F) {
            /* Transition: '<S18>:43' */
            fuelsys_DW.is_Speed = fuelsys_IN_NO_ACTIVE_CHILD;

            /* Event: '<S18>:91' */
            b_previousEvent = fuelsys_DW.sfEvent;
            fuelsys_DW.sfEvent = fuelsys_event_DEC;
            if (fuelsys_DW.is_active_Fail != 0U) {
              fuelsys_Fail();
            }

            fuelsys_DW.sfEvent = b_previousEvent;
            fuelsys_DW.is_Speed = fuelsys_IN_normal;
          } else {
            /* Outputs for Function Call SubSystem: '<S18>/Speed.speed_estimate' */
            /* Lookup_n-D: '<S23>/Speed Estimation' */
            /* Simulink Function 'speed_estimate': '<S18>:119' */
            rtb_throttle = look2_iflf_linlca(fuelsys_B.RateTransition.throttle,
              fuelsys_B.RateTransition.map, fuelsys_ConstP.pooled3,
              fuelsys_ConstP.pooled4, fuelsys_ConstP.SpeedEstimation_tableData,
              fuelsys_ConstP.SpeedEstimation_maxIndex, 17U);

            /* Saturate: '<S23>/Saturation' */
            if (rtb_throttle > 628.0F) {
              fuelsys_B.es_o.speed = 628.0F;
            } else if (rtb_throttle < 0.0F) {
              fuelsys_B.es_o.speed = 0.0F;
            } else {
              fuelsys_B.es_o.speed = rtb_throttle;
            }

            /* End of Saturate: '<S23>/Saturation' */
            /* End of Outputs for SubSystem: '<S18>/Speed.speed_estimate' */
          }
          break;

         case fuelsys_IN_normal:
          /* During 'normal': '<S18>:12' */
          if ((fuelsys_B.RateTransition.speed == 0.0F) &&
              (fuelsys_B.RateTransition.map < 250.0F)) {
            /* Transition: '<S18>:40' */
            fuelsys_DW.is_Speed = fuelsys_IN_NO_ACTIVE_CHILD;

            /* Event: '<S18>:92' */
            b_previousEvent = fuelsys_DW.sfEvent;
            fuelsys_DW.sfEvent = fuelsys_event_INC;
            if (fuelsys_DW.is_active_Fail != 0U) {
              fuelsys_Fail();
            }

            fuelsys_DW.sfEvent = b_previousEvent;
            fuelsys_DW.is_Speed = fuelsys_IN_fail;
          } else {
            fuelsys_B.es_o.speed = fuelsys_B.RateTransition.speed;
          }
          break;

         default:
          /* Unreachable state, for coverage only */
          fuelsys_DW.is_Speed = fuelsys_IN_NO_ACTIVE_CHILD;
          break;
        }
      }

      if (fuelsys_DW.is_active_Fail != 0U) {
        fuelsys_Fail();
      }

      if (fuelsys_DW.is_active_Fueling_Mode != 0U) {
        fuelsys_Fueling_Mode();
      }
    }

    /* End of Chart: '<S6>/control_logic' */

    /* DiscreteFilter: '<S17>/Throttle Transient' */
    rtb_throttle = fuelsys_B.es_o.throttle - -0.8F *
      fuelsys_DW.ThrottleTransient_states;

    /* MultiPortSwitch: '<S25>/Multiport Switch' incorporates:
     *  Constant: '<S25>/normal'
     *  Constant: '<S25>/rich'
     *  Constant: '<S25>/shutdown'
     */
    switch (fuelsys_B.fuel_mode) {
     case LOW:
      rtb_MultiportSwitch = 0.0684931502F;
      break;

     case RICH:
      rtb_MultiportSwitch = 0.0856164396F;
      break;

     default:
      rtb_MultiportSwitch = 0.0F;
      break;
    }

    /* End of MultiPortSwitch: '<S25>/Multiport Switch' */

    /* SwitchCase: '<S26>/Switch Case' incorporates:
     *  Constant: '<S27>/shutoff'
     */
    switch (fuelsys_B.fuel_mode) {
     case LOW:
      /* Outputs for IfAction SubSystem: '<S26>/low_mode' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* DiscreteFilter: '<S28>/Discrete Filter' incorporates:
       *  DiscreteIntegrator: '<S17>/Discrete Integrator'
       */
      denAccum = fuelsys_DW.DiscreteIntegrator_DSTATE - -0.7408F *
        fuelsys_DW.DiscreteFilter_states_i;

      /* Sum: '<S28>/Sum3' incorporates:
       *  DiscreteFilter: '<S17>/Throttle Transient'
       *  DiscreteFilter: '<S28>/Discrete Filter'
       *  Lookup_n-D: '<S17>/Pumping Constant'
       *  Product: '<S17>/Product'
       *  Product: '<S17>/Product2'
       *  Product: '<S25>/Product'
       *  Sum: '<S17>/Sum'
       */
      rtb_ego = ((0.01F * rtb_throttle + -0.01F *
                  fuelsys_DW.ThrottleTransient_states) + fuelsys_B.es_o.speed *
                 look2_iflf_linlca(fuelsys_B.es_o.speed, fuelsys_B.es_o.map,
                  fuelsys_ConstP.pooled2, fuelsys_ConstP.pooled4,
                  fuelsys_ConstP.PumpingConstant_tableData,
                  fuelsys_ConstP.pooled9, 18U) * fuelsys_B.es_o.map) *
        rtb_MultiportSwitch + (8.7696F * denAccum + -8.5104F *
        fuelsys_DW.DiscreteFilter_states_i);

      /* Update for DiscreteFilter: '<S28>/Discrete Filter' */
      fuelsys_DW.DiscreteFilter_states_i = denAccum;

      /* End of Outputs for SubSystem: '<S26>/low_mode' */
      break;

     case RICH:
      /* Outputs for IfAction SubSystem: '<S26>/rich_mode' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* DiscreteFilter: '<S29>/Discrete Filter' */
      rtb_ego = 0.2592F * fuelsys_DW.DiscreteFilter_states;

      /* Update for DiscreteFilter: '<S29>/Discrete Filter' incorporates:
       *  DiscreteFilter: '<S17>/Throttle Transient'
       *  DiscreteIntegrator: '<S17>/Discrete Integrator'
       *  Lookup_n-D: '<S17>/Pumping Constant'
       *  Product: '<S17>/Product'
       *  Product: '<S17>/Product2'
       *  Product: '<S25>/Product'
       *  Sum: '<S17>/Sum'
       *  Sum: '<S29>/Sum2'
       */
      fuelsys_DW.DiscreteFilter_states = (((0.01F * rtb_throttle + -0.01F *
        fuelsys_DW.ThrottleTransient_states) + fuelsys_B.es_o.speed *
        look2_iflf_linlca(fuelsys_B.es_o.speed, fuelsys_B.es_o.map,
                          fuelsys_ConstP.pooled2, fuelsys_ConstP.pooled4,
                          fuelsys_ConstP.PumpingConstant_tableData,
                          fuelsys_ConstP.pooled9, 18U) * fuelsys_B.es_o.map) *
        rtb_MultiportSwitch + fuelsys_DW.DiscreteIntegrator_DSTATE) - -0.7408F *
        fuelsys_DW.DiscreteFilter_states;

      /* End of Outputs for SubSystem: '<S26>/rich_mode' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S26>/disabled_mode' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      rtb_ego = 0.0F;

      /* End of Outputs for SubSystem: '<S26>/disabled_mode' */
      break;
    }

    /* End of SwitchCase: '<S26>/Switch Case' */

    /* Switch: '<S17>/hold integrator' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant2'
     *  Constant: '<S17>/Oxygen Sensor Switching Threshold'
     *  Constant: '<S21>/Constant'
     *  DataTypeConversion: '<S17>/Data Type  Conversion'
     *  Logic: '<S17>/Logic1'
     *  Lookup_n-D: '<S17>/Ramp Rate Ki'
     *  Product: '<S17>/Product1'
     *  RelationalOperator: '<S17>/Relational Operator1'
     *  RelationalOperator: '<S17>/Relational Operator3'
     *  Sum: '<S17>/Sum1'
     */
    if (fuelsys_B.O2_normal && (fuelsys_B.fuel_mode == LOW)) {
      rtb_MultiportSwitch = ((real32_T)(fuelsys_B.es_o.ego <= 0.5F) - 0.5F) *
        look2_iflf_linlca(fuelsys_B.es_o.speed, fuelsys_B.es_o.map,
                          fuelsys_ConstP.RampRateKi_bp01Data,
                          fuelsys_ConstP.RampRateKi_bp02Data,
                          fuelsys_ConstP.RampRateKi_tableData,
                          fuelsys_ConstP.RampRateKi_maxIndex, 6U);
    } else {
      rtb_MultiportSwitch = 0.0F;
    }

    /* End of Switch: '<S17>/hold integrator' */

    /* Update for DiscreteIntegrator: '<S17>/Discrete Integrator' */
    fuelsys_DW.DiscreteIntegrator_DSTATE += 0.01F * rtb_MultiportSwitch;

    /* Update for DiscreteFilter: '<S17>/Throttle Transient' */
    fuelsys_DW.ThrottleTransient_states = rtb_throttle;

    /* End of Outputs for SubSystem: '<Root>/fuel_rate_control' */

    /* DataTypeConversion: '<S5>/DTC5' */
    fuelsys_B.DTC5 = rtb_ego;
  }

  if (rtmIsMajorTimeStep(fuelsys_M) &&
      fuelsys_M->Timing.TaskCounters.TID[1] == 0) {
    /* MinMax: '<S7>/MinMax' */
    if (fuelsys_B.DTC5 > 0.1) {
      fuelsys_B.MinMax = fuelsys_B.DTC5;
    } else {
      fuelsys_B.MinMax = 0.1;
    }

    /* End of MinMax: '<S7>/MinMax' */
  }

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Engine Speed'
   */
  /* MATLAB Function 'Engine Gas Dynamics/Throttle & Manifold/Intake Manifold/MATLAB Function': '<S13>:1' */
  /* '<S13>:1:4' */
  rtb_y_j = ((0.08979 * fuelsys_B.p00589bar * 300.0 + -0.366) -
             fuelsys_B.p00589bar * fuelsys_B.p00589bar * 10.11) + 0.0001 *
    fuelsys_B.p00589bar * 90000.0;

  /* Product: '<S7>/Product' */
  fuelsys_B.Product = rtb_y_j / fuelsys_B.MinMax;

  /* Saturate: '<S8>/Limit to Positive' */
  if (fuelsys_B.LookUpTable1 <= 0.0) {
    rtb_LimittoPositive = 0.0;
  } else {
    rtb_LimittoPositive = fuelsys_B.LookUpTable1;
  }

  /* End of Saturate: '<S8>/Limit to Positive' */

  /* Product: '<S12>/Product2' */
  /* MATLAB Function 'Engine Gas Dynamics/Throttle & Manifold/Throttle/f(theta)': '<S14>:1' */
  /* '<S14>:1:4' */
  rtb_pratio = 1.0 / fuelsys_B.p00589bar;

  /* MinMax: '<S12>/MinMax' incorporates:
   *  Product: '<S12>/Product1'
   */
  if ((fuelsys_B.p00589bar < rtb_pratio) || rtIsNaN(rtb_pratio)) {
    rtb_pratio = fuelsys_B.p00589bar;
  }

  /* End of MinMax: '<S12>/MinMax' */

  /* Switch: '<S12>/threshold = 0.5' incorporates:
   *  Constant: '<S12>/Sonic Flow '
   *  MATLAB Function: '<S12>/g(pratio)'
   */
  /* MATLAB Function 'Engine Gas Dynamics/Throttle & Manifold/Throttle/g(pratio)': '<S15>:1' */
  /* '<S15>:1:4' */
  if (rtb_pratio >= 0.5) {
    rtb_pratio = sqrt(rtb_pratio - rtb_pratio * rtb_pratio) * 2.0;
  } else {
    rtb_pratio = 1.0;
  }

  /* End of Switch: '<S12>/threshold = 0.5' */

  /* Signum: '<S12>/direction' incorporates:
   *  Constant: '<S8>/Atmospheric Pressure, Pa (bar)'
   *  Sum: '<S12>/Sum'
   */
  if (1.0 - fuelsys_B.p00589bar < 0.0) {
    tmp = -1.0;
  } else if (1.0 - fuelsys_B.p00589bar > 0.0) {
    tmp = 1.0;
  } else if (1.0 - fuelsys_B.p00589bar == 0.0) {
    tmp = 0.0;
  } else {
    tmp = (rtNaN);
  }

  /* End of Signum: '<S12>/direction' */

  /* Gain: '<S11>/RT//Vm' incorporates:
   *  MATLAB Function: '<S12>/f(theta)'
   *  Product: '<S12>/Product'
   *  Sum: '<S11>/Sum'
   */
  fuelsys_B.RTVm = ((((2.821 - 0.05231 * rtb_LimittoPositive) +
                      rtb_LimittoPositive * rtb_LimittoPositive * 0.10299) -
                     0.00063 * rt_powd_snf(rtb_LimittoPositive, 3.0)) *
                    rtb_pratio * tmp - rtb_y_j) * 0.41328;
  if (rtmIsMajorTimeStep(fuelsys_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(fuelsys_M->rtwLogInfo, (fuelsys_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(fuelsys_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(fuelsys_M)!=-1) &&
          !((rtmGetTFinal(fuelsys_M)-(((fuelsys_M->Timing.clockTick1+
               fuelsys_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((fuelsys_M->Timing.clockTick1+fuelsys_M->Timing.clockTickH1*
               4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(fuelsys_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&fuelsys_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++fuelsys_M->Timing.clockTick0)) {
      ++fuelsys_M->Timing.clockTickH0;
    }

    fuelsys_M->Timing.t[0] = rtsiGetSolverStopTime(&fuelsys_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      fuelsys_M->Timing.clockTick1++;
      if (!fuelsys_M->Timing.clockTick1) {
        fuelsys_M->Timing.clockTickH1++;
      }
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void fuelsys_derivatives(void)
{
  XDot_fuelsys_T *_rtXdot;
  _rtXdot = ((XDot_fuelsys_T *) fuelsys_M->derivs);

  /* Derivatives for StateSpace: '<S10>/State Space' */
  _rtXdot->StateSpace_CSTATE = 0.0;
  _rtXdot->StateSpace_CSTATE += -3.0 * fuelsys_X.StateSpace_CSTATE;
  _rtXdot->StateSpace_CSTATE += fuelsys_B.Product;

  /* Derivatives for Integrator: '<S11>/p0 = 0.589 bar' */
  _rtXdot->p00589bar_CSTATE = fuelsys_B.RTVm;
}

/* Model initialize function */
void fuelsys_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)fuelsys_M, 0,
                sizeof(RT_MODEL_fuelsys_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&fuelsys_M->solverInfo, &fuelsys_M->Timing.simTimeStep);
    rtsiSetTPtr(&fuelsys_M->solverInfo, &rtmGetTPtr(fuelsys_M));
    rtsiSetStepSizePtr(&fuelsys_M->solverInfo, &fuelsys_M->Timing.stepSize0);
    rtsiSetdXPtr(&fuelsys_M->solverInfo, &fuelsys_M->derivs);
    rtsiSetContStatesPtr(&fuelsys_M->solverInfo, (real_T **)
                         &fuelsys_M->contStates);
    rtsiSetNumContStatesPtr(&fuelsys_M->solverInfo,
      &fuelsys_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&fuelsys_M->solverInfo,
      &fuelsys_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&fuelsys_M->solverInfo,
      &fuelsys_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&fuelsys_M->solverInfo,
      &fuelsys_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&fuelsys_M->solverInfo, (&rtmGetErrorStatus(fuelsys_M)));
    rtsiSetRTModelPtr(&fuelsys_M->solverInfo, fuelsys_M);
  }

  rtsiSetSimTimeStep(&fuelsys_M->solverInfo, MAJOR_TIME_STEP);
  fuelsys_M->intgData.y = fuelsys_M->odeY;
  fuelsys_M->intgData.f[0] = fuelsys_M->odeF[0];
  fuelsys_M->intgData.f[1] = fuelsys_M->odeF[1];
  fuelsys_M->intgData.f[2] = fuelsys_M->odeF[2];
  fuelsys_M->contStates = ((X_fuelsys_T *) &fuelsys_X);
  rtsiSetSolverData(&fuelsys_M->solverInfo, (void *)&fuelsys_M->intgData);
  rtsiSetSolverName(&fuelsys_M->solverInfo,"ode3");
  rtmSetTPtr(fuelsys_M, &fuelsys_M->Timing.tArray[0]);
  rtmSetTFinal(fuelsys_M, 2000.0);
  fuelsys_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    fuelsys_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(fuelsys_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(fuelsys_M->rtwLogInfo, (NULL));
    rtliSetLogT(fuelsys_M->rtwLogInfo, "");
    rtliSetLogX(fuelsys_M->rtwLogInfo, "");
    rtliSetLogXFinal(fuelsys_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(fuelsys_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(fuelsys_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(fuelsys_M->rtwLogInfo, 0);
    rtliSetLogDecimation(fuelsys_M->rtwLogInfo, 1);
    rtliSetLogY(fuelsys_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(fuelsys_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(fuelsys_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &fuelsys_B), 0,
                sizeof(B_fuelsys_T));

  {
    fuelsys_B.fuel_mode = LOW;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&fuelsys_X, 0,
                  sizeof(X_fuelsys_T));
  }

  /* states (dwork) */
  (void) memset((void *)&fuelsys_DW, 0,
                sizeof(DW_fuelsys_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(fuelsys_M->rtwLogInfo, 0.0, rtmGetTFinal
    (fuelsys_M), fuelsys_M->Timing.stepSize0, (&rtmGetErrorStatus(fuelsys_M)));

  /* InitializeConditions for StateSpace: '<S10>/State Space' */
  fuelsys_X.StateSpace_CSTATE = 0.0228310502283105;

  /* InitializeConditions for Integrator: '<S11>/p0 = 0.589 bar' */
  fuelsys_X.p00589bar_CSTATE = 0.589;

  /* SystemInitialize for Atomic SubSystem: '<Root>/fuel_rate_control' */
  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete Integrator' */
  fuelsys_DW.DiscreteIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteFilter: '<S17>/Throttle Transient' */
  fuelsys_DW.ThrottleTransient_states = 0.0F;

  /* SystemInitialize for Chart: '<S6>/control_logic' */
  fuelsys_DW.sfEvent = -1;
  fuelsys_DW.is_active_Fail = 0U;
  fuelsys_DW.is_Fail = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_Multi = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_active_Fueling_Mode = 0U;
  fuelsys_DW.is_Fueling_Mode = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_Fuel_Disabled = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_Running = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.was_Running = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_Low_Emissions = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.was_Low_Emissions = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_Rich_Mixture = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_active_O2 = 0U;
  fuelsys_DW.is_O2 = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_A = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.temporalCounter_i1 = 0U;
  fuelsys_DW.is_active_Pressure = 0U;
  fuelsys_DW.is_Pressure = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_active_Speed = 0U;
  fuelsys_DW.is_Speed = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_active_Throttle = 0U;
  fuelsys_DW.is_Throttle = fuelsys_IN_NO_ACTIVE_CHILD;
  fuelsys_DW.is_active_c1_fuelsys = 0U;
  fuelsys_B.es_o.throttle = 0.0F;
  fuelsys_B.es_o.speed = 0.0F;
  fuelsys_B.es_o.ego = 0.0F;
  fuelsys_B.es_o.map = 0.0F;
  fuelsys_B.O2_normal = false;
  fuelsys_B.fuel_mode = LOW;

  /* SystemInitialize for IfAction SubSystem: '<S26>/low_mode' */
  /* InitializeConditions for DiscreteFilter: '<S28>/Discrete Filter' */
  fuelsys_DW.DiscreteFilter_states_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S26>/low_mode' */

  /* SystemInitialize for IfAction SubSystem: '<S26>/rich_mode' */
  /* InitializeConditions for DiscreteFilter: '<S29>/Discrete Filter' */
  fuelsys_DW.DiscreteFilter_states = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S26>/rich_mode' */
  /* End of SystemInitialize for SubSystem: '<Root>/fuel_rate_control' */
}

/* Model terminate function */
void fuelsys_terminate(void)
{
  /* (no terminate code required) */
}
