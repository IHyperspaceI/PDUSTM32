/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_of_PDUSTM32.c
 *
 * Code generated for Simulink model 'Copy_of_PDUSTM32'.
 *
 * Model version                  : 13.228
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Sep 29 17:23:49 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_of_PDUSTM32.h"
#include "rtwtypes.h"
#include "Copy_of_PDUSTM32_types.h"
#include "Copy_of_PDUSTM32_private.h"
#include "mw_stm32_spi_ll.h"
#include "stm_adc_ll.h"

const real_T Copy_of_PDUSTM32_RGND = 0.0;/* real_T ground */

/* Block signals (default storage) */
B_Copy_of_PDUSTM32_T Copy_of_PDUSTM32_B;

/* Block states (default storage) */
DW_Copy_of_PDUSTM32_T Copy_of_PDUSTM32_DW;

/* Real-time model */
static RT_MODEL_Copy_of_PDUSTM32_T Copy_of_PDUSTM32_M_;
RT_MODEL_Copy_of_PDUSTM32_T *const Copy_of_PDUSTM32_M = &Copy_of_PDUSTM32_M_;

/* Forward declaration for local functions */
static void Copy_of_PDUSTM_SystemCore_setup(stm32cube_blocks_AnalogInputF_T *obj);

/*
 * Output and update for atomic system:
 *    '<S2>/MATLAB Function'
 *    '<S3>/MATLAB Function'
 *    '<S4>/MATLAB Function'
 */
void Copy_of_PDUSTM32_MATLABFunction(const uint8_T rtu_Counts[2], real_T rtu_VA,
  real_T *rty_Voltage)
{
  *rty_Voltage = (real_T)(((rtu_Counts[0] << 8) + rtu_Counts[1]) >> 1 != 0) *
    (rtu_VA / 4095.0);
}

/* System initialize for atomic system: */
void Copy_of_PD_DigitalPortRead_Init(DW_DigitalPortRead_Copy_of_PD_T *localDW)
{
  /* Start for MATLABSystem: '<S36>/Digital Port Read' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void Copy_of_PDUSTM3_DigitalPortRead(B_DigitalPortRead_Copy_of_PDU_T *localB)
{
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S36>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S36>/Digital Port Read' */
  localB->DigitalPortRead = ((pinReadLoc & 4U) != 0U);
}

/*
 * System initialize for enable system:
 *    '<S31>/Enabled Subsystem'
 *    '<S32>/Enabled Subsystem'
 */
void Copy_of_P_EnabledSubsystem_Init(DW_EnabledSubsystem_Copy_of_P_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S34>/SPI Controller Transfer7' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/*
 * Output and update for enable system:
 *    '<S31>/Enabled Subsystem'
 *    '<S32>/Enabled Subsystem'
 */
void Copy_of_PDUSTM_EnabledSubsystem(boolean_T rtu_Enable, CANMessage
  *rty_CANMessage, DW_EnabledSubsystem_Copy_of_P_T *localDW)
{
  int32_T i;
  uint8_T rtb_SPIControllerTransfer7_0[15];

  /* Outputs for Enabled SubSystem: '<S31>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  if (rtu_Enable) {
    uint8_T status;

    /* MATLABSystem: '<S34>/SPI Controller Transfer7' incorporates:
     *  Constant: '<S34>/Read RX Buffer start at RXB0SIDH7'
     */
    status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    if (status == 0) {
      GPIO_TypeDef * portNameLoc;
      portNameLoc = GPIOB;
      LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
      MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE,
        &Copy_of_PDUSTM32_ConstP.pooled8[0], &rtb_SPIControllerTransfer7_0[0], 0,
        15U, 1, 10U);
      LL_GPIO_SetOutputPin(portNameLoc, 16384U);
    }

    /* MATLAB Function: '<S34>/MATLAB Function7' incorporates:
     *  MATLABSystem: '<S34>/SPI Controller Transfer7'
     */
    rty_CANMessage->ID = (uint32_T)rtb_SPIControllerTransfer7_0[2] << 3 |
      (uint32_T)rtb_SPIControllerTransfer7_0[3] >> 5;
    rty_CANMessage->Extended = false;
    rty_CANMessage->Remote = false;
    rty_CANMessage->Error = false;
    rty_CANMessage->Length = rtb_SPIControllerTransfer7_0[6] & 15U;
    for (i = 0; i < 8; i++) {
      rty_CANMessage->Data[i] = rtb_SPIControllerTransfer7_0[i + 7];
    }

    /* End of MATLAB Function: '<S34>/MATLAB Function7' */
  }

  /* End of Outputs for SubSystem: '<S31>/Enabled Subsystem' */
}

/*
 * Termination for enable system:
 *    '<S31>/Enabled Subsystem'
 *    '<S32>/Enabled Subsystem'
 */
void Copy_of_P_EnabledSubsystem_Term(DW_EnabledSubsystem_Copy_of_P_T *localDW)
{
  /* Terminate for MATLABSystem: '<S34>/SPI Controller Transfer7' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S34>/SPI Controller Transfer7' */
}

/*
 * Output and update for atomic system:
 *    '<S7>/MATLAB Function2'
 *    '<S8>/MATLAB Function2'
 *    '<S9>/MATLAB Function1'
 *    '<S9>/MATLAB Function2'
 *    '<S9>/MATLAB Function3'
 */
void Copy_of_PDUSTM3_MATLABFunction2(uint32_T rtu_ID, uint8_T rtu_Length, const
  uint8_T rtu_Data[8], uint8_T rtu_RTS, uint16_T rtu_period, uint16_T rtu_offset,
  boolean_T rtu_MCPInitialized, uint8_T *rty_WriteInstruction, uint8_T
  rty_CANVector[13], uint8_T *rty_RTSByte, DW_MATLABFunction2_Copy_of_PD_T
  *localDW)
{
  int32_T i;
  if (rtu_MCPInitialized) {
    uint32_T tmp;
    if (localDW->count == rtu_offset) {
      tmp = rtu_ID;
      if (rtu_ID > 65535U) {
        tmp = 65535U;
      }

      for (i = 0; i < 13; i++) {
        rty_CANVector[i] = 0U;
      }

      i = (uint16_T)tmp >> 3;
      if (i > 255) {
        i = 255;
      }

      rty_CANVector[0] = (uint8_T)i;
      rty_CANVector[1] = (uint8_T)((int32_T)((uint16_T)tmp & 7U) << 5);
      rty_CANVector[2] = 0U;
      rty_CANVector[3] = 0U;
      rty_CANVector[4] = (uint8_T)(rtu_Length & 15);
      for (i = 0; i < 8; i++) {
        rty_CANVector[i + 5] = rtu_Data[i];
      }

      *rty_RTSByte = rtu_RTS;
      *rty_WriteInstruction = 2U;
    } else {
      for (i = 0; i < 13; i++) {
        rty_CANVector[i] = 0U;
      }

      *rty_RTSByte = 3U;
      *rty_WriteInstruction = 3U;
    }

    tmp = localDW->count + 1U;
    if (localDW->count + 1U > 65535U) {
      tmp = 65535U;
    }

    localDW->count = (uint16_T)tmp;
    if (localDW->count >= rtu_period) {
      localDW->count = 0U;
    }
  } else {
    for (i = 0; i < 13; i++) {
      rty_CANVector[i] = 0U;
    }

    *rty_RTSByte = 3U;
    *rty_WriteInstruction = 3U;
  }
}

/* System initialize for atomic system: */
void Cop_SPIControllerTransfer4_Init(DW_SPIControllerTransfer4_Cop_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S7>/SPI Controller Transfer4' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Copy_of__SPIControllerTransfer4(const uint8_T rtu_0[15],
  DW_SPIControllerTransfer4_Cop_T *localDW)
{
  uint8_T tmp[15];
  uint8_T status;

  /* MATLABSystem: '<S7>/SPI Controller Transfer4' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOB;
    LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0], &tmp
      [0], 0, 15U, 0, 1U);
    LL_GPIO_SetOutputPin(portNameLoc, 16384U);
  }

  /* End of MATLABSystem: '<S7>/SPI Controller Transfer4' */
}

