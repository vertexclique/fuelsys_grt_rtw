/*
 * fuelsys_types.h
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

#ifndef RTW_HEADER_fuelsys_types_h_
#define RTW_HEADER_fuelsys_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_EngSensors_
#define DEFINED_TYPEDEF_FOR_EngSensors_

typedef struct {
  real32_T throttle;
  real32_T speed;
  real32_T ego;
  real32_T map;
} EngSensors;

#endif

#ifndef DEFINED_TYPEDEF_FOR_sld_FuelModes_
#define DEFINED_TYPEDEF_FOR_sld_FuelModes_

typedef enum {
  LOW = 1,                             /* Default value */
  RICH,
  DISABLED
} sld_FuelModes;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_fuelsys_T RT_MODEL_fuelsys_T;

#endif                                 /* RTW_HEADER_fuelsys_types_h_ */
