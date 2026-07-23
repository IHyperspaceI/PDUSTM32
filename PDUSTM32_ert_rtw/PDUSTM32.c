/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PDUSTM32.c
 *
 * Code generated for Simulink model 'PDUSTM32'.
 *
 * Model version                  : 13.172
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Jul 24 00:25:56 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PDUSTM32.h"
#include "rtwtypes.h"
#include "PDUSTM32_types.h"
#include "PDUSTM32_private.h"
#include "mw_stm32_spi_ll.h"
#include "stm_adc_ll.h"

/* Block signals (default storage) */
B_PDUSTM32_T PDUSTM32_B;

/* Block states (default storage) */
DW_PDUSTM32_T PDUSTM32_DW;

/* Real-time model */
static RT_MODEL_PDUSTM32_T PDUSTM32_M_;
RT_MODEL_PDUSTM32_T *const PDUSTM32_M = &PDUSTM32_M_;

/* Forward declaration for local functions */
static void PDUSTM32_SystemCore_setup(stm32cube_blocks_AnalogInputF_T *obj);

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function'
 *    '<S2>/MATLAB Function'
 *    '<S3>/MATLAB Function'
 *    '<S4>/MATLAB Function'
 */
void PDUSTM32_MATLABFunction(const uint8_T rtu_Counts[2], real_T rtu_VA, real_T *
  rty_Voltage)
{
  *rty_Voltage = (real_T)(((rtu_Counts[0] << 8) + rtu_Counts[1]) >> 1 != 0) *
    (rtu_VA / 4095.0);
}

/*
 * Output and update for atomic system:
 *    '<S6>/MATLAB Function'
 *    '<S6>/MATLAB Function1'
 */
void PDUSTM32_MATLABFunction_f(const uint8_T rtu_RxBytes[14], CAN_MESSAGE_def
  *rty_Message)
{
  int32_T i;
  rty_Message->ID = (uint32_T)rtu_RxBytes[1] << 3 | (uint32_T)rtu_RxBytes[2] >>
    5;
  rty_Message->Extended = false;
  rty_Message->Remote = false;
  rty_Message->Error = false;
  rty_Message->Length = rtu_RxBytes[5] & 15U;
  for (i = 0; i < 8; i++) {
    rty_Message->Data[i] = rtu_RxBytes[i + 6];
  }
}

