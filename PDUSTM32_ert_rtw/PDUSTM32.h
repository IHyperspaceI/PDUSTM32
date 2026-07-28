/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PDUSTM32.h
 *
 * Code generated for Simulink model 'PDUSTM32'.
 *
 * Model version                  : 13.206
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Jul 28 13:42:02 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PDUSTM32_h_
#define PDUSTM32_h_
#ifndef PDUSTM32_COMMON_INCLUDES_
#define PDUSTM32_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "math.h"
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
#include "main.h"
#endif                                 /* PDUSTM32_COMMON_INCLUDES_ */

#include "PDUSTM32_types.h"
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

/* Block states (default storage) for system '<S6>/MATLAB Function' */
typedef struct {
  uint16_T count;                      /* '<S6>/MATLAB Function' */
} DW_MATLABFunction_PDUSTM32_c_T;

/* Block states (default storage) for system '<S6>/SPI Controller Transfer' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S6>/SPI Controller Transfer' */
  boolean_T objisempty;                /* '<S6>/SPI Controller Transfer' */
} DW_SPIControllerTransfer_PDUS_T;

/* Block states (default storage) for system '<S6>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S6>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S6>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_PDU_T;

/* Block states (default storage) for system '<S36>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S36>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S36>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_P_f_T;

/* Block states (default storage) for system '<S36>/SPI Controller Transfer5' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S36>/SPI Controller Transfer5' */
  boolean_T objisempty;                /* '<S36>/SPI Controller Transfer5' */
} DW_SPIControllerTransfer5_PDU_T;

