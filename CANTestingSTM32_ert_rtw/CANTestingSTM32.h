/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CANTestingSTM32.h
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

#ifndef CANTestingSTM32_h_
#define CANTestingSTM32_h_
#ifndef CANTestingSTM32_COMMON_INCLUDES_
#define CANTestingSTM32_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
#include "main.h"
#endif                                 /* CANTestingSTM32_COMMON_INCLUDES_ */

#include "CANTestingSTM32_types.h"
#include <stddef.h>
#include "can_message.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "stm32h7xx_ll_tim.h"

/* Block signals for system '<S1>/SPI Controller Transfer' */
typedef struct {
  uint8_T SPIControllerTransfer[14];   /* '<S1>/SPI Controller Transfer' */
} B_SPIControllerTransfer_CANTe_T;

/* Block states (default storage) for system '<S1>/SPI Controller Transfer' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S1>/SPI Controller Transfer' */
  boolean_T objisempty;                /* '<S1>/SPI Controller Transfer' */
} DW_SPIControllerTransfer_CANT_T;

/* Block states (default storage) for system '<S25>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S25>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S25>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_CAN_T;

/* Block states (default storage) for system '<S25>/SPI Controller Transfer5' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S25>/SPI Controller Transfer5' */
  boolean_T objisempty;                /* '<S25>/SPI Controller Transfer5' */
} DW_SPIControllerTransfer5_CAN_T;

/* Block signals (default storage) */
typedef struct {
  CAN_MESSAGE_def Message;             /* '<S1>/MATLAB Function1' */
  CAN_MESSAGE_def Message_p;           /* '<S1>/MATLAB Function' */
  real_T CANUnpack_o1;                 /* '<S1>/CAN Unpack' */
  real_T CANUnpack_o2;                 /* '<S1>/CAN Unpack' */
  real_T CANUnpack_o3;                 /* '<S1>/CAN Unpack' */
  real_T CANUnpack_o4;                 /* '<S1>/CAN Unpack' */
  real_T CANUnpack1_o1;                /* '<S1>/CAN Unpack1' */
  real_T CANUnpack1_o2;                /* '<S1>/CAN Unpack1' */
  real_T CANUnpack1_o3;                /* '<S1>/CAN Unpack1' */
  B_SPIControllerTransfer_CANTe_T SPIControllerTransfer1;/* '<S1>/SPI Controller Transfer' */
  B_SPIControllerTransfer_CANTe_T SPIControllerTransfer;/* '<S1>/SPI Controller Transfer' */
} B_CANTestingSTM32_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S25>/SPI Controller Transfer' */
  real_T DelayInput1_DSTATE;           /* '<S22>/Delay Input1' */
  int_T CANUnpack_ModeSignalID;        /* '<S1>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<S1>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<S1>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<S1>/CAN Unpack1' */
  DW_SPIControllerTransfer5_CAN_T SPIControllerTransfer7;/* '<S25>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer1_CAN_T SPIControllerTransfer6;/* '<S25>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer5_CAN_T SPIControllerTransfer5;/* '<S25>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer1_CAN_T SPIControllerTransfer4;/* '<S25>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_CAN_T SPIControllerTransfer3;/* '<S25>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_CAN_T SPIControllerTransfer2;/* '<S25>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_CAN_T SPIControllerTransfer1_p;/* '<S25>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer_CANT_T SPIControllerTransfer1;/* '<S1>/SPI Controller Transfer' */
  DW_SPIControllerTransfer_CANT_T SPIControllerTransfer;/* '<S1>/SPI Controller Transfer' */
} DW_CANTestingSTM32_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: uint8([0x90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]))
   * Referenced by:
   *   '<S1>/Read RX Buffer start at RXB0SIDH'
   *   '<S1>/Read RX Buffer start at RXB0SIDH1'
   */
  uint8_T pooled4[14];

  /* Expression: 0xc0
   * Referenced by: '<S25>/Enter Configuration Mode'
   */
  uint8_T EnterConfigurationMode_Value;

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S25>/CNF1'
   */
  uint8_T CNF1_Value[3];

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S25>/CNF2'
   */
  uint8_T CNF2_Value[3];

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S25>/CNF3'
   */
  uint8_T CNF3_Value[3];

  /* Expression: [0x05, 0x2B, 0xFF, 0x01]
   * Referenced by: '<S25>/CANINTE'
   */
  uint8_T CANINTE_Value[4];

  /* Expression: [0x02, 0x60, 0x60]
   * Referenced by: '<S25>/Set acceptance filters'
   */
  uint8_T Setacceptancefilters_Value[3];

  /* Expression: [0x05, 0x2C, 0xFF, 0x00]
   * Referenced by: '<S25>/Clear flags'
   */
  uint8_T Clearflags_Value[4];

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S25>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  uint8_T u00normalmode0dontabortpendingt[3];
} ConstP_CANTestingSTM32_T;