/* Termination for atomic system: */
void Cop_SPIControllerTransfer4_Term(DW_SPIControllerTransfer4_Cop_T *localDW)
{
  /* Terminate for MATLABSystem: '<S7>/SPI Controller Transfer4' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/SPI Controller Transfer4' */
}

/* System initialize for atomic system: */
void Cop_SPIControllerTransfer5_Init(DW_SPIControllerTransfer5_Cop_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S7>/SPI Controller Transfer5' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Copy_of__SPIControllerTransfer5(uint8_T rtu_0,
  DW_SPIControllerTransfer5_Cop_T *localDW)
{
  uint8_T rdDataRaw;

  /* MATLABSystem: '<S7>/SPI Controller Transfer5' */
  rdDataRaw = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (rdDataRaw == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOB;
    LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0,
      &rdDataRaw, 0, 1U, 0, 1U);
    LL_GPIO_SetOutputPin(portNameLoc, 16384U);
  }

  /* End of MATLABSystem: '<S7>/SPI Controller Transfer5' */
}

/* Termination for atomic system: */
void Cop_SPIControllerTransfer5_Term(DW_SPIControllerTransfer5_Cop_T *localDW)
{
  /* Terminate for MATLABSystem: '<S7>/SPI Controller Transfer5' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/SPI Controller Transfer5' */
}

/* System initialize for atomic system: */
void Cop_SPIControllerTransfer1_Init(DW_SPIControllerTransfer1_Cop_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S60>/SPI Controller Transfer1' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Copy_of__SPIControllerTransfer1(const uint8_T rtu_0[3],
  DW_SPIControllerTransfer1_Cop_T *localDW)
{
  uint8_T tmp[3];
  uint8_T status;

  /* MATLABSystem: '<S60>/SPI Controller Transfer1' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOB;
    LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0], &tmp
      [0], 0, 3U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 16384U);
  }

  /* End of MATLABSystem: '<S60>/SPI Controller Transfer1' */
}

/* Termination for atomic system: */
void Cop_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_Cop_T *localDW)
{
  /* Terminate for MATLABSystem: '<S60>/SPI Controller Transfer1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S60>/SPI Controller Transfer1' */
}

/* System initialize for atomic system: */
void C_SPIControllerTransfer5_l_Init(DW_SPIControllerTransfer5_C_f_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S60>/SPI Controller Transfer5' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Copy_o_SPIControllerTransfer5_p(const uint8_T rtu_0[4],
  DW_SPIControllerTransfer5_C_f_T *localDW)
{
  uint8_T tmp[4];
  uint8_T status;

  /* MATLABSystem: '<S60>/SPI Controller Transfer5' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOB;
    LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0], &tmp
      [0], 0, 4U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 16384U);
  }

  /* End of MATLABSystem: '<S60>/SPI Controller Transfer5' */
}

/* Termination for atomic system: */
void C_SPIControllerTransfer5_o_Term(DW_SPIControllerTransfer5_C_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S60>/SPI Controller Transfer5' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S60>/SPI Controller Transfer5' */
}

