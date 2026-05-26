/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CANTestingSTM32.c
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

#include "CANTestingSTM32.h"
#include "rtwtypes.h"
#include "CANTestingSTM32_types.h"
#include "CANTestingSTM32_private.h"
#include "mw_stm32_spi_ll.h"

/* Block signals (default storage) */
B_CANTestingSTM32_T CANTestingSTM32_B;

/* Block states (default storage) */
DW_CANTestingSTM32_T CANTestingSTM32_DW;

/* Real-time model */
static RT_MODEL_CANTestingSTM32_T CANTestingSTM32_M_;
RT_MODEL_CANTestingSTM32_T *const CANTestingSTM32_M = &CANTestingSTM32_M_;

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function'
 *    '<S1>/MATLAB Function1'
 */
void CANTestingSTM32_MATLABFunction(const uint8_T rtu_RxBytes[14],
  CAN_MESSAGE_def *rty_Message)
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
void CANT_SPIControllerTransfer_Init(DW_SPIControllerTransfer_CANT_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S1>/SPI Controller Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void CANTestin_SPIControllerTransfer(const uint8_T rtu_0[14],
  B_SPIControllerTransfer_CANTe_T *localB, DW_SPIControllerTransfer_CANT_T
  *localDW)
{
  uint8_T status;

  /* MATLABSystem: '<S1>/SPI Controller Transfer' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 16U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0],
      &localB->SPIControllerTransfer[0], 0, 14U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 16U);
  }

  /* End of MATLABSystem: '<S1>/SPI Controller Transfer' */
}

/* Termination for atomic system: */
void CANT_SPIControllerTransfer_Term(DW_SPIControllerTransfer_CANT_T *localDW)
{
  /* Terminate for MATLABSystem: '<S1>/SPI Controller Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/SPI Controller Transfer' */
}

/* System initialize for atomic system: */
void CAN_SPIControllerTransfer1_Init(DW_SPIControllerTransfer1_CAN_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S25>/SPI Controller Transfer1' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void CANTesti_SPIControllerTransfer1(const uint8_T rtu_0[3],
  DW_SPIControllerTransfer1_CAN_T *localDW)
{
  uint8_T tmp[3];
  uint8_T status;

  /* MATLABSystem: '<S25>/SPI Controller Transfer1' */
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

  /* End of MATLABSystem: '<S25>/SPI Controller Transfer1' */
}

/* Termination for atomic system: */
void CAN_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_CAN_T *localDW)
{
  /* Terminate for MATLABSystem: '<S25>/SPI Controller Transfer1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S25>/SPI Controller Transfer1' */
}

/* System initialize for atomic system: */
void CAN_SPIControllerTransfer5_Init(DW_SPIControllerTransfer5_CAN_T *localDW)
{
  STM32_SPI_ModuleStruct_T b;

  /* Start for MATLABSystem: '<S25>/SPI Controller Transfer5' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  b.PeripheralPtr = SPI1;
  localDW->obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
  MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U, MW_SPI_MODE_2);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void CANTesti_SPIControllerTransfer5(const uint8_T rtu_0[4],
  DW_SPIControllerTransfer5_CAN_T *localDW)
{
  uint8_T tmp[4];
  uint8_T status;

  /* MATLABSystem: '<S25>/SPI Controller Transfer5' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 0U, 1792U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOA;
    LL_GPIO_ResetOutputPin(portNameLoc, 16U);
    MW_SPI_MasterWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0[0], &tmp
      [0], 0, 4U, 1, 10U);
    LL_GPIO_SetOutputPin(portNameLoc, 16U);
  }

  /* End of MATLABSystem: '<S25>/SPI Controller Transfer5' */
}

/* Termination for atomic system: */
void CAN_SPIControllerTransfer5_Term(DW_SPIControllerTransfer5_CAN_T *localDW)
{
  /* Terminate for MATLABSystem: '<S25>/SPI Controller Transfer5' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S25>/SPI Controller Transfer5' */
}