/* Block signals (default storage) */
typedef struct {
  CAN_MESSAGE_def Message;             /* '<Root>/MATLAB Function' */
  CAN_MESSAGE_BUS CANPack1;            /* '<S6>/CAN Pack1' */
  CAN_MESSAGE_BUS CANPack2;            /* '<S6>/CAN Pack2' */
  CAN_MESSAGE_BUS CANPack3;            /* '<S6>/CAN Pack3' */
  real_T CANUnpack_o1;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o2;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o3;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o4;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o5;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o6;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o7;                 /* '<Root>/CAN Unpack' */
  real_T CANUnpack_o8;                 /* '<Root>/CAN Unpack' */
  real_T Voltage;                      /* '<S4>/MATLAB Function' */
  real_T Voltage_g;                    /* '<S3>/MATLAB Function' */
  real_T Voltage_k;                    /* '<S2>/MATLAB Function' */
  real_T Voltage_a;                    /* '<S1>/MATLAB Function' */
  real32_T Gain4[7];                   /* '<Root>/Gain4' */
  real32_T Gain;                       /* '<Root>/Gain' */
  boolean_T OutportBufferForMCPInitialized;/* '<S35>/Constant' */
} B_PDUSTM32_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S36>/SPI Controller Transfer' */
  stm32cube_blocks_SPIControlle_T obj_c;/* '<Root>/SPI Controller Transfer' */
  stm32cube_blocks_SPIControlle_T obj_e;/* '<S4>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_o;/* '<S3>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_d;/* '<S2>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_l;/* '<S1>/SPI Controller Transfer1' */
  stm32cube_blocks_AnalogInputF_T obj_n;/* '<S22>/Analog to Digital Converter' */
  real_T UnitDelay_DSTATE;             /* '<S13>/Unit Delay' */
  real_T DelayInput1_DSTATE;           /* '<S34>/Delay Input1' */
  int_T CANUnpack_ModeSignalID;        /* '<Root>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<Root>/CAN Unpack' */
  int_T CANPack1_ModeSignalID;         /* '<S6>/CAN Pack1' */
  int_T CANPack2_ModeSignalID;         /* '<S6>/CAN Pack2' */
  int_T CANPack3_ModeSignalID;         /* '<S6>/CAN Pack3' */
  DW_SPIControllerTransfer5_PDU_T SPIControllerTransfer7;/* '<S36>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer1_P_f_T SPIControllerTransfer6;/* '<S36>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer5_PDU_T SPIControllerTransfer5_p;/* '<S36>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer1_P_f_T SPIControllerTransfer4_p;/* '<S36>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_P_f_T SPIControllerTransfer3_p;/* '<S36>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_P_f_T SPIControllerTransfer2_p;/* '<S36>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_P_f_T SPIControllerTransfer1_pnaev;/* '<S36>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_PDU_T SPIControllerTransfer5;/* '<S6>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer_PDUS_T SPIControllerTransfer4;/* '<S6>/SPI Controller Transfer' */
  DW_SPIControllerTransfer1_PDU_T SPIControllerTransfer3;/* '<S6>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer_PDUS_T SPIControllerTransfer2;/* '<S6>/SPI Controller Transfer' */
  DW_SPIControllerTransfer1_PDU_T SPIControllerTransfer1_pnae;/* '<S6>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer_PDUS_T SPIControllerTransfer;/* '<S6>/SPI Controller Transfer' */
  DW_MATLABFunction_PDUSTM32_c_T sf_MATLABFunction2;/* '<S6>/MATLAB Function2' */
  DW_MATLABFunction_PDUSTM32_c_T sf_MATLABFunction1;/* '<S6>/MATLAB Function1' */
  DW_MATLABFunction_PDUSTM32_c_T sf_MATLABFunction_o;/* '<S6>/MATLAB Function' */
} DW_PDUSTM32_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T Constant;            /* '<S35>/Constant' */
} ConstB_PDUSTM32_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: 0xc0
   * Referenced by: '<S36>/Enter Configuration Mode'
   */
  uint8_T EnterConfigurationMode_Value;

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S36>/CNF1'
   */
  uint8_T CNF1_Value[3];

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S36>/CNF2'
   */
  uint8_T CNF2_Value[3];

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S36>/CNF3'
   */
  uint8_T CNF3_Value[3];

  /* Expression: [0x05, 0x2B, 0xFF, 0x01]
   * Referenced by: '<S36>/CANINTE'
   */
  uint8_T CANINTE_Value[4];

  /* Expression: [0x02, 0x60, 0x60]
   * Referenced by: '<S36>/Set acceptance filters'
   */
  uint8_T Setacceptancefilters_Value[3];

  /* Expression: [0x05, 0x2C, 0xFF, 0x00]
   * Referenced by: '<S36>/Clear flags'
   */
  uint8_T Clearflags_Value[4];

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S36>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  uint8_T u00normalmode0dontabortpendingt[3];

  /* Expression: uint8([0x90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
   * Referenced by: '<Root>/Read RX Buffer start at RXB0SIDH'
   */
  uint8_T ReadRXBufferstartatRXB0SIDH_Val[14];

  /* Pooled Parameter (Expression: uint8([0, 0]))
   * Referenced by:
   *   '<S1>/Dummy Bits'
   *   '<S2>/Dummy Bits'
   *   '<S3>/Dummy Bits'
   *   '<S4>/Dummy Bits'
   */
  uint8_T pooled5[2];
} ConstP_PDUSTM32_T;

