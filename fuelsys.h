/*
 * fuelsys.h
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

#ifndef RTW_HEADER_fuelsys_h_
#define RTW_HEADER_fuelsys_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef fuelsys_COMMON_INCLUDES_
# define fuelsys_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* fuelsys_COMMON_INCLUDES_ */

#include "fuelsys_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  EngSensors RateTransition;           /* '<S4>/Rate Transition' */
  EngSensors es_o;                     /* '<S6>/control_logic' */
  real_T LookUpTable1;                 /* '<S3>/Look-Up Table1' */
  real_T StateSpace;                   /* '<S10>/State Space' */
  real_T p00589bar;                    /* '<S11>/p0 = 0.589 bar' */
  real_T DTC5;                         /* '<S5>/DTC5' */
  real_T MinMax;                       /* '<S7>/MinMax' */
  real_T Product;                      /* '<S7>/Product' */
  real_T RTVm;                         /* '<S11>/RT//Vm' */
  real_T y;                            /* '<S7>/EGO Sensor' */
  sld_FuelModes fuel_mode;             /* '<S6>/control_logic' */
  boolean_T O2_normal;                 /* '<S6>/control_logic' */
} B_fuelsys_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  real32_T DiscreteIntegrator_DSTATE;  /* '<S17>/Discrete Integrator' */
  real32_T ThrottleTransient_states;   /* '<S17>/Throttle Transient' */
  real32_T DiscreteFilter_states;      /* '<S29>/Discrete Filter' */
  real32_T DiscreteFilter_states_i;    /* '<S28>/Discrete Filter' */
  int32_T sfEvent;                     /* '<S6>/control_logic' */
  uint16_T temporalCounter_i1;         /* '<S6>/control_logic' */
  uint8_T is_active_c1_fuelsys;        /* '<S6>/control_logic' */
  uint8_T is_O2;                       /* '<S6>/control_logic' */
  uint8_T is_active_O2;                /* '<S6>/control_logic' */
  uint8_T is_A;                        /* '<S6>/control_logic' */
  uint8_T is_Pressure;                 /* '<S6>/control_logic' */
  uint8_T is_active_Pressure;          /* '<S6>/control_logic' */
  uint8_T is_Throttle;                 /* '<S6>/control_logic' */
  uint8_T is_active_Throttle;          /* '<S6>/control_logic' */
  uint8_T is_Speed;                    /* '<S6>/control_logic' */
  uint8_T is_active_Speed;             /* '<S6>/control_logic' */
  uint8_T is_Fail;                     /* '<S6>/control_logic' */
  uint8_T is_active_Fail;              /* '<S6>/control_logic' */
  uint8_T is_Multi;                    /* '<S6>/control_logic' */
  uint8_T is_Fueling_Mode;             /* '<S6>/control_logic' */
  uint8_T is_active_Fueling_Mode;      /* '<S6>/control_logic' */
  uint8_T is_Fuel_Disabled;            /* '<S6>/control_logic' */
  uint8_T is_Running;                  /* '<S6>/control_logic' */
  uint8_T was_Running;                 /* '<S6>/control_logic' */
  uint8_T is_Low_Emissions;            /* '<S6>/control_logic' */
  uint8_T was_Low_Emissions;           /* '<S6>/control_logic' */
  uint8_T is_Rich_Mixture;             /* '<S6>/control_logic' */
} DW_fuelsys_T;

/* Continuous states (default storage) */
typedef struct {
  real_T StateSpace_CSTATE;            /* '<S10>/State Space' */
  real_T p00589bar_CSTATE;             /* '<S11>/p0 = 0.589 bar' */
} X_fuelsys_T;

/* State derivatives (default storage) */
typedef struct {
  real_T StateSpace_CSTATE;            /* '<S10>/State Space' */
  real_T p00589bar_CSTATE;             /* '<S11>/p0 = 0.589 bar' */
} XDot_fuelsys_T;

