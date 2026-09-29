/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_of_PDUSTM32_private.h
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

#ifndef Copy_of_PDUSTM32_private_h_
#define Copy_of_PDUSTM32_private_h_
#include "rtwtypes.h"
#include "Copy_of_PDUSTM32.h"
#include "Copy_of_PDUSTM32_types.h"
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
extern void Copy_of_PDUSTM32_MATLABFunction(const uint8_T rtu_Counts[2], real_T
  rtu_VA, real_T *rty_Voltage);
extern void Copy_of_PD_DigitalPortRead_Init(DW_DigitalPortRead_Copy_of_PD_T
  *localDW);
extern void Copy_of_PDUSTM3_DigitalPortRead(B_DigitalPortRead_Copy_of_PDU_T
  *localB);
extern void Copy_of_P_EnabledSubsystem_Init(DW_EnabledSubsystem_Copy_of_P_T
  *localDW);
extern void Copy_of_PDUSTM_EnabledSubsystem(boolean_T rtu_Enable, CANMessage
  *rty_CANMessage, DW_EnabledSubsystem_Copy_of_P_T *localDW);
extern void Copy_of_PDUSTM3_MATLABFunction2(uint32_T rtu_ID, uint8_T rtu_Length,
  const uint8_T rtu_Data[8], uint8_T rtu_RTS, uint16_T rtu_period, uint16_T
  rtu_offset, boolean_T rtu_MCPInitialized, uint8_T *rty_WriteInstruction,
  uint8_T rty_CANVector[13], uint8_T *rty_RTSByte,
  DW_MATLABFunction2_Copy_of_PD_T *localDW);
extern void Cop_SPIControllerTransfer4_Init(DW_SPIControllerTransfer4_Cop_T
  *localDW);
extern void Copy_of__SPIControllerTransfer4(const uint8_T rtu_0[15],
  DW_SPIControllerTransfer4_Cop_T *localDW);
extern void Cop_SPIControllerTransfer5_Init(DW_SPIControllerTransfer5_Cop_T
  *localDW);
extern void Copy_of__SPIControllerTransfer5(uint8_T rtu_0,
  DW_SPIControllerTransfer5_Cop_T *localDW);
extern void Cop_SPIControllerTransfer1_Init(DW_SPIControllerTransfer1_Cop_T
  *localDW);
extern void Copy_of__SPIControllerTransfer1(const uint8_T rtu_0[3],
  DW_SPIControllerTransfer1_Cop_T *localDW);
extern void C_SPIControllerTransfer5_l_Init(DW_SPIControllerTransfer5_C_f_T
  *localDW);
extern void Copy_o_SPIControllerTransfer5_p(const uint8_T rtu_0[4],
  DW_SPIControllerTransfer5_C_f_T *localDW);
extern void Copy_of_P_EnabledSubsystem_Term(DW_EnabledSubsystem_Copy_of_P_T
  *localDW);
extern void Cop_SPIControllerTransfer4_Term(DW_SPIControllerTransfer4_Cop_T
  *localDW);
extern void Cop_SPIControllerTransfer5_Term(DW_SPIControllerTransfer5_Cop_T
  *localDW);
extern void Cop_SPIControllerTransfer1_Term(DW_SPIControllerTransfer1_Cop_T
  *localDW);
extern void C_SPIControllerTransfer5_o_Term(DW_SPIControllerTransfer5_C_f_T
  *localDW);

#endif                                 /* Copy_of_PDUSTM32_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
