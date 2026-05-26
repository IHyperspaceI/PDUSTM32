/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CANTestingSTM32_private.h
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

#ifndef CANTestingSTM32_private_h_
#define CANTestingSTM32_private_h_
#include "rtwtypes.h"
#include "CANTestingSTM32_types.h"
#include "CANTestingSTM32.h"

extern void CANTestingSTM32_MATLABFunction(const uint8_T rtu_RxBytes[14],
  CAN_MESSAGE_def *rty_Message);
extern void CANT_SPIControllerTransfer_Init(DW_SPIControllerTransfer_CANT_T
  *localDW);
extern void CANTestin_SPIControllerTransfer(const uint8_T rtu_0[14],
  B_SPIControllerTransfer_CANTe_T *localB, DW_SPIControllerTransfer_CANT_T
  *localDW);
extern void CAN_SPIControllerTransfer1_Init(DW_SPIControllerTransfer1_CAN_T
  *localDW);
extern void CANTesti_SPIControllerTransfer1(const uint8_T rtu_0[3],
  DW_SPIControllerTransfer1_CAN_T *localDW);
extern void CAN_SPIControllerTransfer5_Init(DW_SPIControllerTransfer5_CAN_T
  *localDW);
extern void CANTesti_SPIControllerTransfer5(const uint8_T rtu_0[4],
  DW_SPIControllerTransfer5_CAN_T *localDW);
extern void CANT_SPIControllerTransfer_Term(DW_SPIControllerTransfer_CANT_T
  *localDW);
extern void CAN_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_CAN_T
  *localDW);
extern void CAN_SPIControllerTransfer5_Term(DW_SPIControllerTransfer5_CAN_T
  *localDW);

#endif                                 /* CANTestingSTM32_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