/* Model step function */
void CANTestingSTM32_step(void)
{
  GPIO_TypeDef * portNameLoc;
  int32_T rtb_Step1;
  uint32_T pinReadLoc;
  uint8_T rdDataRaw;
  boolean_T rtb_AND1;

  /* MATLABSystem: '<S15>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* Outputs for Enabled SubSystem: '<Root>/CAN Rx' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* Logic: '<Root>/NOT4' incorporates:
   *  Constant: '<S1>/Read RX Buffer start at RXB0SIDH'
   *  Constant: '<S1>/Read RX Buffer start at RXB0SIDH1'
   *  MATLABSystem: '<S15>/Digital Port Read'
   * */
  if ((pinReadLoc & 32U) == 0U) {
    CANTestin_SPIControllerTransfer(CANTestingSTM32_ConstP.pooled4,
      &CANTestingSTM32_B.SPIControllerTransfer,
      &CANTestingSTM32_DW.SPIControllerTransfer);
    CANTestin_SPIControllerTransfer(CANTestingSTM32_ConstP.pooled4,
      &CANTestingSTM32_B.SPIControllerTransfer1,
      &CANTestingSTM32_DW.SPIControllerTransfer1);

    /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
     *  Constant: '<S1>/Read RX Buffer start at RXB0SIDH'
     *  Constant: '<S1>/Read RX Buffer start at RXB0SIDH1'
     */
    CANTestingSTM32_MATLABFunction
      (CANTestingSTM32_B.SPIControllerTransfer1.SPIControllerTransfer,
       &CANTestingSTM32_B.Message);

    /* MATLAB Function: '<S1>/MATLAB Function' */
    CANTestingSTM32_MATLABFunction
      (CANTestingSTM32_B.SPIControllerTransfer.SPIControllerTransfer,
       &CANTestingSTM32_B.Message_p);

    /* S-Function (scanunpack): '<S1>/CAN Unpack' */
    {
      /* S-Function (scanunpack): '<S1>/CAN Unpack' */
      if ((4 == CANTestingSTM32_B.Message_p.Length) &&
          (CANTestingSTM32_B.Message_p.ID != INVALID_CAN_ID) ) {
        if ((0 == CANTestingSTM32_B.Message_p.ID) && (0U ==
             CANTestingSTM32_B.Message_p.Extended) ) {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 0
             *  length                  = 8
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
                    tempValue = tempValue | (uint8_T)
                      (CANTestingSTM32_B.Message_p.Data[0]);
                  }

                  unpackedValue = tempValue;
                }

                outValue = (real_T) (unpackedValue);
              }

              {
                real_T result = (real_T) outValue;
                CANTestingSTM32_B.CANUnpack_o1 = result;
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 16
             *  length                  = 8
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
                    tempValue = tempValue | (uint8_T)
                      (CANTestingSTM32_B.Message_p.Data[2]);
                  }

                  unpackedValue = tempValue;
                }

                outValue = (real_T) (unpackedValue);
              }

              {
                real_T result = (real_T) outValue;
                CANTestingSTM32_B.CANUnpack_o2 = result;
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 8
             *  length                  = 8
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
                    tempValue = tempValue | (uint8_T)
                      (CANTestingSTM32_B.Message_p.Data[1]);
                  }

                  unpackedValue = tempValue;
                }

                outValue = (real_T) (unpackedValue);
              }

              {
                real_T result = (real_T) outValue;
                CANTestingSTM32_B.CANUnpack_o3 = result;
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 24
             *  length                  = 8
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
                    tempValue = tempValue | (uint8_T)
                      (CANTestingSTM32_B.Message_p.Data[3]);
                  }

                  unpackedValue = tempValue;
                }

                outValue = (real_T) (unpackedValue);
              }

              {
                real_T result = (real_T) outValue;
                CANTestingSTM32_B.CANUnpack_o4 = result;
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S1>/CAN Unpack1' */
    {
      /* S-Function (scanunpack): '<S1>/CAN Unpack1' */
      if ((6 == CANTestingSTM32_B.Message.Length) &&
          (CANTestingSTM32_B.Message.ID != INVALID_CAN_ID) ) {
        if ((2 == CANTestingSTM32_B.Message.ID) && (0U ==
             CANTestingSTM32_B.Message.Extended) ) {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 32
             *  length                  = 16
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              real_T outValue = 0;

              {
                uint16_T unpackedValue = 0;

                {
                  uint16_T tempValue = (uint16_T) (0);

                  {
                    tempValue = tempValue | (uint16_T)
                      (CANTestingSTM32_B.Message.Data[4]);
                    tempValue = tempValue | (uint16_T)((uint16_T)
                      (CANTestingSTM32_B.Message.Data[5]) << 8);
                  }

                  unpackedValue = tempValue;
                }

                outValue = (real_T) (unpackedValue);
              }

              {
                real_T result = (real_T) outValue;
                CANTestingSTM32_B.CANUnpack1_o1 = result;
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 16
             *  length                  = 16
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              real_T outValue = 0;

              {
                uint16_T unpackedValue = 0;

                {
                  uint16_T tempValue = (uint16_T) (0);

                  {
                    tempValue = tempValue | (uint16_T)
                      (CANTestingSTM32_B.Message.Data[2]);
                    tempValue = tempValue | (uint16_T)((uint16_T)
                      (CANTestingSTM32_B.Message.Data[3]) << 8);
                  }

                  unpackedValue = tempValue;
                }

                outValue = (real_T) (unpackedValue);
              }

              {
                real_T result = (real_T) outValue;
                CANTestingSTM32_B.CANUnpack1_o2 = result;
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 0
             *  length                  = 16
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              real_T outValue = 0;

              {
                uint16_T unpackedValue = 0;

                {
                  uint16_T tempValue = (uint16_T) (0);

                  {
                    tempValue = tempValue | (uint16_T)
                      (CANTestingSTM32_B.Message.Data[0]);
                    tempValue = tempValue | (uint16_T)((uint16_T)
                      (CANTestingSTM32_B.Message.Data[1]) << 8);
                  }

                  unpackedValue = tempValue;
                }

                outValue = (real_T) (unpackedValue);
              }

              {
                real_T result = (real_T) outValue;
                CANTestingSTM32_B.CANUnpack1_o3 = result;
              }
            }
          }
        }
      }
    }
  }

  /* End of Logic: '<Root>/NOT4' */
  /* End of Outputs for SubSystem: '<Root>/CAN Rx' */

  /* Logic: '<Root>/AND1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   */
  rtb_AND1 = ((CANTestingSTM32_B.CANUnpack1_o1 >= 32768.0) &&
              (CANTestingSTM32_B.CANUnpack1_o3 >= 32768.0));

  /* MATLABSystem: '<S17>/Digital Port Write' */
  portNameLoc = GPIOC;
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_AND1);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_AND1 & 1U);

  /* MATLABSystem: '<S19>/Digital Port Write' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Logic: '<Root>/AND'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   */
  portNameLoc = GPIOB;
  if ((CANTestingSTM32_B.CANUnpack1_o1 >= 32768.0) &&
      (CANTestingSTM32_B.CANUnpack1_o2 >= 32768.0)) {
    rtb_Step1 = 4;
  } else {
    rtb_Step1 = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_Step1);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_Step1 & 4U);

  /* End of MATLABSystem: '<S19>/Digital Port Write' */

  /* MATLABSystem: '<S21>/Digital Port Write' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S2>/Constant'
   *  Product: '<Root>/Divide'
   *  RelationalOperator: '<S2>/Compare'
   *  Sum: '<Root>/Add'
   */
  portNameLoc = GPIOB;
  if ((((CANTestingSTM32_B.CANUnpack_o1 + CANTestingSTM32_B.CANUnpack_o2) +
        CANTestingSTM32_B.CANUnpack_o3) + CANTestingSTM32_B.CANUnpack_o4) / 4.0 >=
      64.0) {
    rtb_Step1 = 2;
  } else {
    rtb_Step1 = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)rtb_Step1);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)rtb_Step1 & 2U);

  /* End of MATLABSystem: '<S21>/Digital Port Write' */

  /* Step: '<S11>/Step1' */
  rtb_Step1 = !(((CANTestingSTM32_M->Timing.clockTick0) * 0.001) < 1.0);

  /* Outputs for Enabled SubSystem: '<S11>/MCPInit' incorporates:
   *  EnablePort: '<S25>/Enable'
   */
  /* RelationalOperator: '<S22>/FixPt Relational Operator' incorporates:
   *  Constant: '<S25>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   *  Constant: '<S25>/CANINTE'
   *  Constant: '<S25>/CNF1'
   *  Constant: '<S25>/CNF2'
   *  Constant: '<S25>/CNF3'
   *  Constant: '<S25>/Clear flags'
   *  Constant: '<S25>/Set acceptance filters'
   *  UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (rtb_Step1 > CANTestingSTM32_DW.DelayInput1_DSTATE) {
    /* MATLABSystem: '<S25>/SPI Controller Transfer' incorporates:
     *  Constant: '<S25>/Enter Configuration Mode'
     */
    rdDataRaw = MW_STM32_SPI_SetFormat(CANTestingSTM32_DW.obj.MW_SPI_HANDLE, 0U,
      1792U, MW_SPI_MODE_2);
    if (rdDataRaw == 0) {
      portNameLoc = GPIOA;
      LL_GPIO_ResetOutputPin(portNameLoc, 16U);
      MW_SPI_MasterWriteRead_Databits(CANTestingSTM32_DW.obj.MW_SPI_HANDLE,
        &CANTestingSTM32_ConstP.EnterConfigurationMode_Value, &rdDataRaw, 0, 1U,
        1, 10U);
      LL_GPIO_SetOutputPin(portNameLoc, 16U);
    }

    /* End of MATLABSystem: '<S25>/SPI Controller Transfer' */
    CANTesti_SPIControllerTransfer1(CANTestingSTM32_ConstP.CNF1_Value,
      &CANTestingSTM32_DW.SPIControllerTransfer1_p);
    CANTesti_SPIControllerTransfer1(CANTestingSTM32_ConstP.CNF2_Value,
      &CANTestingSTM32_DW.SPIControllerTransfer2);
    CANTesti_SPIControllerTransfer1(CANTestingSTM32_ConstP.CNF3_Value,
      &CANTestingSTM32_DW.SPIControllerTransfer3);
    CANTesti_SPIControllerTransfer5(CANTestingSTM32_ConstP.CANINTE_Value,
      &CANTestingSTM32_DW.SPIControllerTransfer5);
    CANTesti_SPIControllerTransfer1
      (CANTestingSTM32_ConstP.Setacceptancefilters_Value,
       &CANTestingSTM32_DW.SPIControllerTransfer6);
    CANTesti_SPIControllerTransfer5(CANTestingSTM32_ConstP.Clearflags_Value,
      &CANTestingSTM32_DW.SPIControllerTransfer7);
    CANTesti_SPIControllerTransfer1
      (CANTestingSTM32_ConstP.u00normalmode0dontabortpendingt,
       &CANTestingSTM32_DW.SPIControllerTransfer4);
  }

  /* End of RelationalOperator: '<S22>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<S11>/MCPInit' */

  /* Update for UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  CANTestingSTM32_DW.DelayInput1_DSTATE = rtb_Step1;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  CANTestingSTM32_M->Timing.clockTick0++;
}

/* Model initialize function */
void CANTestingSTM32_initialize(void)
{
  {
    STM32_SPI_ModuleStruct_T b;

    /* SystemInitialize for Enabled SubSystem: '<Root>/CAN Rx' */

    /* Start for S-Function (scanunpack): '<S1>/CAN Unpack' */

    /*-----------S-Function Block: <S1>/CAN Unpack -----------------*/

    /* Start for S-Function (scanunpack): '<S1>/CAN Unpack1' */

    /*-----------S-Function Block: <S1>/CAN Unpack1 -----------------*/
    CANT_SPIControllerTransfer_Init(&CANTestingSTM32_DW.SPIControllerTransfer);
    CANT_SPIControllerTransfer_Init(&CANTestingSTM32_DW.SPIControllerTransfer1);

    /* End of SystemInitialize for SubSystem: '<Root>/CAN Rx' */

    /* SystemInitialize for Enabled SubSystem: '<S11>/MCPInit' */
    /* Start for MATLABSystem: '<S25>/SPI Controller Transfer' */
    CANTestingSTM32_DW.obj.matlabCodegenIsDeleted = false;
    CANTestingSTM32_DW.obj.isInitialized = 1;
    b.PeripheralPtr = SPI1;
    CANTestingSTM32_DW.obj.MW_SPI_HANDLE = SPI_STM32_Init(&b);
    MW_STM32_SPI_SetFormat(CANTestingSTM32_DW.obj.MW_SPI_HANDLE, 0U, 1792U,
      MW_SPI_MODE_2);
    CANTestingSTM32_DW.obj.isSetupComplete = true;
    CAN_SPIControllerTransfer1_Init(&CANTestingSTM32_DW.SPIControllerTransfer1_p);
    CAN_SPIControllerTransfer1_Init(&CANTestingSTM32_DW.SPIControllerTransfer2);
    CAN_SPIControllerTransfer1_Init(&CANTestingSTM32_DW.SPIControllerTransfer3);
    CAN_SPIControllerTransfer5_Init(&CANTestingSTM32_DW.SPIControllerTransfer5);
    CAN_SPIControllerTransfer1_Init(&CANTestingSTM32_DW.SPIControllerTransfer6);
    CAN_SPIControllerTransfer5_Init(&CANTestingSTM32_DW.SPIControllerTransfer7);
    CAN_SPIControllerTransfer1_Init(&CANTestingSTM32_DW.SPIControllerTransfer4);

    /* End of SystemInitialize for SubSystem: '<S11>/MCPInit' */
  }

  /* user code (Initialize function Body) */
  LL_TIM_EnableCounter(TIM2);
}