/* State disabled  */
typedef struct {
  boolean_T StateSpace_CSTATE;         /* '<S10>/State Space' */
  boolean_T p00589bar_CSTATE;          /* '<S11>/p0 = 0.589 bar' */
} XDis_fuelsys_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: rep_seq_y
   * Referenced by: '<S3>/Look-Up Table1'
   */
  real_T LookUpTable1_tableData[3];

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S3>/Look-Up Table1'
   */
  real_T LookUpTable1_bp01Data[3];

  /* Computed Parameter: RampRateKi_tableData
   * Referenced by: '<S17>/Ramp Rate Ki'
   */
  real32_T RampRateKi_tableData[36];

  /* Computed Parameter: RampRateKi_bp01Data
   * Referenced by: '<S17>/Ramp Rate Ki'
   */
  real32_T RampRateKi_bp01Data[6];

  /* Computed Parameter: RampRateKi_bp02Data
   * Referenced by: '<S17>/Ramp Rate Ki'
   */
  real32_T RampRateKi_bp02Data[6];

  /* Computed Parameter: PressureEstimation_tableData
   * Referenced by: '<S22>/Pressure Estimation'
   */
  real32_T PressureEstimation_tableData[306];

  /* Pooled Parameter (Expression: SpeedVect)
   * Referenced by:
   *   '<S17>/Pumping Constant'
   *   '<S22>/Pressure Estimation'
   *   '<S24>/Throttle Estimation'
   */
  real32_T pooled2[18];

  /* Pooled Parameter (Expression: ThrotVect)
   * Referenced by:
   *   '<S22>/Pressure Estimation'
   *   '<S23>/Speed Estimation'
   */
  real32_T pooled3[17];

  /* Computed Parameter: ThrottleEstimation_tableData
   * Referenced by: '<S24>/Throttle Estimation'
   */
  real32_T ThrottleEstimation_tableData[342];

  /* Computed Parameter: SpeedEstimation_tableData
   * Referenced by: '<S23>/Speed Estimation'
   */
  real32_T SpeedEstimation_tableData[323];

  /* Pooled Parameter (Expression: PressVect)
   * Referenced by:
   *   '<S17>/Pumping Constant'
   *   '<S23>/Speed Estimation'
   *   '<S24>/Throttle Estimation'
   */
  real32_T pooled4[19];

  /* Computed Parameter: PumpingConstant_tableData
   * Referenced by: '<S17>/Pumping Constant'
   */
  real32_T PumpingConstant_tableData[342];

  /* Computed Parameter: RampRateKi_maxIndex
   * Referenced by: '<S17>/Ramp Rate Ki'
   */
  uint32_T RampRateKi_maxIndex[2];

  /* Computed Parameter: PressureEstimation_maxIndex
   * Referenced by: '<S22>/Pressure Estimation'
   */
  uint32_T PressureEstimation_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S17>/Pumping Constant'
   *   '<S24>/Throttle Estimation'
   */
  uint32_T pooled9[2];

  /* Computed Parameter: SpeedEstimation_maxIndex
   * Referenced by: '<S23>/Speed Estimation'
   */
  uint32_T SpeedEstimation_maxIndex[2];
} ConstP_fuelsys_T;

/* Real-time Model Data Structure */
struct tag_RTM_fuelsys_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_fuelsys_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block signals (default storage) */
extern B_fuelsys_T fuelsys_B;

/* Continuous states (default storage) */
extern X_fuelsys_T fuelsys_X;

/* Block states (default storage) */
extern DW_fuelsys_T fuelsys_DW;

/* Constant parameters (default storage) */
extern const ConstP_fuelsys_T fuelsys_ConstP;

/* Model entry point functions */
extern void fuelsys_initialize(void);
extern void fuelsys_step(void);
extern void fuelsys_terminate(void);

/* Real-time Model object */
extern RT_MODEL_fuelsys_T *const fuelsys_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'fuelsys'
 * '<S1>'   : 'fuelsys/Dashboard'
 * '<S2>'   : 'fuelsys/Engine Gas Dynamics'
 * '<S3>'   : 'fuelsys/Throttle Command'
 * '<S4>'   : 'fuelsys/To Controller'
 * '<S5>'   : 'fuelsys/To Plant'
 * '<S6>'   : 'fuelsys/fuel_rate_control'
 * '<S7>'   : 'fuelsys/Engine Gas Dynamics/Mixing & Combustion'
 * '<S8>'   : 'fuelsys/Engine Gas Dynamics/Throttle & Manifold'
 * '<S9>'   : 'fuelsys/Engine Gas Dynamics/Mixing & Combustion/EGO Sensor'
 * '<S10>'  : 'fuelsys/Engine Gas Dynamics/Mixing & Combustion/System Lag'
 * '<S11>'  : 'fuelsys/Engine Gas Dynamics/Throttle & Manifold/Intake Manifold'
 * '<S12>'  : 'fuelsys/Engine Gas Dynamics/Throttle & Manifold/Throttle'
 * '<S13>'  : 'fuelsys/Engine Gas Dynamics/Throttle & Manifold/Intake Manifold/MATLAB Function'
 * '<S14>'  : 'fuelsys/Engine Gas Dynamics/Throttle & Manifold/Throttle/f(theta)'
 * '<S15>'  : 'fuelsys/Engine Gas Dynamics/Throttle & Manifold/Throttle/g(pratio)'
 * '<S16>'  : 'fuelsys/To Controller/Sensor Info'
 * '<S17>'  : 'fuelsys/fuel_rate_control/airflow_calc'
 * '<S18>'  : 'fuelsys/fuel_rate_control/control_logic'
 * '<S19>'  : 'fuelsys/fuel_rate_control/fuel_calc'
 * '<S20>'  : 'fuelsys/fuel_rate_control/validate_sample_time'
 * '<S21>'  : 'fuelsys/fuel_rate_control/airflow_calc/Enumerated Constant'
 * '<S22>'  : 'fuelsys/fuel_rate_control/control_logic/Pressure.map_estimate'
 * '<S23>'  : 'fuelsys/fuel_rate_control/control_logic/Speed.speed_estimate'
 * '<S24>'  : 'fuelsys/fuel_rate_control/control_logic/Throttle.throttle_estimate'
 * '<S25>'  : 'fuelsys/fuel_rate_control/fuel_calc/feedforward_fuel_rate'
 * '<S26>'  : 'fuelsys/fuel_rate_control/fuel_calc/switchable_compensation'
 * '<S27>'  : 'fuelsys/fuel_rate_control/fuel_calc/switchable_compensation/disabled_mode'
 * '<S28>'  : 'fuelsys/fuel_rate_control/fuel_calc/switchable_compensation/low_mode'
 * '<S29>'  : 'fuelsys/fuel_rate_control/fuel_calc/switchable_compensation/rich_mode'
 * '<S30>'  : 'fuelsys/fuel_rate_control/validate_sample_time/CheckRange'
 */
#endif                                 /* RTW_HEADER_fuelsys_h_ */
