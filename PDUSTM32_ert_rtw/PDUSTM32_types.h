/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PDUSTM32_types.h
 *
 * Code generated for Simulink model 'PDUSTM32'.
 *
 * Model version                  : 13.213
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jul 29 19:04:52 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PDUSTM32_types_h_
#define PDUSTM32_types_h_
#include "rtwtypes.h"
#include "mw_stm32_spi_ll.h"
#include "stm_adc_ll.h"
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_def_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_def_

typedef struct {
  uint32_T ID;
  boolean_T Extended;
  boolean_T Remote;
  boolean_T Error;
  real_T Length;
  uint8_T Data[8];
} CAN_MESSAGE_def;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

typedef struct {
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
} CAN_MESSAGE_BUS;

#endif

/* Custom Type definition for MATLABSystem: '<S6>/SPI Controller Transfer' */
#include "mw_stm32_spi_ll.h"
#include "mw_stm32_spi_ll.h"
#ifndef struct_tag_eH4w3s88qRk3dEce3kceRG
#define struct_tag_eH4w3s88qRk3dEce3kceRG

struct tag_eH4w3s88qRk3dEce3kceRG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  STM32_SPI_ModuleStruct_T* MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_eH4w3s88qRk3dEce3kceRG */

#ifndef typedef_stm32cube_blocks_SPIControlle_T
#define typedef_stm32cube_blocks_SPIControlle_T

typedef struct tag_eH4w3s88qRk3dEce3kceRG stm32cube_blocks_SPIControlle_T;

#endif                             /* typedef_stm32cube_blocks_SPIControlle_T */

/* Custom Type definition for MATLABSystem: '<S22>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_zOwLqZHHwTkA89oP5eJ7RB
#define struct_tag_zOwLqZHHwTkA89oP5eJ7RB

struct tag_zOwLqZHHwTkA89oP5eJ7RB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  ADC_Type_T* ADCHandle;
  uint32_T * ADCInternalBuffer;
};

#endif                                 /* struct_tag_zOwLqZHHwTkA89oP5eJ7RB */

#ifndef typedef_stm32cube_blocks_AnalogInputF_T
#define typedef_stm32cube_blocks_AnalogInputF_T

typedef struct tag_zOwLqZHHwTkA89oP5eJ7RB stm32cube_blocks_AnalogInputF_T;

#endif                             /* typedef_stm32cube_blocks_AnalogInputF_T */

#ifndef struct_tag_GSKovyH6bCN42HwFzVB4DE
#define struct_tag_GSKovyH6bCN42HwFzVB4DE

struct tag_GSKovyH6bCN42HwFzVB4DE
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_GSKovyH6bCN42HwFzVB4DE */

#ifndef typedef_stm32cube_blocks_DigitalPortR_T
#define typedef_stm32cube_blocks_DigitalPortR_T

typedef struct tag_GSKovyH6bCN42HwFzVB4DE stm32cube_blocks_DigitalPortR_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortR_T */

#ifndef struct_tag_tsKyPuhWUdS8zBSeRGR2aC
#define struct_tag_tsKyPuhWUdS8zBSeRGR2aC

struct tag_tsKyPuhWUdS8zBSeRGR2aC
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_tsKyPuhWUdS8zBSeRGR2aC */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_tsKyPuhWUdS8zBSeRGR2aC stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_PDUSTM32_T RT_MODEL_PDUSTM32_T;

#endif                                 /* PDUSTM32_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
