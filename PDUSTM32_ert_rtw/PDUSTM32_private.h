/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PDUSTM32_private.h
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

#ifndef PDUSTM32_private_h_
#define PDUSTM32_private_h_
#include "rtwtypes.h"
#include "PDUSTM32_types.h"
#include "PDUSTM32.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
extern void PDUSTM32_MATLABFunction(const uint8_T rtu_Counts[2], real_T rtu_VA,
  real_T *rty_Voltage);
extern void PDUSTM32_MATLABFunction_f(const uint8_T rtu_RxBytes[14],
  CAN_MESSAGE_def *rty_Message);
extern void PDUS_SPIControllerTransfer_Init(DW_SPIControllerTransfer_PDUS_T
  *localDW);
extern void PDUSTM32_SPIControllerTransfer(const uint8_T rtu_0[14],
  B_SPIControllerTransfer_PDUST_T *localB, DW_SPIControllerTransfer_PDUS_T
  *localDW);
extern void PDUSTM32_MATLABFunction_o(uint32_T rtu_ID, uint8_T rtu_Length, const
  uint8_T rtu_Data[8], uint8_T rtu_RTS, uint16_T rtu_period, uint16_T rtu_offset,
  boolean_T rtu_MCPInitialized, uint8_T *rty_WriteInstruction, uint8_T
  rty_CANVector[13], uint8_T *rty_RTSByte, DW_MATLABFunction_PDUSTM32_c_T
  *localDW);
extern void PD_SPIControllerTransfer_o_Init(DW_SPIControllerTransfer_PD_f_T
  *localDW);
extern void PDUSTM3_SPIControllerTransfer_p(const uint8_T rtu_0[15],
  DW_SPIControllerTransfer_PD_f_T *localDW);
extern void PDU_SPIControllerTransfer1_Init(DW_SPIControllerTransfer1_PDU_T
  *localDW);
extern void PDUSTM32_SPIControllerTransfer1(const uint8_T rtu_0[3],
  DW_SPIControllerTransfer1_PDU_T *localDW);
extern void PDUS_SPIControllerTransfer_Term(DW_SPIControllerTransfer_PDUS_T
  *localDW);
extern void PD_SPIControllerTransfer_i_Term(DW_SPIControllerTransfer_PD_f_T
  *localDW);
extern void PDU_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_PDU_T
  *localDW);

#endif                                 /* PDUSTM32_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