static void Copy_of_PDUSTM_SystemCore_setup(stm32cube_blocks_AnalogInputF_T *obj)
{
  ADC_Type_T adcStructLoc;

  /* Start for MATLABSystem: '<S30>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  obj->ADCInternalBuffer = GET_ADC1_DMA_BUFFER();
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.InternalBufferPtr = obj->ADCInternalBuffer;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = DMA1;
  adcStructLoc.dmastream = LL_DMA_STREAM_0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 7U;
  adcStructLoc.RegularNoOfConversion = 7U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_DMA_INTERRUPT_MODE, 1,
    ADC_READ, LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS);
  enableADCAutomaticCalibration(obj->ADCHandle, (uint32_T)LL_ADC_CALIB_OFFSET, 2);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

/* Model step function */
void Copy_of_PDUSTM32_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_UnitDelay1;
  int32_T i;
  uint32_T rtb_AnalogtoDigitalConverter_0[7];
  uint32_T pinReadLoc;
  uint8_T rtb_VectorConcatenate1[15];
  uint8_T rtb_VectorConcatenate2[15];
  uint8_T rtb_VectorConcatenate2_fg[15];
  uint8_T rtb_VectorConcatenate2_i[15];
  uint8_T rtb_VectorConcatenate3[15];
  uint8_T rtb_SPIControllerTransfer1_bx_0[2];
  uint8_T rtb_FixPtSum1;
  uint8_T rtb_RTSByte;
  uint8_T status;
  boolean_T UnitDelay1_DSTATE_tmp;

  /* MATLABSystem: '<S1>/SPI Controller Transfer1' incorporates:
   *  Constant: '<S1>/Dummy Bits'
   */
  status = MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj_l.MW_SPI_HANDLE, 0U,
    1792U, MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 1U);
    MW_SPI_MasterWriteRead_Databits(Copy_of_PDUSTM32_DW.obj_l.MW_SPI_HANDLE,
      &Copy_of_PDUSTM32_ConstP.pooled9[0], &rtb_SPIControllerTransfer1_bx_0[0],
      0, 2U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 1U);
  }

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/VA'
   *  MATLABSystem: '<S1>/SPI Controller Transfer1'
   */
  Copy_of_PDUSTM32_B.Voltage_a = (real_T)(((rtb_SPIControllerTransfer1_bx_0[0] <<
    8) + rtb_SPIControllerTransfer1_bx_0[1]) >> 1 != 0) * 0.001221001221001221;

  /* MATLABSystem: '<S2>/SPI Controller Transfer1' incorporates:
   *  Constant: '<S2>/Dummy Bits'
   */
  status = MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj_d.MW_SPI_HANDLE, 0U,
    1792U, MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 2U);
    MW_SPI_MasterWriteRead_Databits(Copy_of_PDUSTM32_DW.obj_d.MW_SPI_HANDLE,
      &Copy_of_PDUSTM32_ConstP.pooled9[0], &rtb_SPIControllerTransfer1_bx_0[0],
      0, 2U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 2U);
  }

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<S2>/VA'
   *  MATLABSystem: '<S2>/SPI Controller Transfer1'
   */
  Copy_of_PDUSTM32_MATLABFunction(rtb_SPIControllerTransfer1_bx_0, 5.0,
    &Copy_of_PDUSTM32_B.Voltage_k);

  /* MATLABSystem: '<S3>/SPI Controller Transfer1' incorporates:
   *  Constant: '<S3>/Dummy Bits'
   */
  status = MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj_o.MW_SPI_HANDLE, 0U,
    1792U, MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 4U);
    MW_SPI_MasterWriteRead_Databits(Copy_of_PDUSTM32_DW.obj_o.MW_SPI_HANDLE,
      &Copy_of_PDUSTM32_ConstP.pooled9[0], &rtb_SPIControllerTransfer1_bx_0[0],
      0, 2U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 4U);
  }

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S3>/VA'
   *  MATLABSystem: '<S3>/SPI Controller Transfer1'
   */
  Copy_of_PDUSTM32_MATLABFunction(rtb_SPIControllerTransfer1_bx_0, 5.0,
    &Copy_of_PDUSTM32_B.Voltage_g);

  /* MATLABSystem: '<S4>/SPI Controller Transfer1' incorporates:
   *  Constant: '<S4>/Dummy Bits'
   */
  status = MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj_e.MW_SPI_HANDLE, 0U,
    1792U, MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOB;
    LL_GPIO_ResetOutputPin(portNameLoc, 1024U);
    MW_SPI_MasterWriteRead_Databits(Copy_of_PDUSTM32_DW.obj_e.MW_SPI_HANDLE,
      &Copy_of_PDUSTM32_ConstP.pooled9[0], &rtb_SPIControllerTransfer1_bx_0[0],
      0, 2U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 1024U);
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S4>/VA'
   *  MATLABSystem: '<S4>/SPI Controller Transfer1'
   */
  Copy_of_PDUSTM32_MATLABFunction(rtb_SPIControllerTransfer1_bx_0, 5.0,
    &Copy_of_PDUSTM32_B.Voltage);

  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  Copy_of_PDUSTM32_B.CANPack1.ID = 105U;
  Copy_of_PDUSTM32_B.CANPack1.Length = 8U;
  Copy_of_PDUSTM32_B.CANPack1.Extended = 0U;
  Copy_of_PDUSTM32_B.CANPack1.Remote = 0;
  Copy_of_PDUSTM32_B.CANPack1.Data[0] = 0;
  Copy_of_PDUSTM32_B.CANPack1.Data[1] = 0;
  Copy_of_PDUSTM32_B.CANPack1.Data[2] = 0;
  Copy_of_PDUSTM32_B.CANPack1.Data[3] = 0;
  Copy_of_PDUSTM32_B.CANPack1.Data[4] = 0;
  Copy_of_PDUSTM32_B.CANPack1.Data[5] = 0;
  Copy_of_PDUSTM32_B.CANPack1.Data[6] = 0;
  Copy_of_PDUSTM32_B.CANPack1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.0012211
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = Copy_of_PDUSTM32_B.Voltage_a;

        /* no offset to apply */
        result = result * (1 / 0.0012211);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(4095)) {
          packedValue = (uint16_T) 4095;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack1.Data[0] =
              Copy_of_PDUSTM32_B.CANPack1.Data[0] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack1.Data[1] =
              Copy_of_PDUSTM32_B.CANPack1.Data[1] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.0012211
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = Copy_of_PDUSTM32_B.Voltage_k;

        /* no offset to apply */
        result = result * (1 / 0.0012211);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(4095)) {
          packedValue = (uint16_T) 4095;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack1.Data[2] =
              Copy_of_PDUSTM32_B.CANPack1.Data[2] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack1.Data[3] =
              Copy_of_PDUSTM32_B.CANPack1.Data[3] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.0012211
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = Copy_of_PDUSTM32_B.Voltage_g;

        /* no offset to apply */
        result = result * (1 / 0.0012211);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(4095)) {
          packedValue = (uint16_T) 4095;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack1.Data[4] =
              Copy_of_PDUSTM32_B.CANPack1.Data[4] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack1.Data[5] =
              Copy_of_PDUSTM32_B.CANPack1.Data[5] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 48
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.0012211
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = Copy_of_PDUSTM32_B.Voltage;

        /* no offset to apply */
        result = result * (1 / 0.0012211);

        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real_T)(4095)) {
          packedValue = (uint16_T) 4095;
        } else if (outValue < (real_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack1.Data[6] =
              Copy_of_PDUSTM32_B.CANPack1.Data[6] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack1.Data[7] =
              Copy_of_PDUSTM32_B.CANPack1.Data[7] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }
  }

  /* Outputs for Enabled SubSystem: '<S16>/Initialize' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  /* UnitDelay: '<S16>/Unit Delay3' */
  if (Copy_of_PDUSTM32_DW.UnitDelay3_DSTATE > 0.0) {
    /* SignalConversion generated from: '<S59>/MCPInitialized' */
    Copy_of_PDUSTM32_B.OutportBufferForMCPInitialized =
      Copy_of_PDUSTM32_ConstB.Constant;
  }

  /* End of UnitDelay: '<S16>/Unit Delay3' */
  /* End of Outputs for SubSystem: '<S16>/Initialize' */

  /* MATLAB Function: '<S7>/MATLAB Function2' incorporates:
   *  Constant: '<S7>/Offset'
   *  Constant: '<S7>/Period'
   *  Constant: '<S7>/RTS'
   */
  Copy_of_PDUSTM3_MATLABFunction2(Copy_of_PDUSTM32_B.CANPack1.ID,
    Copy_of_PDUSTM32_B.CANPack1.Length, Copy_of_PDUSTM32_B.CANPack1.Data, 129,
    5000, 0, Copy_of_PDUSTM32_B.OutportBufferForMCPInitialized,
    &rtb_VectorConcatenate2[0], &rtb_VectorConcatenate2[2], &status,
    &Copy_of_PDUSTM32_DW.sf_MATLABFunction2);

  /* Constant: '<S7>/TXBuffer' */
  rtb_VectorConcatenate2[1] = 49U;
  Copy_of__SPIControllerTransfer4(rtb_VectorConcatenate2,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer4);

  /* MATLABSystem: '<S30>/Analog to Digital Converter' */
  regularReadADCDMA(Copy_of_PDUSTM32_DW.obj_n.ADCHandle, ADC_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);
  for (i = 0; i < 7; i++) {
    /* Gain: '<Root>/Gain4' incorporates:
     *  MATLABSystem: '<S30>/Analog to Digital Converter'
     */
    Copy_of_PDUSTM32_B.Gain4[i] = 5.03547708E-5F * (real32_T)
      rtb_AnalogtoDigitalConverter_0[i];
  }

  /* S-Function (scanpack): '<Root>/CAN Pack2' */
  /* S-Function (scanpack): '<Root>/CAN Pack2' */
  Copy_of_PDUSTM32_B.CANPack2.ID = 5U;
  Copy_of_PDUSTM32_B.CANPack2.Length = 8U;
  Copy_of_PDUSTM32_B.CANPack2.Extended = 0U;
  Copy_of_PDUSTM32_B.CANPack2.Remote = 0;
  Copy_of_PDUSTM32_B.CANPack2.Data[0] = 0;
  Copy_of_PDUSTM32_B.CANPack2.Data[1] = 0;
  Copy_of_PDUSTM32_B.CANPack2.Data[2] = 0;
  Copy_of_PDUSTM32_B.CANPack2.Data[3] = 0;
  Copy_of_PDUSTM32_B.CANPack2.Data[4] = 0;
  Copy_of_PDUSTM32_B.CANPack2.Data[5] = 0;
  Copy_of_PDUSTM32_B.CANPack2.Data[6] = 0;
  Copy_of_PDUSTM32_B.CANPack2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 5.04E-5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = Copy_of_PDUSTM32_B.Gain4[0];

        /* no offset to apply */
        result = result * (1 / 5.04E-5F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack2.Data[0] =
              Copy_of_PDUSTM32_B.CANPack2.Data[0] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack2.Data[1] =
              Copy_of_PDUSTM32_B.CANPack2.Data[1] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 5.04E-5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = Copy_of_PDUSTM32_B.Gain4[1];

        /* no offset to apply */
        result = result * (1 / 5.04E-5F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack2.Data[2] =
              Copy_of_PDUSTM32_B.CANPack2.Data[2] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack2.Data[3] =
              Copy_of_PDUSTM32_B.CANPack2.Data[3] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 5.04E-5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = Copy_of_PDUSTM32_B.Gain4[2];

        /* no offset to apply */
        result = result * (1 / 5.04E-5F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack2.Data[4] =
              Copy_of_PDUSTM32_B.CANPack2.Data[4] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack2.Data[5] =
              Copy_of_PDUSTM32_B.CANPack2.Data[5] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 5.04E-5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = Copy_of_PDUSTM32_B.Gain4[3];

        /* no offset to apply */
        result = result * (1 / 5.04E-5F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack2.Data[6] =
              Copy_of_PDUSTM32_B.CANPack2.Data[6] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack2.Data[7] =
              Copy_of_PDUSTM32_B.CANPack2.Data[7] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLAB Function: '<S8>/MATLAB Function2' incorporates:
   *  Constant: '<S8>/Offset'
   *  Constant: '<S8>/Period'
   *  Constant: '<S8>/RTS'
   */
  Copy_of_PDUSTM3_MATLABFunction2(Copy_of_PDUSTM32_B.CANPack2.ID,
    Copy_of_PDUSTM32_B.CANPack2.Length, Copy_of_PDUSTM32_B.CANPack2.Data, 129,
    250, 2, Copy_of_PDUSTM32_B.OutportBufferForMCPInitialized,
    &rtb_VectorConcatenate2_i[0], &rtb_VectorConcatenate2_i[2], &rtb_RTSByte,
    &Copy_of_PDUSTM32_DW.sf_MATLABFunction2_o);

  /* Constant: '<S8>/TXBuffer' */
  rtb_VectorConcatenate2_i[1] = 49U;
  Copy_of__SPIControllerTransfer4(rtb_VectorConcatenate2_i,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer4_p);

  /* Gain: '<Root>/Gain' */
  Copy_of_PDUSTM32_B.Gain = 9.183F * Copy_of_PDUSTM32_B.Gain4[6];

  /* S-Function (scanpack): '<Root>/CAN Pack3' */
  /* S-Function (scanpack): '<Root>/CAN Pack3' */
  Copy_of_PDUSTM32_B.CANPack3.ID = 66U;
  Copy_of_PDUSTM32_B.CANPack3.Length = 6U;
  Copy_of_PDUSTM32_B.CANPack3.Extended = 0U;
  Copy_of_PDUSTM32_B.CANPack3.Remote = 0;
  Copy_of_PDUSTM32_B.CANPack3.Data[0] = 0;
  Copy_of_PDUSTM32_B.CANPack3.Data[1] = 0;
  Copy_of_PDUSTM32_B.CANPack3.Data[2] = 0;
  Copy_of_PDUSTM32_B.CANPack3.Data[3] = 0;
  Copy_of_PDUSTM32_B.CANPack3.Data[4] = 0;
  Copy_of_PDUSTM32_B.CANPack3.Data[5] = 0;
  Copy_of_PDUSTM32_B.CANPack3.Data[6] = 0;
  Copy_of_PDUSTM32_B.CANPack3.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 5.04E-5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = Copy_of_PDUSTM32_B.Gain4[4];

        /* no offset to apply */
        result = result * (1 / 5.04E-5F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack3.Data[0] =
              Copy_of_PDUSTM32_B.CANPack3.Data[0] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack3.Data[1] =
              Copy_of_PDUSTM32_B.CANPack3.Data[1] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 5.04E-5
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = Copy_of_PDUSTM32_B.Gain4[5];

        /* no offset to apply */
        result = result * (1 / 5.04E-5F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack3.Data[2] =
              Copy_of_PDUSTM32_B.CANPack3.Data[2] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack3.Data[3] =
              Copy_of_PDUSTM32_B.CANPack3.Data[3] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.00046327
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = Copy_of_PDUSTM32_B.Gain;

        /* no offset to apply */
        result = result * (1 / 0.00046327F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint16_T packedValue;
        if (outValue > (real32_T)(65535)) {
          packedValue = (uint16_T) 65535;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint16_T) 0;
        } else {
          packedValue = (uint16_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack3.Data[4] =
              Copy_of_PDUSTM32_B.CANPack3.Data[4] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack3.Data[5] =
              Copy_of_PDUSTM32_B.CANPack3.Data[5] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLAB Function: '<S9>/MATLAB Function2' incorporates:
   *  Constant: '<S9>/Offset'
   *  Constant: '<S9>/Period'
   *  Constant: '<S9>/RTS'
   */
  Copy_of_PDUSTM3_MATLABFunction2(Copy_of_PDUSTM32_B.CANPack3.ID,
    Copy_of_PDUSTM32_B.CANPack3.Length, Copy_of_PDUSTM32_B.CANPack3.Data, 129,
    250, 8, Copy_of_PDUSTM32_B.OutportBufferForMCPInitialized,
    &rtb_VectorConcatenate2_fg[0], &rtb_VectorConcatenate2_fg[2], &rtb_FixPtSum1,
    &Copy_of_PDUSTM32_DW.sf_MATLABFunction2_n);

  /* Constant: '<S9>/TXBuffer' */
  rtb_VectorConcatenate2_fg[1] = 49U;
  Copy_of__SPIControllerTransfer4(rtb_VectorConcatenate2_fg,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer4_pn);
  Copy_of__SPIControllerTransfer5(rtb_FixPtSum1,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer5_pn);

  /* S-Function (scanpack): '<Root>/CAN Pack5' */
  /* S-Function (scanpack): '<Root>/CAN Pack5' */
  Copy_of_PDUSTM32_B.CANPack5.ID = 1328U;
  Copy_of_PDUSTM32_B.CANPack5.Length = 8U;
  Copy_of_PDUSTM32_B.CANPack5.Extended = 0U;
  Copy_of_PDUSTM32_B.CANPack5.Remote = 0;
  Copy_of_PDUSTM32_B.CANPack5.Data[0] = 0;
  Copy_of_PDUSTM32_B.CANPack5.Data[1] = 0;
  Copy_of_PDUSTM32_B.CANPack5.Data[2] = 0;
  Copy_of_PDUSTM32_B.CANPack5.Data[3] = 0;
  Copy_of_PDUSTM32_B.CANPack5.Data[4] = 0;
  Copy_of_PDUSTM32_B.CANPack5.Data[5] = 0;
  Copy_of_PDUSTM32_B.CANPack5.Data[6] = 0;
  Copy_of_PDUSTM32_B.CANPack5.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 8
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 0.1216
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = Copy_of_PDUSTM32_B.Gain;

        /* no offset to apply */
        result = result * (1 / 0.1216F);

        /* round to closest integer value for integer CAN signal */
        outValue = roundf(result);
      }

      {
        uint8_T packedValue;
        if (outValue > (real32_T)(255)) {
          packedValue = (uint8_T) 255;
        } else if (outValue < (real32_T)(0)) {
          packedValue = (uint8_T) 0;
        } else {
          packedValue = (uint8_T) (outValue);
        }

        {
          {
            Copy_of_PDUSTM32_B.CANPack5.Data[0] =
              Copy_of_PDUSTM32_B.CANPack5.Data[0] | (uint8_T)(packedValue);
          }
        }
      }
    }
  }

  /* MATLAB Function: '<S9>/MATLAB Function1' incorporates:
   *  Constant: '<S9>/Offset1'
   *  Constant: '<S9>/Period1'
   *  Constant: '<S9>/RTS1'
   */
  Copy_of_PDUSTM3_MATLABFunction2(Copy_of_PDUSTM32_B.CANPack5.ID,
    Copy_of_PDUSTM32_B.CANPack5.Length, Copy_of_PDUSTM32_B.CANPack5.Data, 129,
    250, 8, Copy_of_PDUSTM32_B.OutportBufferForMCPInitialized,
    &rtb_VectorConcatenate1[0], &rtb_VectorConcatenate1[2], &rtb_FixPtSum1,
    &Copy_of_PDUSTM32_DW.sf_MATLABFunction1);

  /* Constant: '<S9>/TXBuffer1' */
  rtb_VectorConcatenate1[1] = 49U;
  Copy_of__SPIControllerTransfer4(rtb_VectorConcatenate1,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer1_pnae);
  Copy_of__SPIControllerTransfer5(rtb_FixPtSum1,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer2);

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  Copy_of_PDUSTM3_DigitalPortRead(&Copy_of_PDUSTM32_B.DigitalPortRead_m);

  /* Outputs for Enabled SubSystem: '<S31>/Enabled Subsystem' */
  /* Logic: '<S31>/NOT5' */
  Copy_of_PDUSTM_EnabledSubsystem
    (!Copy_of_PDUSTM32_B.DigitalPortRead_m.DigitalPortRead,
     &Copy_of_PDUSTM32_B.Message_o, &Copy_of_PDUSTM32_DW.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S31>/Enabled Subsystem' */

  /* S-Function (scanunpack): '<S6>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<S6>/CAN Unpack' */
    if ((7 == Copy_of_PDUSTM32_B.Message_o.Length) &&
        (Copy_of_PDUSTM32_B.Message_o.ID != INVALID_CAN_ID) ) {
      if ((1539 == Copy_of_PDUSTM32_B.Message_o.ID) && (0U ==
           Copy_of_PDUSTM32_B.Message_o.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 24
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (Copy_of_PDUSTM32_B.Message_o.Data[3]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real_T) (unpackedValue);
            }

            {
              real_T result = (real_T) outValue;
              Copy_of_PDUSTM32_B.CANUnpack_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 0
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (Copy_of_PDUSTM32_B.Message_o.Data[0]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real_T) (unpackedValue);
            }

            {
              real_T result = (real_T) outValue;
              Copy_of_PDUSTM32_B.CANUnpack_o2 = result;
            }
          }

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 32
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (Copy_of_PDUSTM32_B.Message_o.Data[4]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real_T) (unpackedValue);
            }

            {
              real_T result = (real_T) outValue;
              Copy_of_PDUSTM32_B.CANUnpack_o3 = result;
            }
          }

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 8
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (Copy_of_PDUSTM32_B.Message_o.Data[1]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real_T) (unpackedValue);
            }

            {
              real_T result = (real_T) outValue;
              Copy_of_PDUSTM32_B.CANUnpack_o4 = result;
            }
          }

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 16
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (Copy_of_PDUSTM32_B.Message_o.Data[2]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real_T) (unpackedValue);
            }

            {
              real_T result = (real_T) outValue;
              Copy_of_PDUSTM32_B.CANUnpack_o5 = result;
            }
          }

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 40
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (Copy_of_PDUSTM32_B.Message_o.Data[5]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real_T) (unpackedValue);
            }

            {
              real_T result = (real_T) outValue;
              Copy_of_PDUSTM32_B.CANUnpack_o6 = result;
            }
          }

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 48
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)
                    (Copy_of_PDUSTM32_B.Message_o.Data[6]) & (uint8_T)(0x1U));
                }

                unpackedValue = tempValue;
              }

              outValue = (real_T) (unpackedValue);
            }

            {
              real_T result = (real_T) outValue;
              Copy_of_PDUSTM32_B.CANUnpack_o7 = result;
            }
          }
        }
      }
    }
  }

  Copy_of_PDUSTM3_DigitalPortRead(&Copy_of_PDUSTM32_B.DigitalPortRead_k);

  /* Outputs for Enabled SubSystem: '<S32>/Enabled Subsystem' */
  /* Logic: '<S32>/NOT5' */
  Copy_of_PDUSTM_EnabledSubsystem
    (!Copy_of_PDUSTM32_B.DigitalPortRead_k.DigitalPortRead,
     &Copy_of_PDUSTM32_B.Message, &Copy_of_PDUSTM32_DW.EnabledSubsystem_l);

  /* End of Outputs for SubSystem: '<S32>/Enabled Subsystem' */

  /* S-Function (scanunpack): '<S6>/CAN Unpack1' */
  {
    /* S-Function (scanunpack): '<S6>/CAN Unpack1' */
    if ((6 == Copy_of_PDUSTM32_B.Message.Length) &&
        (Copy_of_PDUSTM32_B.Message.ID != INVALID_CAN_ID) ) {
      if ((419 == Copy_of_PDUSTM32_B.Message.ID) && (0U ==
           Copy_of_PDUSTM32_B.Message.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 32
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 33
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 2 ------------------
           *  startBit                = 34
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 3 ------------------
           *  startBit                = 35
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 4 ------------------
           *  startBit                = 36
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 5 ------------------
           *  startBit                = 37
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 6 ------------------
           *  startBit                = 31
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 7 ------------------
           *  startBit                = 1
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real_T outValue = 0;

            {
              uint8_T unpackedValue = 0;

              {
                uint8_T tempValue = (uint8_T) (0);

                {
                  tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                    (Copy_of_PDUSTM32_B.Message.Data[0]) & (uint8_T)(0x2U)) >> 1);
                }

                unpackedValue = tempValue;
              }

              outValue = (real_T) (unpackedValue);
            }

            {
              real_T result = (real_T) outValue;
              Copy_of_PDUSTM32_B.CANUnpack1_o8 = result;
            }
          }

          /* --------------- START Unpacking signal 8 ------------------
           *  startBit                = 5
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 9 ------------------
           *  startBit                = 6
           *  length                  = 2
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -1.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 10 ------------------
           *  startBit                = 13
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 11 ------------------
           *  startBit                = 14
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 12 ------------------
           *  startBit                = 15
           *  length                  = 2
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -1.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 13 ------------------
           *  startBit                = 17
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 14 ------------------
           *  startBit                = 18
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 15 ------------------
           *  startBit                = 19
           *  length                  = 2
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -1.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 16 ------------------
           *  startBit                = 9
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 17 ------------------
           *  startBit                = 10
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 18 ------------------
           *  startBit                = 11
           *  length                  = 2
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -1.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 19 ------------------
           *  startBit                = 0
           *  length                  = 1
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 20 ------------------
           *  startBit                = 2
           *  length                  = 2
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = -1.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 21 ------------------
           *  startBit                = 44
           *  length                  = 4
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 22 ------------------
           *  startBit                = 38
           *  length                  = 6
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */

          /* --------------- START Unpacking signal 23 ------------------
           *  startBit                = 21
           *  length                  = 10
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = UNSIGNED
           *  factor                  = 0.1
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          /*
           * Signal is not connected or connected to terminator.
           * No unpacking code generated.
           */
        }
      }
    }
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */

  /* S-Function (scanpack): '<Root>/CAN Pack4' */
  /* S-Function (scanpack): '<Root>/CAN Pack4' */
  Copy_of_PDUSTM32_B.CANPack4.ID = 0U;
  Copy_of_PDUSTM32_B.CANPack4.Length = 8U;
  Copy_of_PDUSTM32_B.CANPack4.Extended = 0U;
  Copy_of_PDUSTM32_B.CANPack4.Remote = 0;
  Copy_of_PDUSTM32_B.CANPack4.Data[0] = 0;
  Copy_of_PDUSTM32_B.CANPack4.Data[1] = 0;
  Copy_of_PDUSTM32_B.CANPack4.Data[2] = 0;
  Copy_of_PDUSTM32_B.CANPack4.Data[3] = 0;
  Copy_of_PDUSTM32_B.CANPack4.Data[4] = 0;
  Copy_of_PDUSTM32_B.CANPack4.Data[5] = 0;
  Copy_of_PDUSTM32_B.CANPack4.Data[6] = 0;
  Copy_of_PDUSTM32_B.CANPack4.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (Copy_of_PDUSTM32_B.Message_o.ID);

        /* no scaling required */
        packingValue = result;
      }

      {
        int16_T packedValue;
        int32_T scaledValue;
        if (packingValue > 2147483647U) {
          scaledValue = 2147483647;
        } else {
          scaledValue = (int32_T) packingValue;
        }

        if (scaledValue > (int32_T) (32767)) {
          packedValue = 32767;
        } else if (scaledValue < (int32_T)((-(32767)-1))) {
          packedValue = (-(32767)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            Copy_of_PDUSTM32_B.CANPack4.Data[0] =
              Copy_of_PDUSTM32_B.CANPack4.Data[0] | (uint8_T)((uint16_T)
              (tempValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack4.Data[1] =
              Copy_of_PDUSTM32_B.CANPack4.Data[1] | (uint8_T)((uint16_T)
              ((uint16_T)(tempValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = Copy_of_PDUSTM32_B.Message_o.Length;

        /* no scaling required */
        /* round to closest integer value for integer CAN signal */
        outValue = round(result);
      }

      {
        int16_T packedValue;
        int32_T scaledValue;
        if (outValue > 2147483647.0) {
          scaledValue = 2147483647;
        } else if (outValue < -2147483648.0) {
          scaledValue = -2147483647 - 1;
        } else {
          scaledValue = (int32_T) outValue;
        }

        if (scaledValue > (int32_T) (32767)) {
          packedValue = 32767;
        } else if (scaledValue < (int32_T)((-(32767)-1))) {
          packedValue = (-(32767)-1);
        } else {
          packedValue = (int16_T) (scaledValue);
        }

        {
          uint16_T* tempValuePtr = (uint16_T*)&packedValue;
          uint16_T tempValue = *tempValuePtr;

          {
            Copy_of_PDUSTM32_B.CANPack4.Data[2] =
              Copy_of_PDUSTM32_B.CANPack4.Data[2] | (uint8_T)((uint16_T)
              (tempValue & (uint16_T)0xFFU));
            Copy_of_PDUSTM32_B.CANPack4.Data[3] =
              Copy_of_PDUSTM32_B.CANPack4.Data[3] | (uint8_T)((uint16_T)
              ((uint16_T)(tempValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = SIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
  }

  /* MATLAB Function: '<S9>/MATLAB Function3' incorporates:
   *  Constant: '<S9>/Offset2'
   *  Constant: '<S9>/Period2'
   *  Constant: '<S9>/RTS2'
   */
  Copy_of_PDUSTM3_MATLABFunction2(Copy_of_PDUSTM32_B.CANPack4.ID,
    Copy_of_PDUSTM32_B.CANPack4.Length, Copy_of_PDUSTM32_B.CANPack4.Data, 129,
    250, 8, Copy_of_PDUSTM32_B.OutportBufferForMCPInitialized,
    &rtb_VectorConcatenate3[0], &rtb_VectorConcatenate3[2], &rtb_FixPtSum1,
    &Copy_of_PDUSTM32_DW.sf_MATLABFunction3);

  /* Constant: '<S9>/TXBuffer2' */
  rtb_VectorConcatenate3[1] = 49U;
  Copy_of__SPIControllerTransfer4(rtb_VectorConcatenate3,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer3);
  Copy_of__SPIControllerTransfer5(rtb_FixPtSum1,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer6);

  /* MATLABSystem: '<S62>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   */
  portNameLoc = GPIOB;

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  if (Copy_of_PDUSTM32_B.CANUnpack_o2 != 0.0) {
    i = 32;
  } else {
    i = 0;
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 32U);

  /* End of MATLABSystem: '<S62>/Digital Port Write' */

  /* MATLABSystem: '<S64>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion4'
   */
  portNameLoc = GPIOC;

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  if (Copy_of_PDUSTM32_B.CANUnpack_o5 != 0.0) {
    i = 4;
  } else {
    i = 0;
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4U);

  /* End of MATLABSystem: '<S64>/Digital Port Write' */

  /* MATLABSystem: '<S66>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion5'
   */
  portNameLoc = GPIOA;

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  if (Copy_of_PDUSTM32_B.CANUnpack_o6 != 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S66>/Digital Port Write' */

  /* MATLABSystem: '<S68>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   */
  portNameLoc = GPIOB;

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  if (Copy_of_PDUSTM32_B.CANUnpack_o3 != 0.0) {
    i = 128;
  } else {
    i = 0;
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 128U);

  /* End of MATLABSystem: '<S68>/Digital Port Write' */

  /* MATLABSystem: '<S70>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion3'
   */
  portNameLoc = GPIOB;

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  if (Copy_of_PDUSTM32_B.CANUnpack_o4 != 0.0) {
    i = 512;
  } else {
    i = 0;
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 512U);

  /* End of MATLABSystem: '<S70>/Digital Port Write' */

  /* MATLABSystem: '<S72>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  portNameLoc = GPIOB;

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  if (Copy_of_PDUSTM32_B.CANUnpack_o1 != 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S72>/Digital Port Write' */

  /* MATLABSystem: '<S74>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion7'
   */
  portNameLoc = GPIOB;

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  if (Copy_of_PDUSTM32_B.CANUnpack1_o8 != 0.0) {
    i = 8192;
  } else {
    i = 0;
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 8192U);

  /* End of MATLABSystem: '<S74>/Digital Port Write' */

  /* MATLABSystem: '<S76>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion6'
   */
  portNameLoc = GPIOB;

  /* Outputs for Atomic SubSystem: '<Root>/CAN Rx' */
  if (Copy_of_PDUSTM32_B.CANUnpack_o7 != 0.0) {
    i = 16;
  } else {
    i = 0;
  }

  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 16U);

  /* End of MATLABSystem: '<S76>/Digital Port Write' */
  Copy_of__SPIControllerTransfer5(rtb_RTSByte,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer5_p);
  Copy_of__SPIControllerTransfer5(status,
    &Copy_of_PDUSTM32_DW.SPIControllerTransfer5);

  /* MATLABSystem: '<S53>/Digital Port Write' incorporates:
   *  Constant: '<S10>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   *  UnitDelay: '<S11>/Output'
   */
  portNameLoc = GPIOC;
  if (Copy_of_PDUSTM32_DW.Output_DSTATE >= 125) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 2048U);

  /* End of MATLABSystem: '<S53>/Digital Port Write' */

  /* Switch: '<S49>/FixPt Switch' incorporates:
   *  Constant: '<S48>/FixPt Constant'
   *  Constant: '<S49>/Constant'
   *  Sum: '<S48>/FixPt Sum1'
   *  UnitDelay: '<S11>/Output'
   */
  if ((uint8_T)(Copy_of_PDUSTM32_DW.Output_DSTATE + 1) > 250) {
    Copy_of_PDUSTM32_DW.Output_DSTATE = 0U;
  } else {
    Copy_of_PDUSTM32_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S49>/FixPt Switch' */

  /* MATLABSystem: '<S57>/Digital Port Write' */
  portNameLoc = GPIOA;
  LL_GPIO_SetOutputPin(portNameLoc, 2U);
  LL_GPIO_ResetOutputPin(portNameLoc, 0U);

  /* UnitDelay: '<S16>/Unit Delay1' */
  rtb_UnitDelay1 = Copy_of_PDUSTM32_DW.UnitDelay1_DSTATE;

  /* Step: '<S16>/Step2' incorporates:
   *  UnitDelay: '<S16>/Unit Delay1'
   */
  UnitDelay1_DSTATE_tmp = !(((Copy_of_PDUSTM32_M->Timing.clockTick0) * 0.001) <
    1.0);
  Copy_of_PDUSTM32_DW.UnitDelay1_DSTATE = UnitDelay1_DSTATE_tmp;

  /* Outputs for Enabled SubSystem: '<S16>/MCPInit' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  /* RelationalOperator: '<S58>/FixPt Relational Operator' incorporates:
   *  Constant: '<S60>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   *  Constant: '<S60>/CANINTE'
   *  Constant: '<S60>/CNF2'
   *  Constant: '<S60>/CNF3'
   *  Constant: '<S60>/CNF4'
   *  Constant: '<S60>/Clear flags'
   *  Constant: '<S60>/Set acceptance filters'
   *  UnitDelay: '<S58>/Delay Input1'
   *
   * Block description for '<S58>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((real_T)UnitDelay1_DSTATE_tmp > Copy_of_PDUSTM32_DW.DelayInput1_DSTATE) {
    /* MATLABSystem: '<S60>/SPI Controller Transfer' incorporates:
     *  Constant: '<S60>/Enter Configuration Mode'
     */
    status = MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj.MW_SPI_HANDLE, 0U,
      1792U, MW_SPI_MODE_2);
    if (status == 0) {
      portNameLoc = GPIOB;
      LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
      MW_SPI_MasterWriteRead_Databits(Copy_of_PDUSTM32_DW.obj.MW_SPI_HANDLE,
        &Copy_of_PDUSTM32_ConstP.EnterConfigurationMode_Value, &status, 0, 1U, 1,
        10U);
      LL_GPIO_SetOutputPin(portNameLoc, 16384U);
    }

    /* End of MATLABSystem: '<S60>/SPI Controller Transfer' */
    Copy_of__SPIControllerTransfer1(Copy_of_PDUSTM32_ConstP.CNF4_Value,
      &Copy_of_PDUSTM32_DW.SPIControllerTransfer1_pnaev);
    Copy_of__SPIControllerTransfer1(Copy_of_PDUSTM32_ConstP.CNF2_Value,
      &Copy_of_PDUSTM32_DW.SPIControllerTransfer2_p);
    Copy_of__SPIControllerTransfer1(Copy_of_PDUSTM32_ConstP.CNF3_Value,
      &Copy_of_PDUSTM32_DW.SPIControllerTransfer3_p);
    Copy_o_SPIControllerTransfer5_p(Copy_of_PDUSTM32_ConstP.CANINTE_Value,
      &Copy_of_PDUSTM32_DW.SPIControllerTransfer5_pna);
    Copy_of__SPIControllerTransfer1
      (Copy_of_PDUSTM32_ConstP.Setacceptancefilters_Value,
       &Copy_of_PDUSTM32_DW.SPIControllerTransfer6_p);
    Copy_o_SPIControllerTransfer5_p(Copy_of_PDUSTM32_ConstP.Clearflags_Value,
      &Copy_of_PDUSTM32_DW.SPIControllerTransfer7);
    Copy_of__SPIControllerTransfer1
      (Copy_of_PDUSTM32_ConstP.u00normalmode0dontabortpendingt,
       &Copy_of_PDUSTM32_DW.SPIControllerTransfer4_pna);
  }

  /* End of RelationalOperator: '<S58>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<S16>/MCPInit' */

  /* MATLABSystem: '<S51>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S55>/Digital Port Write' incorporates:
   *  Logic: '<Root>/NOT4'
   *  MATLABSystem: '<S51>/Digital Port Read'
   * */
  portNameLoc = GPIOC;
  if ((pinReadLoc & 4U) == 0U) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S55>/Digital Port Write' */

  /* Update for UnitDelay: '<S16>/Unit Delay3' incorporates:
   *  UnitDelay: '<S16>/Unit Delay2'
   */
  Copy_of_PDUSTM32_DW.UnitDelay3_DSTATE = Copy_of_PDUSTM32_DW.UnitDelay2_DSTATE;

  /* Update for UnitDelay: '<S16>/Unit Delay2' */
  Copy_of_PDUSTM32_DW.UnitDelay2_DSTATE = rtb_UnitDelay1;

  /* Update for UnitDelay: '<S58>/Delay Input1'
   *
   * Block description for '<S58>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Copy_of_PDUSTM32_DW.DelayInput1_DSTATE = UnitDelay1_DSTATE_tmp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Copy_of_PDUSTM32_M->Timing.clockTick0++;
}

/* Model initialize function */
void Copy_of_PDUSTM32_initialize(void)
{
  {
    STM32_SPI_ModuleStruct_T b;
    STM32_SPI_ModuleStruct_T b_0;
    STM32_SPI_ModuleStruct_T b_1;
    STM32_SPI_ModuleStruct_T b_2;
    STM32_SPI_ModuleStruct_T b_3;

    /* SystemInitialize for Enabled SubSystem: '<S16>/Initialize' */
    /* SystemInitialize for SignalConversion generated from: '<S59>/MCPInitialized' */
    Copy_of_PDUSTM32_B.OutportBufferForMCPInitialized =
      Copy_of_PDUSTM32_ConstB.Constant;

    /* End of SystemInitialize for SubSystem: '<S16>/Initialize' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/CAN Rx' */
    /* Start for S-Function (scanunpack): '<S6>/CAN Unpack' */

    /*-----------S-Function Block: <S6>/CAN Unpack -----------------*/

    /* Start for S-Function (scanunpack): '<S6>/CAN Unpack1' */

    /*-----------S-Function Block: <S6>/CAN Unpack1 -----------------*/

    /* SystemInitialize for Enabled SubSystem: '<S31>/Enabled Subsystem' */
    Copy_of_P_EnabledSubsystem_Init(&Copy_of_PDUSTM32_DW.EnabledSubsystem);

    /* End of SystemInitialize for SubSystem: '<S31>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S32>/Enabled Subsystem' */
    Copy_of_P_EnabledSubsystem_Init(&Copy_of_PDUSTM32_DW.EnabledSubsystem_l);

    /* End of SystemInitialize for SubSystem: '<S32>/Enabled Subsystem' */
    Copy_of_PD_DigitalPortRead_Init(&Copy_of_PDUSTM32_DW.DigitalPortRead_m);
    Copy_of_PD_DigitalPortRead_Init(&Copy_of_PDUSTM32_DW.DigitalPortRead_k);

    /* End of SystemInitialize for SubSystem: '<Root>/CAN Rx' */

    /* SystemInitialize for Enabled SubSystem: '<S16>/MCPInit' */
    /* Start for MATLABSystem: '<S60>/SPI Controller Transfer' */
    Copy_of_PDUSTM32_DW.obj.matlabCodegenIsDeleted = false;
    Copy_of_PDUSTM32_DW.obj.isInitialized = 1;
    b_3.PeripheralPtr = SPI1;
    Copy_of_PDUSTM32_DW.obj.MW_SPI_HANDLE = SPI_STM32_Init(&b_3);
    MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    Copy_of_PDUSTM32_DW.obj.isSetupComplete = true;
    Cop_SPIControllerTransfer1_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer1_pnaev);
    Cop_SPIControllerTransfer1_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer2_p);
    Cop_SPIControllerTransfer1_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer3_p);
    C_SPIControllerTransfer5_l_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer5_pna);
    Cop_SPIControllerTransfer1_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer6_p);
    C_SPIControllerTransfer5_l_Init(&Copy_of_PDUSTM32_DW.SPIControllerTransfer7);
    Cop_SPIControllerTransfer1_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer4_pna);

    /* End of SystemInitialize for SubSystem: '<S16>/MCPInit' */

    /* Start for MATLABSystem: '<S1>/SPI Controller Transfer1' */
    Copy_of_PDUSTM32_DW.obj_l.matlabCodegenIsDeleted = false;
    Copy_of_PDUSTM32_DW.obj_l.isInitialized = 1;
    b.PeripheralPtr = SPI1;
    Copy_of_PDUSTM32_DW.obj_l.MW_SPI_HANDLE = SPI_STM32_Init(&b);
    MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj_l.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    Copy_of_PDUSTM32_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/SPI Controller Transfer1' */
    Copy_of_PDUSTM32_DW.obj_d.matlabCodegenIsDeleted = false;
    Copy_of_PDUSTM32_DW.obj_d.isInitialized = 1;
    b_0.PeripheralPtr = SPI1;
    Copy_of_PDUSTM32_DW.obj_d.MW_SPI_HANDLE = SPI_STM32_Init(&b_0);
    MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj_d.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    Copy_of_PDUSTM32_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/SPI Controller Transfer1' */
    Copy_of_PDUSTM32_DW.obj_o.matlabCodegenIsDeleted = false;
    Copy_of_PDUSTM32_DW.obj_o.isInitialized = 1;
    b_1.PeripheralPtr = SPI1;
    Copy_of_PDUSTM32_DW.obj_o.MW_SPI_HANDLE = SPI_STM32_Init(&b_1);
    MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj_o.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    Copy_of_PDUSTM32_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/SPI Controller Transfer1' */
    Copy_of_PDUSTM32_DW.obj_e.matlabCodegenIsDeleted = false;
    Copy_of_PDUSTM32_DW.obj_e.isInitialized = 1;
    b_2.PeripheralPtr = SPI1;
    Copy_of_PDUSTM32_DW.obj_e.MW_SPI_HANDLE = SPI_STM32_Init(&b_2);
    MW_STM32_SPI_SetFormat(Copy_of_PDUSTM32_DW.obj_e.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    Copy_of_PDUSTM32_DW.obj_e.isSetupComplete = true;
    Cop_SPIControllerTransfer4_Init(&Copy_of_PDUSTM32_DW.SPIControllerTransfer4);

    /* Start for MATLABSystem: '<S30>/Analog to Digital Converter' */
    Copy_of_PDUSTM32_DW.obj_n.isInitialized = 0;
    Copy_of_PDUSTM32_DW.obj_n.matlabCodegenIsDeleted = false;
    Copy_of_PDUSTM_SystemCore_setup(&Copy_of_PDUSTM32_DW.obj_n);
    Cop_SPIControllerTransfer4_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer4_p);
    Cop_SPIControllerTransfer4_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer4_pn);
    Cop_SPIControllerTransfer5_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer5_pn);
    Cop_SPIControllerTransfer4_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer1_pnae);
    Cop_SPIControllerTransfer5_Init(&Copy_of_PDUSTM32_DW.SPIControllerTransfer2);
    Cop_SPIControllerTransfer4_Init(&Copy_of_PDUSTM32_DW.SPIControllerTransfer3);
    Cop_SPIControllerTransfer5_Init(&Copy_of_PDUSTM32_DW.SPIControllerTransfer6);
    Cop_SPIControllerTransfer5_Init
      (&Copy_of_PDUSTM32_DW.SPIControllerTransfer5_p);
    Cop_SPIControllerTransfer5_Init(&Copy_of_PDUSTM32_DW.SPIControllerTransfer5);
  }

  /* user code (Initialize function Body) */
  LL_TIM_EnableCounter(TIM2);
}

/* Model terminate function */
void Copy_of_PDUSTM32_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S1>/SPI Controller Transfer1' */
  if (!Copy_of_PDUSTM32_DW.obj_l.matlabCodegenIsDeleted) {
    Copy_of_PDUSTM32_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Copy_of_PDUSTM32_DW.obj_l.isInitialized == 1) &&
        Copy_of_PDUSTM32_DW.obj_l.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(Copy_of_PDUSTM32_DW.obj_l.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 0U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/SPI Controller Transfer1' */

  /* Terminate for MATLABSystem: '<S2>/SPI Controller Transfer1' */
  if (!Copy_of_PDUSTM32_DW.obj_d.matlabCodegenIsDeleted) {
    Copy_of_PDUSTM32_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Copy_of_PDUSTM32_DW.obj_d.isInitialized == 1) &&
        Copy_of_PDUSTM32_DW.obj_d.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(Copy_of_PDUSTM32_DW.obj_d.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 1U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/SPI Controller Transfer1' */

  /* Terminate for MATLABSystem: '<S3>/SPI Controller Transfer1' */
  if (!Copy_of_PDUSTM32_DW.obj_o.matlabCodegenIsDeleted) {
    Copy_of_PDUSTM32_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Copy_of_PDUSTM32_DW.obj_o.isInitialized == 1) &&
        Copy_of_PDUSTM32_DW.obj_o.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(Copy_of_PDUSTM32_DW.obj_o.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 2U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/SPI Controller Transfer1' */

  /* Terminate for MATLABSystem: '<S4>/SPI Controller Transfer1' */
  if (!Copy_of_PDUSTM32_DW.obj_e.matlabCodegenIsDeleted) {
    Copy_of_PDUSTM32_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Copy_of_PDUSTM32_DW.obj_e.isInitialized == 1) &&
        Copy_of_PDUSTM32_DW.obj_e.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(Copy_of_PDUSTM32_DW.obj_e.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 10U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/SPI Controller Transfer1' */
  Cop_SPIControllerTransfer4_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer4);

  /* Terminate for MATLABSystem: '<S30>/Analog to Digital Converter' */
  if (!Copy_of_PDUSTM32_DW.obj_n.matlabCodegenIsDeleted) {
    Copy_of_PDUSTM32_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Copy_of_PDUSTM32_DW.obj_n.isInitialized == 1) &&
        Copy_of_PDUSTM32_DW.obj_n.isSetupComplete) {
      ADC_Handle_Deinit(Copy_of_PDUSTM32_DW.obj_n.ADCHandle,
                        ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S30>/Analog to Digital Converter' */
  Cop_SPIControllerTransfer4_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer4_p);
  Cop_SPIControllerTransfer4_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer4_pn);
  Cop_SPIControllerTransfer5_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer5_pn);
  Cop_SPIControllerTransfer4_Term
    (&Copy_of_PDUSTM32_DW.SPIControllerTransfer1_pnae);
  Cop_SPIControllerTransfer5_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer2);

  /* Terminate for Atomic SubSystem: '<Root>/CAN Rx' */
  /* Terminate for Enabled SubSystem: '<S31>/Enabled Subsystem' */
  Copy_of_P_EnabledSubsystem_Term(&Copy_of_PDUSTM32_DW.EnabledSubsystem);

  /* End of Terminate for SubSystem: '<S31>/Enabled Subsystem' */

  /* Terminate for Enabled SubSystem: '<S32>/Enabled Subsystem' */
  Copy_of_P_EnabledSubsystem_Term(&Copy_of_PDUSTM32_DW.EnabledSubsystem_l);

  /* End of Terminate for SubSystem: '<S32>/Enabled Subsystem' */
  /* End of Terminate for SubSystem: '<Root>/CAN Rx' */
  Cop_SPIControllerTransfer4_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer3);
  Cop_SPIControllerTransfer5_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer6);
  Cop_SPIControllerTransfer5_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer5_p);
  Cop_SPIControllerTransfer5_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer5);

  /* Terminate for Enabled SubSystem: '<S16>/MCPInit' */
  /* Terminate for MATLABSystem: '<S60>/SPI Controller Transfer' */
  if (!Copy_of_PDUSTM32_DW.obj.matlabCodegenIsDeleted) {
    Copy_of_PDUSTM32_DW.obj.matlabCodegenIsDeleted = true;
    if ((Copy_of_PDUSTM32_DW.obj.isInitialized == 1) &&
        Copy_of_PDUSTM32_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(Copy_of_PDUSTM32_DW.obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S60>/SPI Controller Transfer' */
  Cop_SPIControllerTransfer1_Term
    (&Copy_of_PDUSTM32_DW.SPIControllerTransfer1_pnaev);
  Cop_SPIControllerTransfer1_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer2_p);
  Cop_SPIControllerTransfer1_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer3_p);
  C_SPIControllerTransfer5_o_Term
    (&Copy_of_PDUSTM32_DW.SPIControllerTransfer5_pna);
  Cop_SPIControllerTransfer1_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer6_p);
  C_SPIControllerTransfer5_o_Term(&Copy_of_PDUSTM32_DW.SPIControllerTransfer7);
  Cop_SPIControllerTransfer1_Term
    (&Copy_of_PDUSTM32_DW.SPIControllerTransfer4_pna);

  /* End of Terminate for SubSystem: '<S16>/MCPInit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
