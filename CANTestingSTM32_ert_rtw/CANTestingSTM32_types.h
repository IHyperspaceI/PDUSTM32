/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CANTestingSTM32_types.h
 *
 * Code generated for Simulink model 'CANTestingSTM32'.
 *
 * Model version                  : 13.147
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May 26 20:20:07 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef CANTestingSTM32_types_h_
#define CANTestingSTM32_types_h_
#include "rtwtypes.h"
#include "mw_stm32_spi_ll.h"
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

/* Custom Type definition for MATLABSystem: '<S1>/SPI Controller Transfer' */
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
typedef struct tag_RTM_CANTestingSTM32_T RT_MODEL_CANTestingSTM32_T;

#endif                                 /* CANTestingSTM32_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