/* System initialize for atomic system: */
void PDUS_SPIControllerTransfer_Init(DW_SPIControllerTransfer_PDUS_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S6>/SPI Controller Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PDUSTM32_SPIControllerTransfer(const uint8_T rtu_0[14],
  B_SPIControllerTransfer_PDUST_T *localB, DW_SPIControllerTransfer_PDUS_T
  *localDW)
{
  uint8_T status;

  /* MATLABSystem: '<S6>/SPI Controller Transfer' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOC;
    LL_GPIO_ResetOutputPin(portNameLoc, 16U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0],
      &localB->SPIControllerTransfer[0], 0, 14U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 16U);
  }

  /* End of MATLABSystem: '<S6>/SPI Controller Transfer' */
}

/* Termination for atomic system: */
void PDUS_SPIControllerTransfer_Term(DW_SPIControllerTransfer_PDUS_T *localDW)
{
  /* Terminate for MATLABSystem: '<S6>/SPI Controller Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/SPI Controller Transfer' */
}

/*
 * Output and update for atomic system:
 *    '<S7>/MATLAB Function'
 *    '<S7>/MATLAB Function1'
 *    '<S7>/MATLAB Function2'
 */
void PDUSTM32_MATLABFunction_o(uint32_T rtu_ID, uint8_T rtu_Length, const
  uint8_T rtu_Data[8], uint8_T rtu_RTS, uint16_T rtu_period, uint16_T rtu_offset,
  boolean_T rtu_MCPInitialized, uint8_T *rty_WriteInstruction, uint8_T
  rty_CANVector[13], uint8_T *rty_RTSByte, DW_MATLABFunction_PDUSTM32_c_T
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

      *rty_RTSByte = rtu_RTS;
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
void PD_SPIControllerTransfer_o_Init(DW_SPIControllerTransfer_PD_f_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S7>/SPI Controller Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PDUSTM3_SPIControllerTransfer_p(const uint8_T rtu_0[15],
  DW_SPIControllerTransfer_PD_f_T *localDW)
{
  uint8_T tmp[15];
  uint8_T status;

  /* MATLABSystem: '<S7>/SPI Controller Transfer' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 16U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0], &tmp
      [0], 0, 15U, 0, 1U);
    LL_GPIO_SetOutputPin(portNameLoc, 16U);
  }

  /* End of MATLABSystem: '<S7>/SPI Controller Transfer' */
}

/* Termination for atomic system: */
void PD_SPIControllerTransfer_i_Term(DW_SPIControllerTransfer_PD_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S7>/SPI Controller Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/SPI Controller Transfer' */
}

/* System initialize for atomic system: */
void PDU_SPIControllerTransfer1_Init(DW_SPIControllerTransfer1_PDU_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S31>/SPI Controller Transfer1' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PDUSTM32_SPIControllerTransfer1(const uint8_T rtu_0[3],
  DW_SPIControllerTransfer1_PDU_T *localDW)
{
  uint8_T tmp[3];
  uint8_T status;

  /* MATLABSystem: '<S31>/SPI Controller Transfer1' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 16U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0], &tmp
      [0], 0, 3U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 16U);
  }

  /* End of MATLABSystem: '<S31>/SPI Controller Transfer1' */
}

/* Termination for atomic system: */
void PDU_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_PDU_T *localDW)
{
  /* Terminate for MATLABSystem: '<S31>/SPI Controller Transfer1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/SPI Controller Transfer1' */
}

static void PDUSTM32_SystemCore_setup(stm32cube_blocks_AnalogInputF_T *obj)
{
  ADC_Type_T adcStructLoc;

  /* Start for MATLABSystem: '<S19>/Analog to Digital Converter' */
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
void PDUSTM32_step(void)
{
  GPIO_TypeDef * portNameLoc;
  int32_T i;
  int32_T tmp_0;
  int32_T tmp_1;
  int32_T tmp_2;
  int32_T tmp_3;
  int32_T tmp_4;
  uint32_T rtb_AnalogtoDigitalConverter_0[7];
  uint32_T pinReadLoc;
  uint8_T rtb_VectorConcatenate[15];
  uint8_T rtb_VectorConcatenate1[15];
  uint8_T rtb_VectorConcatenate2[15];
  uint8_T tmp[2];
  uint8_T status;
  boolean_T UnitDelay_DSTATE_tmp;

  /* MATLABSystem: '<S2>/SPI Controller Transfer1' incorporates:
   *  Constant: '<S2>/Dummy Bits'
   */
  status = MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_d.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 2U);
    MW_SPI_MasterWriteRead_Databits(PDUSTM32_DW.obj_d.MW_SPI_HANDLE,
      &PDUSTM32_ConstP.pooled7[0], &tmp[0], 0, 2U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 2U);
  }

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<S2>/VA'
   *  MATLABSystem: '<S2>/SPI Controller Transfer1'
   */
  PDUSTM32_MATLABFunction(tmp, 5.0, &PDUSTM32_B.Voltage_k);

  /* MATLABSystem: '<S1>/SPI Controller Transfer1' incorporates:
   *  Constant: '<S1>/Dummy Bits'
   */
  status = MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_l.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 1U);
    MW_SPI_MasterWriteRead_Databits(PDUSTM32_DW.obj_l.MW_SPI_HANDLE,
      &PDUSTM32_ConstP.pooled7[0], &tmp[0], 0, 2U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 1U);
  }

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/VA'
   *  MATLABSystem: '<S1>/SPI Controller Transfer1'
   */
  PDUSTM32_MATLABFunction(tmp, 5.0, &PDUSTM32_B.Voltage_a);

  /* MATLABSystem: '<S4>/SPI Controller Transfer1' incorporates:
   *  Constant: '<S4>/Dummy Bits'
   */
  status = MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_e2.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 8U);
    MW_SPI_MasterWriteRead_Databits(PDUSTM32_DW.obj_e2.MW_SPI_HANDLE,
      &PDUSTM32_ConstP.pooled7[0], &tmp[0], 0, 2U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 8U);
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S4>/VA'
   *  MATLABSystem: '<S4>/SPI Controller Transfer1'
   */
  PDUSTM32_MATLABFunction(tmp, 5.0, &PDUSTM32_B.Voltage);

  /* MATLABSystem: '<S3>/SPI Controller Transfer1' incorporates:
   *  Constant: '<S3>/Dummy Bits'
   */
  status = MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_o.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 4U);
    MW_SPI_MasterWriteRead_Databits(PDUSTM32_DW.obj_o.MW_SPI_HANDLE,
      &PDUSTM32_ConstP.pooled7[0], &tmp[0], 0, 2U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 4U);
  }

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S3>/VA'
   *  MATLABSystem: '<S3>/SPI Controller Transfer1'
   */
  PDUSTM32_MATLABFunction(tmp, 5.0, &PDUSTM32_B.Voltage_g);

  /* S-Function (scanpack): '<S7>/CAN Pack1' */
  /* S-Function (scanpack): '<S7>/CAN Pack1' */
  PDUSTM32_B.CANPack1.ID = 105U;
  PDUSTM32_B.CANPack1.Length = 8U;
  PDUSTM32_B.CANPack1.Extended = 0U;
  PDUSTM32_B.CANPack1.Remote = 0;
  PDUSTM32_B.CANPack1.Data[0] = 0;
  PDUSTM32_B.CANPack1.Data[1] = 0;
  PDUSTM32_B.CANPack1.Data[2] = 0;
  PDUSTM32_B.CANPack1.Data[3] = 0;
  PDUSTM32_B.CANPack1.Data[4] = 0;
  PDUSTM32_B.CANPack1.Data[5] = 0;
  PDUSTM32_B.CANPack1.Data[6] = 0;
  PDUSTM32_B.CANPack1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = PDUSTM32_B.Voltage_k;

        /* no scaling required */
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
            PDUSTM32_B.CANPack1.Data[0] = PDUSTM32_B.CANPack1.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack1.Data[1] = PDUSTM32_B.CANPack1.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = PDUSTM32_B.Voltage_a;

        /* no scaling required */
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
            PDUSTM32_B.CANPack1.Data[2] = PDUSTM32_B.CANPack1.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack1.Data[3] = PDUSTM32_B.CANPack1.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = PDUSTM32_B.Voltage;

        /* no scaling required */
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
            PDUSTM32_B.CANPack1.Data[4] = PDUSTM32_B.CANPack1.Data[4] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack1.Data[5] = PDUSTM32_B.CANPack1.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 48
     *  length                  = 12
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real_T outValue = 0;

      {
        real_T result = PDUSTM32_B.Voltage_g;

        /* no scaling required */
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
            PDUSTM32_B.CANPack1.Data[6] = PDUSTM32_B.CANPack1.Data[6] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack1.Data[7] = PDUSTM32_B.CANPack1.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xF00U) >> 8));
          }
        }
      }
    }
  }

  /* Outputs for Enabled SubSystem: '<S10>/Initialize' incorporates:
   *  EnablePort: '<S30>/Enable'
   */
  /* UnitDelay: '<S10>/Unit Delay' */
  if (PDUSTM32_DW.UnitDelay_DSTATE > 0.0) {
    /* SignalConversion generated from: '<S30>/MCPInitialized' */
    PDUSTM32_B.OutportBufferForMCPInitialized = PDUSTM32_ConstB.Constant;
  }

  /* End of Outputs for SubSystem: '<S10>/Initialize' */

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Offset'
   *  Constant: '<S7>/Period'
   *  Constant: '<S7>/RTS'
   */
  PDUSTM32_MATLABFunction_o(PDUSTM32_B.CANPack1.ID, PDUSTM32_B.CANPack1.Length,
    PDUSTM32_B.CANPack1.Data, 129, 5, 0,
    PDUSTM32_B.OutportBufferForMCPInitialized, &rtb_VectorConcatenate[0],
    &rtb_VectorConcatenate[2], &status, &PDUSTM32_DW.sf_MATLABFunction_o);

  /* Constant: '<S7>/TX Buffer 0' */
  rtb_VectorConcatenate[1] = 49U;
  PDUSTM3_SPIControllerTransfer_p(rtb_VectorConcatenate,
    &PDUSTM32_DW.SPIControllerTransfer);

  /* MATLABSystem: '<S19>/Analog to Digital Converter' */
  regularReadADCDMA(PDUSTM32_DW.obj_n.ADCHandle, ADC_READ,
                    &rtb_AnalogtoDigitalConverter_0[0]);
  for (i = 0; i < 7; i++) {
    /* Gain: '<Root>/Gain4' incorporates:
     *  MATLABSystem: '<S19>/Analog to Digital Converter'
     */
    PDUSTM32_B.Gain4[i] = 5.03547708E-5F * (real32_T)
      rtb_AnalogtoDigitalConverter_0[i];
  }

  /* S-Function (scanpack): '<S7>/CAN Pack2' */
  /* S-Function (scanpack): '<S7>/CAN Pack2' */
  PDUSTM32_B.CANPack2.ID = 5U;
  PDUSTM32_B.CANPack2.Length = 8U;
  PDUSTM32_B.CANPack2.Extended = 0U;
  PDUSTM32_B.CANPack2.Remote = 0;
  PDUSTM32_B.CANPack2.Data[0] = 0;
  PDUSTM32_B.CANPack2.Data[1] = 0;
  PDUSTM32_B.CANPack2.Data[2] = 0;
  PDUSTM32_B.CANPack2.Data[3] = 0;
  PDUSTM32_B.CANPack2.Data[4] = 0;
  PDUSTM32_B.CANPack2.Data[5] = 0;
  PDUSTM32_B.CANPack2.Data[6] = 0;
  PDUSTM32_B.CANPack2.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PDUSTM32_B.Gain4[0];

        /* no scaling required */
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
            PDUSTM32_B.CANPack2.Data[0] = PDUSTM32_B.CANPack2.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack2.Data[1] = PDUSTM32_B.CANPack2.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PDUSTM32_B.Gain4[1];

        /* no scaling required */
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
            PDUSTM32_B.CANPack2.Data[2] = PDUSTM32_B.CANPack2.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack2.Data[3] = PDUSTM32_B.CANPack2.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PDUSTM32_B.Gain4[2];

        /* no scaling required */
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
            PDUSTM32_B.CANPack2.Data[4] = PDUSTM32_B.CANPack2.Data[4] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack2.Data[5] = PDUSTM32_B.CANPack2.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 48
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PDUSTM32_B.Gain4[3];

        /* no scaling required */
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
            PDUSTM32_B.CANPack2.Data[6] = PDUSTM32_B.CANPack2.Data[6] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack2.Data[7] = PDUSTM32_B.CANPack2.Data[7] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLAB Function: '<S7>/MATLAB Function1' incorporates:
   *  Constant: '<S7>/Offset1'
   *  Constant: '<S7>/Period1'
   *  Constant: '<S7>/RTS1'
   */
  PDUSTM32_MATLABFunction_o(PDUSTM32_B.CANPack2.ID, PDUSTM32_B.CANPack2.Length,
    PDUSTM32_B.CANPack2.Data, 129, 5, 2,
    PDUSTM32_B.OutportBufferForMCPInitialized, &rtb_VectorConcatenate1[0],
    &rtb_VectorConcatenate1[2], &status, &PDUSTM32_DW.sf_MATLABFunction1);

  /* Constant: '<S7>/TX Buffer 1' */
  rtb_VectorConcatenate1[1] = 49U;
  PDUSTM3_SPIControllerTransfer_p(rtb_VectorConcatenate1,
    &PDUSTM32_DW.SPIControllerTransfer2);

  /* S-Function (scanpack): '<S7>/CAN Pack3' */
  /* S-Function (scanpack): '<S7>/CAN Pack3' */
  PDUSTM32_B.CANPack3.ID = 66U;
  PDUSTM32_B.CANPack3.Length = 6U;
  PDUSTM32_B.CANPack3.Extended = 0U;
  PDUSTM32_B.CANPack3.Remote = 0;
  PDUSTM32_B.CANPack3.Data[0] = 0;
  PDUSTM32_B.CANPack3.Data[1] = 0;
  PDUSTM32_B.CANPack3.Data[2] = 0;
  PDUSTM32_B.CANPack3.Data[3] = 0;
  PDUSTM32_B.CANPack3.Data[4] = 0;
  PDUSTM32_B.CANPack3.Data[5] = 0;
  PDUSTM32_B.CANPack3.Data[6] = 0;
  PDUSTM32_B.CANPack3.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PDUSTM32_B.Gain4[4];

        /* no scaling required */
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
            PDUSTM32_B.CANPack3.Data[0] = PDUSTM32_B.CANPack3.Data[0] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack3.Data[1] = PDUSTM32_B.CANPack3.Data[1] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 16
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PDUSTM32_B.Gain4[5];

        /* no scaling required */
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
            PDUSTM32_B.CANPack3.Data[2] = PDUSTM32_B.CANPack3.Data[2] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack3.Data[3] = PDUSTM32_B.CANPack3.Data[3] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 32
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real32_T outValue = 0;

      {
        real32_T result = PDUSTM32_B.Gain4[6];

        /* no scaling required */
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
            PDUSTM32_B.CANPack3.Data[4] = PDUSTM32_B.CANPack3.Data[4] | (uint8_T)
              ((uint16_T)(packedValue & (uint16_T)0xFFU));
            PDUSTM32_B.CANPack3.Data[5] = PDUSTM32_B.CANPack3.Data[5] | (uint8_T)
              ((uint16_T)((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }
  }

  /* MATLAB Function: '<S7>/MATLAB Function2' incorporates:
   *  Constant: '<S7>/Offset2'
   *  Constant: '<S7>/Period2'
   *  Constant: '<S7>/RTS2'
   */
  PDUSTM32_MATLABFunction_o(PDUSTM32_B.CANPack3.ID, PDUSTM32_B.CANPack3.Length,
    PDUSTM32_B.CANPack3.Data, 129, 5, 4,
    PDUSTM32_B.OutportBufferForMCPInitialized, &rtb_VectorConcatenate2[0],
    &rtb_VectorConcatenate2[2], &status, &PDUSTM32_DW.sf_MATLABFunction2);

  /* Constant: '<S7>/TX Buffer 2' */
  rtb_VectorConcatenate2[1] = 49U;
  PDUSTM3_SPIControllerTransfer_p(rtb_VectorConcatenate2,
    &PDUSTM32_DW.SPIControllerTransfer4);

  /* MATLABSystem: '<S26>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* Outputs for Enabled SubSystem: '<Root>/CAN Rx' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* Logic: '<Root>/NOT4' incorporates:
   *  Constant: '<S6>/Read RX Buffer start at RXB0SIDH'
   *  Constant: '<S6>/Read RX Buffer start at RXB0SIDH1'
   *  MATLABSystem: '<S26>/Digital Port Read'
   * */
  if ((pinReadLoc & 4U) == 0U) {
    PDUSTM32_SPIControllerTransfer(PDUSTM32_ConstP.pooled6,
      &PDUSTM32_B.SPIControllerTransfer_p, &PDUSTM32_DW.SPIControllerTransfer_p);
    PDUSTM32_SPIControllerTransfer(PDUSTM32_ConstP.pooled6,
      &PDUSTM32_B.SPIControllerTransfer1_pnae,
      &PDUSTM32_DW.SPIControllerTransfer1_pnae);

    /* MATLAB Function: '<S6>/MATLAB Function1' incorporates:
     *  Constant: '<S6>/Read RX Buffer start at RXB0SIDH'
     *  Constant: '<S6>/Read RX Buffer start at RXB0SIDH1'
     */
    PDUSTM32_MATLABFunction_f
      (PDUSTM32_B.SPIControllerTransfer1_pnae.SPIControllerTransfer,
       &PDUSTM32_B.Message);

    /* MATLAB Function: '<S6>/MATLAB Function' */
    PDUSTM32_MATLABFunction_f
      (PDUSTM32_B.SPIControllerTransfer_p.SPIControllerTransfer,
       &PDUSTM32_B.Message_p);

    /* S-Function (scanunpack): '<S6>/CAN Unpack' */
    {
      /* S-Function (scanunpack): '<S6>/CAN Unpack' */
      if ((7 == PDUSTM32_B.Message_p.Length) && (PDUSTM32_B.Message_p.ID !=
           INVALID_CAN_ID) ) {
        if ((1539 == PDUSTM32_B.Message_p.ID) && (0U ==
             PDUSTM32_B.Message_p.Extended) ) {
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
              uint8_T outValue = 0;

              {
                uint8_T unpackedValue = 0;

                {
                  uint8_T tempValue = (uint8_T) (0);

                  {
                    tempValue = tempValue | (uint8_T)((uint8_T)
                      (PDUSTM32_B.Message_p.Data[3]) & (uint8_T)(0x1U));
                  }

                  unpackedValue = tempValue;
                }

                outValue = (boolean_T) (unpackedValue);
              }

              {
                boolean_T result = (boolean_T) outValue;
                PDUSTM32_B.CANUnpack_o1 = result;
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
              uint8_T outValue = 0;

              {
                uint8_T unpackedValue = 0;

                {
                  uint8_T tempValue = (uint8_T) (0);

                  {
                    tempValue = tempValue | (uint8_T)((uint8_T)
                      (PDUSTM32_B.Message_p.Data[0]) & (uint8_T)(0x1U));
                  }

                  unpackedValue = tempValue;
                }

                outValue = (boolean_T) (unpackedValue);
              }

              {
                boolean_T result = (boolean_T) outValue;
                PDUSTM32_B.CANUnpack_o2 = result;
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
              uint8_T outValue = 0;

              {
                uint8_T unpackedValue = 0;

                {
                  uint8_T tempValue = (uint8_T) (0);

                  {
                    tempValue = tempValue | (uint8_T)((uint8_T)
                      (PDUSTM32_B.Message_p.Data[4]) & (uint8_T)(0x1U));
                  }

                  unpackedValue = tempValue;
                }

                outValue = (boolean_T) (unpackedValue);
              }

              {
                boolean_T result = (boolean_T) outValue;
                PDUSTM32_B.CANUnpack_o3 = result;
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
              uint8_T outValue = 0;

              {
                uint8_T unpackedValue = 0;

                {
                  uint8_T tempValue = (uint8_T) (0);

                  {
                    tempValue = tempValue | (uint8_T)((uint8_T)
                      (PDUSTM32_B.Message_p.Data[1]) & (uint8_T)(0x1U));
                  }

                  unpackedValue = tempValue;
                }

                outValue = (boolean_T) (unpackedValue);
              }

              {
                boolean_T result = (boolean_T) outValue;
                PDUSTM32_B.CANUnpack_o4 = result;
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
              uint8_T outValue = 0;

              {
                uint8_T unpackedValue = 0;

                {
                  uint8_T tempValue = (uint8_T) (0);

                  {
                    tempValue = tempValue | (uint8_T)((uint8_T)
                      (PDUSTM32_B.Message_p.Data[2]) & (uint8_T)(0x1U));
                  }

                  unpackedValue = tempValue;
                }

                outValue = (boolean_T) (unpackedValue);
              }

              {
                boolean_T result = (boolean_T) outValue;
                PDUSTM32_B.CANUnpack_o5 = result;
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
              uint8_T outValue = 0;

              {
                uint8_T unpackedValue = 0;

                {
                  uint8_T tempValue = (uint8_T) (0);

                  {
                    tempValue = tempValue | (uint8_T)((uint8_T)
                      (PDUSTM32_B.Message_p.Data[5]) & (uint8_T)(0x1U));
                  }

                  unpackedValue = tempValue;
                }

                outValue = (boolean_T) (unpackedValue);
              }

              {
                boolean_T result = (boolean_T) outValue;
                PDUSTM32_B.CANUnpack_o6 = result;
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
              uint8_T outValue = 0;

              {
                uint8_T unpackedValue = 0;

                {
                  uint8_T tempValue = (uint8_T) (0);

                  {
                    tempValue = tempValue | (uint8_T)((uint8_T)
                      (PDUSTM32_B.Message_p.Data[6]) & (uint8_T)(0x1U));
                  }

                  unpackedValue = tempValue;
                }

                outValue = (boolean_T) (unpackedValue);
              }

              {
                boolean_T result = (boolean_T) outValue;
                PDUSTM32_B.CANUnpack_o7 = result;
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S6>/CAN Unpack1' */
    {
      /* S-Function (scanunpack): '<S6>/CAN Unpack1' */
      if ((6 == PDUSTM32_B.Message.Length) && (PDUSTM32_B.Message.ID !=
           INVALID_CAN_ID) ) {
        if ((419 == PDUSTM32_B.Message.ID) && (0U == PDUSTM32_B.Message.Extended)
            ) {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 32
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              uint8_T outValue = 0;

              {
                uint8_T unpackedValue = 0;

                {
                  uint8_T tempValue = (uint8_T) (0);

                  {
                    tempValue = tempValue | (uint8_T)((uint8_T)
                      (PDUSTM32_B.Message.Data[4]) & (uint8_T)(0x1U));
                  }

                  unpackedValue = tempValue;
                }

                outValue = (boolean_T) (unpackedValue);
              }

              {
                boolean_T result = (boolean_T) outValue;
                PDUSTM32_B.CANUnpack1_o1 = result;
              }
            }

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
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */

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
  }

  /* End of Logic: '<Root>/NOT4' */
  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */

  /* MATLABSystem: '<S33>/Digital Port Write' incorporates:
   *  SignalConversion generated from: '<S33>/Digital Port Write'
   */
  portNameLoc = GPIOB;
  if (PDUSTM32_B.CANUnpack_o2) {
    i = 16;
  } else {
    i = 0;
  }

  if (PDUSTM32_B.CANUnpack_o3) {
    tmp_0 = 32;
  } else {
    tmp_0 = 0;
  }

  if (PDUSTM32_B.CANUnpack_o4) {
    tmp_1 = 128;
  } else {
    tmp_1 = 0;
  }

  if (PDUSTM32_B.CANUnpack_o1) {
    tmp_2 = 512;
  } else {
    tmp_2 = 0;
  }

  if (PDUSTM32_B.CANUnpack1_o1) {
    tmp_3 = 4096;
  } else {
    tmp_3 = 0;
  }

  if (PDUSTM32_B.CANUnpack_o7) {
    tmp_4 = 8192;
  } else {
    tmp_4 = 0;
  }

  i = (int32_T)((uint32_T)i | (uint32_T)tmp_0 | (uint32_T)tmp_1 | (uint32_T)
                tmp_2 | (uint32_T)tmp_3 | (uint32_T)tmp_4);
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 12976U);

  /* End of MATLABSystem: '<S33>/Digital Port Write' */

  /* MATLABSystem: '<S35>/Digital Port Write' */
  portNameLoc = GPIOC;
  if (PDUSTM32_B.CANUnpack_o5) {
    i = 4;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4U);

  /* End of MATLABSystem: '<S35>/Digital Port Write' */

  /* MATLABSystem: '<S37>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (PDUSTM32_B.CANUnpack_o6) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 4096U);

  /* End of MATLABSystem: '<S37>/Digital Port Write' */

  /* MATLABSystem: '<Root>/SPI Controller Transfer3' incorporates:
   *  Constant: '<Root>/RTS0'
   */
  status = MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_e.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 16U);
    MW_SPI_MasterWriteRead_Databits(PDUSTM32_DW.obj_e.MW_SPI_HANDLE,
      &PDUSTM32_ConstP.pooled8, &status, 0, 1U, 0, 1U);
    LL_GPIO_SetOutputPin(portNameLoc, 16U);
  }

  /* End of MATLABSystem: '<Root>/SPI Controller Transfer3' */

  /* Step: '<S10>/Step2' incorporates:
   *  UnitDelay: '<S10>/Unit Delay'
   */
  UnitDelay_DSTATE_tmp = !(((PDUSTM32_M->Timing.clockTick0) * 0.001) < 1.0);
  PDUSTM32_DW.UnitDelay_DSTATE = UnitDelay_DSTATE_tmp;

  /* Outputs for Enabled SubSystem: '<S10>/MCPInit' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  /* RelationalOperator: '<S29>/FixPt Relational Operator' incorporates:
   *  Constant: '<S31>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   *  Constant: '<S31>/CNF1'
   *  Constant: '<S31>/CNF2'
   *  Constant: '<S31>/CNF3'
   *  UnitDelay: '<S29>/Delay Input1'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((real_T)UnitDelay_DSTATE_tmp > PDUSTM32_DW.DelayInput1_DSTATE) {
    /* MATLABSystem: '<S31>/SPI Controller Transfer' incorporates:
     *  Constant: '<S31>/Enter Configuration Mode'
     */
    status = MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    if (status == 0) {
      portNameLoc = GPIOA;
      LL_GPIO_ResetOutputPin(portNameLoc, 16U);
      MW_SPI_MasterWriteRead_Databits(PDUSTM32_DW.obj.MW_SPI_HANDLE,
        &PDUSTM32_ConstP.EnterConfigurationMode_Value, &status, 0, 1U, 1, 10U);
      LL_GPIO_SetOutputPin(portNameLoc, 16U);
    }

    /* End of MATLABSystem: '<S31>/SPI Controller Transfer' */
    PDUSTM32_SPIControllerTransfer1(PDUSTM32_ConstP.CNF1_Value,
      &PDUSTM32_DW.SPIControllerTransfer1_pnaev);
    PDUSTM32_SPIControllerTransfer1(PDUSTM32_ConstP.CNF2_Value,
      &PDUSTM32_DW.SPIControllerTransfer2_p);
    PDUSTM32_SPIControllerTransfer1(PDUSTM32_ConstP.CNF3_Value,
      &PDUSTM32_DW.SPIControllerTransfer3_p);
    PDUSTM32_SPIControllerTransfer1
      (PDUSTM32_ConstP.u00normalmode0dontabortpendingt,
       &PDUSTM32_DW.SPIControllerTransfer4_p);
  }

  /* End of RelationalOperator: '<S29>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<S10>/MCPInit' */

  /* Logic: '<Root>/NOT' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  PDUSTM32_DW.UnitDelay_DSTATE_j = !PDUSTM32_DW.UnitDelay_DSTATE_j;

  /* MATLABSystem: '<S28>/Digital Port Write' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   */
  portNameLoc = GPIOC;
  if (PDUSTM32_DW.UnitDelay_DSTATE_j) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 2048U);

  /* End of MATLABSystem: '<S28>/Digital Port Write' */

  /* Update for UnitDelay: '<S29>/Delay Input1'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  PDUSTM32_DW.DelayInput1_DSTATE = UnitDelay_DSTATE_tmp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  PDUSTM32_M->Timing.clockTick0++;
}

/* Model initialize function */
void PDUSTM32_initialize(void)
{
  {
    STM32_SPI_ModuleStruct_T b;
    STM32_SPI_ModuleStruct_T b_0;
    STM32_SPI_ModuleStruct_T b_1;
    STM32_SPI_ModuleStruct_T b_2;
    STM32_SPI_ModuleStruct_T b_3;
    STM32_SPI_ModuleStruct_T b_4;

    /* SystemInitialize for Enabled SubSystem: '<S10>/Initialize' */
    /* SystemInitialize for SignalConversion generated from: '<S30>/MCPInitialized' */
    PDUSTM32_B.OutportBufferForMCPInitialized = PDUSTM32_ConstB.Constant;

    /* End of SystemInitialize for SubSystem: '<S10>/Initialize' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/CAN Rx' */

    /* Start for S-Function (scanunpack): '<S6>/CAN Unpack' */

    /*-----------S-Function Block: <S6>/CAN Unpack -----------------*/

    /* Start for S-Function (scanunpack): '<S6>/CAN Unpack1' */

    /*-----------S-Function Block: <S6>/CAN Unpack1 -----------------*/
    PDUS_SPIControllerTransfer_Init(&PDUSTM32_DW.SPIControllerTransfer_p);
    PDUS_SPIControllerTransfer_Init(&PDUSTM32_DW.SPIControllerTransfer1_pnae);

    /* End of SystemInitialize for SubSystem: '<Root>/CAN Rx' */

    /* SystemInitialize for Enabled SubSystem: '<S10>/MCPInit' */
    /* Start for MATLABSystem: '<S31>/SPI Controller Transfer' */
    PDUSTM32_DW.obj.matlabCodegenIsDeleted = false;
    PDUSTM32_DW.obj.isInitialized = 1;
    b_4.PeripheralPtr = SPI1;
    PDUSTM32_DW.obj.MW_SPI_HANDLE = SPI_STM32_Init(&b_4);
    MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    PDUSTM32_DW.obj.isSetupComplete = true;
    PDU_SPIControllerTransfer1_Init(&PDUSTM32_DW.SPIControllerTransfer1_pnaev);
    PDU_SPIControllerTransfer1_Init(&PDUSTM32_DW.SPIControllerTransfer2_p);
    PDU_SPIControllerTransfer1_Init(&PDUSTM32_DW.SPIControllerTransfer3_p);
    PDU_SPIControllerTransfer1_Init(&PDUSTM32_DW.SPIControllerTransfer4_p);

    /* End of SystemInitialize for SubSystem: '<S10>/MCPInit' */

    /* Start for MATLABSystem: '<S2>/SPI Controller Transfer1' */
    PDUSTM32_DW.obj_d.matlabCodegenIsDeleted = false;
    PDUSTM32_DW.obj_d.isInitialized = 1;
    b.PeripheralPtr = SPI1;
    PDUSTM32_DW.obj_d.MW_SPI_HANDLE = SPI_STM32_Init(&b);
    MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_d.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    PDUSTM32_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/SPI Controller Transfer1' */
    PDUSTM32_DW.obj_l.matlabCodegenIsDeleted = false;
    PDUSTM32_DW.obj_l.isInitialized = 1;
    b_0.PeripheralPtr = SPI1;
    PDUSTM32_DW.obj_l.MW_SPI_HANDLE = SPI_STM32_Init(&b_0);
    MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_l.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    PDUSTM32_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/SPI Controller Transfer1' */
    PDUSTM32_DW.obj_e2.matlabCodegenIsDeleted = false;
    PDUSTM32_DW.obj_e2.isInitialized = 1;
    b_1.PeripheralPtr = SPI1;
    PDUSTM32_DW.obj_e2.MW_SPI_HANDLE = SPI_STM32_Init(&b_1);
    MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_e2.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    PDUSTM32_DW.obj_e2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/SPI Controller Transfer1' */
    PDUSTM32_DW.obj_o.matlabCodegenIsDeleted = false;
    PDUSTM32_DW.obj_o.isInitialized = 1;
    b_2.PeripheralPtr = SPI1;
    PDUSTM32_DW.obj_o.MW_SPI_HANDLE = SPI_STM32_Init(&b_2);
    MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_o.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    PDUSTM32_DW.obj_o.isSetupComplete = true;
    PD_SPIControllerTransfer_o_Init(&PDUSTM32_DW.SPIControllerTransfer);

    /* Start for MATLABSystem: '<S19>/Analog to Digital Converter' */
    PDUSTM32_DW.obj_n.isInitialized = 0;
    PDUSTM32_DW.obj_n.matlabCodegenIsDeleted = false;
    PDUSTM32_SystemCore_setup(&PDUSTM32_DW.obj_n);
    PD_SPIControllerTransfer_o_Init(&PDUSTM32_DW.SPIControllerTransfer2);
    PD_SPIControllerTransfer_o_Init(&PDUSTM32_DW.SPIControllerTransfer4);

    /* Start for MATLABSystem: '<Root>/SPI Controller Transfer3' */
    PDUSTM32_DW.obj_e.matlabCodegenIsDeleted = false;
    PDUSTM32_DW.obj_e.isInitialized = 1;
    b_3.PeripheralPtr = SPI1;
    PDUSTM32_DW.obj_e.MW_SPI_HANDLE = SPI_STM32_Init(&b_3);
    MW_STM32_SPI_SetFormat(PDUSTM32_DW.obj_e.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    PDUSTM32_DW.obj_e.isSetupComplete = true;
  }

  /* user code (Initialize function Body) */
  LL_TIM_EnableCounter(TIM2);
}

/* Model terminate function */
void PDUSTM32_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S2>/SPI Controller Transfer1' */
  if (!PDUSTM32_DW.obj_d.matlabCodegenIsDeleted) {
    PDUSTM32_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PDUSTM32_DW.obj_d.isInitialized == 1) &&
        PDUSTM32_DW.obj_d.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PDUSTM32_DW.obj_d.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 1U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/SPI Controller Transfer1' */

  /* Terminate for MATLABSystem: '<S1>/SPI Controller Transfer1' */
  if (!PDUSTM32_DW.obj_l.matlabCodegenIsDeleted) {
    PDUSTM32_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((PDUSTM32_DW.obj_l.isInitialized == 1) &&
        PDUSTM32_DW.obj_l.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PDUSTM32_DW.obj_l.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 0U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/SPI Controller Transfer1' */

  /* Terminate for MATLABSystem: '<S4>/SPI Controller Transfer1' */
  if (!PDUSTM32_DW.obj_e2.matlabCodegenIsDeleted) {
    PDUSTM32_DW.obj_e2.matlabCodegenIsDeleted = true;
    if ((PDUSTM32_DW.obj_e2.isInitialized == 1) &&
        PDUSTM32_DW.obj_e2.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PDUSTM32_DW.obj_e2.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 3U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/SPI Controller Transfer1' */

  /* Terminate for MATLABSystem: '<S3>/SPI Controller Transfer1' */
  if (!PDUSTM32_DW.obj_o.matlabCodegenIsDeleted) {
    PDUSTM32_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PDUSTM32_DW.obj_o.isInitialized == 1) &&
        PDUSTM32_DW.obj_o.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PDUSTM32_DW.obj_o.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 2U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/SPI Controller Transfer1' */
  PD_SPIControllerTransfer_i_Term(&PDUSTM32_DW.SPIControllerTransfer);

  /* Terminate for MATLABSystem: '<S19>/Analog to Digital Converter' */
  if (!PDUSTM32_DW.obj_n.matlabCodegenIsDeleted) {
    PDUSTM32_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PDUSTM32_DW.obj_n.isInitialized == 1) &&
        PDUSTM32_DW.obj_n.isSetupComplete) {
      ADC_Handle_Deinit(PDUSTM32_DW.obj_n.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S19>/Analog to Digital Converter' */
  PD_SPIControllerTransfer_i_Term(&PDUSTM32_DW.SPIControllerTransfer2);
  PD_SPIControllerTransfer_i_Term(&PDUSTM32_DW.SPIControllerTransfer4);

  /* Terminate for Enabled SubSystem: '<Root>/CAN Rx' */
  PDUS_SPIControllerTransfer_Term(&PDUSTM32_DW.SPIControllerTransfer_p);
  PDUS_SPIControllerTransfer_Term(&PDUSTM32_DW.SPIControllerTransfer1_pnae);

  /* End of Terminate for SubSystem: '<Root>/CAN Rx' */

  /* Terminate for MATLABSystem: '<Root>/SPI Controller Transfer3' */
  if (!PDUSTM32_DW.obj_e.matlabCodegenIsDeleted) {
    PDUSTM32_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((PDUSTM32_DW.obj_e.isInitialized == 1) &&
        PDUSTM32_DW.obj_e.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PDUSTM32_DW.obj_e.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/SPI Controller Transfer3' */

  /* Terminate for Enabled SubSystem: '<S10>/MCPInit' */
  /* Terminate for MATLABSystem: '<S31>/SPI Controller Transfer' */
  if (!PDUSTM32_DW.obj.matlabCodegenIsDeleted) {
    PDUSTM32_DW.obj.matlabCodegenIsDeleted = true;
    if ((PDUSTM32_DW.obj.isInitialized == 1) && PDUSTM32_DW.obj.isSetupComplete)
    {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PDUSTM32_DW.obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/SPI Controller Transfer' */
  PDU_SPIControllerTransfer1_Term(&PDUSTM32_DW.SPIControllerTransfer1_pnaev);
  PDU_SPIControllerTransfer1_Term(&PDUSTM32_DW.SPIControllerTransfer2_p);
  PDU_SPIControllerTransfer1_Term(&PDUSTM32_DW.SPIControllerTransfer3_p);
  PDU_SPIControllerTransfer1_Term(&PDUSTM32_DW.SPIControllerTransfer4_p);

  /* End of Terminate for SubSystem: '<S10>/MCPInit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