/* Model terminate function */
void CANTestingSTM32_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for Enabled SubSystem: '<Root>/CAN Rx' */
  CANT_SPIControllerTransfer_Term(&CANTestingSTM32_DW.SPIControllerTransfer);
  CANT_SPIControllerTransfer_Term(&CANTestingSTM32_DW.SPIControllerTransfer1);

  /* End of Terminate for SubSystem: '<Root>/CAN Rx' */

  /* Terminate for Enabled SubSystem: '<S11>/MCPInit' */
  /* Terminate for MATLABSystem: '<S25>/SPI Controller Transfer' */
  if (!CANTestingSTM32_DW.obj.matlabCodegenIsDeleted) {
    CANTestingSTM32_DW.obj.matlabCodegenIsDeleted = true;
    if ((CANTestingSTM32_DW.obj.isInitialized == 1) &&
        CANTestingSTM32_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(CANTestingSTM32_DW.obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S25>/SPI Controller Transfer' */
  CAN_SPIControllerTransfer1_Term(&CANTestingSTM32_DW.SPIControllerTransfer1_p);
  CAN_SPIControllerTransfer1_Term(&CANTestingSTM32_DW.SPIControllerTransfer2);
  CAN_SPIControllerTransfer1_Term(&CANTestingSTM32_DW.SPIControllerTransfer3);
  CAN_SPIControllerTransfer5_Term(&CANTestingSTM32_DW.SPIControllerTransfer5);
  CAN_SPIControllerTransfer1_Term(&CANTestingSTM32_DW.SPIControllerTransfer6);
  CAN_SPIControllerTransfer5_Term(&CANTestingSTM32_DW.SPIControllerTransfer7);
  CAN_SPIControllerTransfer1_Term(&CANTestingSTM32_DW.SPIControllerTransfer4);

  /* End of Terminate for SubSystem: '<S11>/MCPInit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