/* Real-time Model Data Structure */
struct tag_RTM_CANTestingSTM32_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

extern CAN_DATATYPE CAN_DATATYPE_GROUND;

/* Block signals (default storage) */
extern B_CANTestingSTM32_T CANTestingSTM32_B;

/* Block states (default storage) */
extern DW_CANTestingSTM32_T CANTestingSTM32_DW;

/* Constant parameters (default storage) */
extern const ConstP_CANTestingSTM32_T CANTestingSTM32_ConstP;

/* Model entry point functions */
extern void CANTestingSTM32_initialize(void);
extern void CANTestingSTM32_step(void);
extern void CANTestingSTM32_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CANTestingSTM32_T *const CANTestingSTM32_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S24>/Constant' : Unused code path elimination
 */

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
 * '<Root>' : 'CANTestingSTM32'
 * '<S1>'   : 'CANTestingSTM32/CAN Rx'
 * '<S2>'   : 'CANTestingSTM32/Compare To Constant'
 * '<S3>'   : 'CANTestingSTM32/Compare To Constant1'
 * '<S4>'   : 'CANTestingSTM32/Compare To Constant2'
 * '<S5>'   : 'CANTestingSTM32/Compare To Constant3'
 * '<S6>'   : 'CANTestingSTM32/Compare To Constant4'
 * '<S7>'   : 'CANTestingSTM32/Digital Port Read1'
 * '<S8>'   : 'CANTestingSTM32/Digital Port Write1'
 * '<S9>'   : 'CANTestingSTM32/Digital Port Write2'
 * '<S10>'  : 'CANTestingSTM32/Digital Port Write3'
 * '<S11>'  : 'CANTestingSTM32/Subsystem'
 * '<S12>'  : 'CANTestingSTM32/CAN Rx/MATLAB Function'
 * '<S13>'  : 'CANTestingSTM32/CAN Rx/MATLAB Function1'
 * '<S14>'  : 'CANTestingSTM32/Digital Port Read1/ECSoC'
 * '<S15>'  : 'CANTestingSTM32/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S16>'  : 'CANTestingSTM32/Digital Port Write1/ECSoC'
 * '<S17>'  : 'CANTestingSTM32/Digital Port Write1/ECSoC/ECSimCodegen'
 * '<S18>'  : 'CANTestingSTM32/Digital Port Write2/ECSoC'
 * '<S19>'  : 'CANTestingSTM32/Digital Port Write2/ECSoC/ECSimCodegen'
 * '<S20>'  : 'CANTestingSTM32/Digital Port Write3/ECSoC'
 * '<S21>'  : 'CANTestingSTM32/Digital Port Write3/ECSoC/ECSimCodegen'
 * '<S22>'  : 'CANTestingSTM32/Subsystem/Detect Increase'
 * '<S23>'  : 'CANTestingSTM32/Subsystem/Detect Increase1'
 * '<S24>'  : 'CANTestingSTM32/Subsystem/Initialize'
 * '<S25>'  : 'CANTestingSTM32/Subsystem/MCPInit'
 */
#endif                                 /* CANTestingSTM32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