/* Real-time Model Data Structure */
struct tag_RTM_PDUSTM32_T {
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
extern B_PDUSTM32_T PDUSTM32_B;

/* Block states (default storage) */
extern DW_PDUSTM32_T PDUSTM32_DW;
extern const ConstB_PDUSTM32_T PDUSTM32_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_PDUSTM32_T PDUSTM32_ConstP;

/* Model entry point functions */
extern void PDUSTM32_initialize(void);
extern void PDUSTM32_step(void);
extern void PDUSTM32_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PDUSTM32_T *const PDUSTM32_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Compare' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/FixPt Constant' : Unused code path elimination
 * Block '<S26>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/FixPt Sum1' : Unused code path elimination
 * Block '<S8>/Output' : Unused code path elimination
 * Block '<S27>/Constant' : Unused code path elimination
 * Block '<S27>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S27>/FixPt Switch' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion3' : Unused code path elimination
 * Block '<Root>/Data Type Conversion4' : Unused code path elimination
 * Block '<Root>/Data Type Conversion6' : Unused code path elimination
 * Block '<Root>/Data Type Conversion7' : Unused code path elimination
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
 * '<Root>' : 'PDUSTM32'
 * '<S1>'   : 'PDUSTM32/ADC121S021 1'
 * '<S2>'   : 'PDUSTM32/ADC121S021 2'
 * '<S3>'   : 'PDUSTM32/ADC121S021 3'
 * '<S4>'   : 'PDUSTM32/ADC121S021 4'
 * '<S5>'   : 'PDUSTM32/Analog to Digital Converter'
 * '<S6>'   : 'PDUSTM32/CAN Tx'
 * '<S7>'   : 'PDUSTM32/Compare To Constant'
 * '<S8>'   : 'PDUSTM32/Counter Limited'
 * '<S9>'   : 'PDUSTM32/Digital Port Read1'
 * '<S10>'  : 'PDUSTM32/Digital Port Write'
 * '<S11>'  : 'PDUSTM32/Digital Port Write1'
 * '<S12>'  : 'PDUSTM32/MATLAB Function'
 * '<S13>'  : 'PDUSTM32/Subsystem1'
 * '<S14>'  : 'PDUSTM32/Switches1'
 * '<S15>'  : 'PDUSTM32/Switches2'
 * '<S16>'  : 'PDUSTM32/Switches3'
 * '<S17>'  : 'PDUSTM32/ADC121S021 1/MATLAB Function'
 * '<S18>'  : 'PDUSTM32/ADC121S021 2/MATLAB Function'
 * '<S19>'  : 'PDUSTM32/ADC121S021 3/MATLAB Function'
 * '<S20>'  : 'PDUSTM32/ADC121S021 4/MATLAB Function'
 * '<S21>'  : 'PDUSTM32/Analog to Digital Converter/ECSoC'
 * '<S22>'  : 'PDUSTM32/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S23>'  : 'PDUSTM32/CAN Tx/MATLAB Function'
 * '<S24>'  : 'PDUSTM32/CAN Tx/MATLAB Function1'
 * '<S25>'  : 'PDUSTM32/CAN Tx/MATLAB Function2'
 * '<S26>'  : 'PDUSTM32/Counter Limited/Increment Real World'
 * '<S27>'  : 'PDUSTM32/Counter Limited/Wrap To Zero'
 * '<S28>'  : 'PDUSTM32/Digital Port Read1/ECSoC'
 * '<S29>'  : 'PDUSTM32/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S30>'  : 'PDUSTM32/Digital Port Write/ECSoC'
 * '<S31>'  : 'PDUSTM32/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S32>'  : 'PDUSTM32/Digital Port Write1/ECSoC'
 * '<S33>'  : 'PDUSTM32/Digital Port Write1/ECSoC/ECSimCodegen'
 * '<S34>'  : 'PDUSTM32/Subsystem1/Detect Increase'
 * '<S35>'  : 'PDUSTM32/Subsystem1/Initialize'
 * '<S36>'  : 'PDUSTM32/Subsystem1/MCPInit'
 * '<S37>'  : 'PDUSTM32/Switches1/ECSoC'
 * '<S38>'  : 'PDUSTM32/Switches1/ECSoC/ECSimCodegen'
 * '<S39>'  : 'PDUSTM32/Switches2/ECSoC'
 * '<S40>'  : 'PDUSTM32/Switches2/ECSoC/ECSimCodegen'
 * '<S41>'  : 'PDUSTM32/Switches3/ECSoC'
 * '<S42>'  : 'PDUSTM32/Switches3/ECSoC/ECSimCodegen'
 */
#endif                                 /* PDUSTM32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
