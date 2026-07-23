/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PDUSTM32.h
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

/* Block signals for system '<S6>/SPI Controller Transfer' */
typedef struct {
  uint8_T SPIControllerTransfer[14];   /* '<S6>/SPI Controller Transfer' */
} B_SPIControllerTransfer_PDUST_T;

/* Block states (default storage) for system '<S6>/SPI Controller Transfer' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S6>/SPI Controller Transfer' */
  boolean_T objisempty;                /* '<S6>/SPI Controller Transfer' */
} DW_SPIControllerTransfer_PDUS_T;

/* Block states (default storage) for system '<S7>/MATLAB Function' */
typedef struct {
  uint16_T count;                      /* '<S7>/MATLAB Function' */
} DW_MATLABFunction_PDUSTM32_c_T;

/* Block states (default storage) for system '<S7>/SPI Controller Transfer' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S7>/SPI Controller Transfer' */
  boolean_T objisempty;                /* '<S7>/SPI Controller Transfer' */
} DW_SPIControllerTransfer_PD_f_T;

/* Block states (default storage) for system '<S31>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S31>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S31>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_PDU_T;

/* Block signals (default storage) */
typedef struct {
  CAN_MESSAGE_def Message;             /* '<S6>/MATLAB Function1' */
  CAN_MESSAGE_def Message_p;           /* '<S6>/MATLAB Function' */
  CAN_MESSAGE_BUS CANPack1;            /* '<S7>/CAN Pack1' */
  CAN_MESSAGE_BUS CANPack2;            /* '<S7>/CAN Pack2' */
  CAN_MESSAGE_BUS CANPack3;            /* '<S7>/CAN Pack3' */
  real_T CANUnpack1_o2;                /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o3;                /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o4;                /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o5;                /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o6;                /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o7;                /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o8;                /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o9;                /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o10;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o11;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o12;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o13;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o14;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o15;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o16;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o17;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o18;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o19;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o20;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o21;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o22;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o23;               /* '<S6>/CAN Unpack1' */
  real_T CANUnpack1_o24;               /* '<S6>/CAN Unpack1' */
  real_T Voltage;                      /* '<S4>/MATLAB Function' */
  real_T Voltage_g;                    /* '<S3>/MATLAB Function' */
  real_T Voltage_k;                    /* '<S2>/MATLAB Function' */
  real_T Voltage_a;                    /* '<S1>/MATLAB Function' */
  real32_T Gain4[7];                   /* '<Root>/Gain4' */
  boolean_T OutportBufferForMCPInitialized;/* '<S30>/Constant' */
  boolean_T CANUnpack_o1;              /* '<S6>/CAN Unpack' */
  boolean_T CANUnpack_o2;              /* '<S6>/CAN Unpack' */
  boolean_T CANUnpack_o3;              /* '<S6>/CAN Unpack' */
  boolean_T CANUnpack_o4;              /* '<S6>/CAN Unpack' */
  boolean_T CANUnpack_o5;              /* '<S6>/CAN Unpack' */
  boolean_T CANUnpack_o6;              /* '<S6>/CAN Unpack' */
  boolean_T CANUnpack_o7;              /* '<S6>/CAN Unpack' */
  boolean_T CANUnpack1_o1;             /* '<S6>/CAN Unpack1' */
  B_SPIControllerTransfer_PDUST_T SPIControllerTransfer1_pnae;/* '<S6>/SPI Controller Transfer' */
  B_SPIControllerTransfer_PDUST_T SPIControllerTransfer_p;/* '<S6>/SPI Controller Transfer' */
} B_PDUSTM32_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S31>/SPI Controller Transfer' */
  stm32cube_blocks_SPIControlle_T obj_e;/* '<Root>/SPI Controller Transfer3' */
  stm32cube_blocks_SPIControlle_T obj_e2;/* '<S4>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_o;/* '<S3>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_d;/* '<S2>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_l;/* '<S1>/SPI Controller Transfer1' */
  stm32cube_blocks_AnalogInputF_T obj_n;/* '<S19>/Analog to Digital Converter' */
  real_T UnitDelay_DSTATE;             /* '<S10>/Unit Delay' */
  real_T DelayInput1_DSTATE;           /* '<S29>/Delay Input1' */
  int_T CANPack1_ModeSignalID;         /* '<S7>/CAN Pack1' */
  int_T CANPack2_ModeSignalID;         /* '<S7>/CAN Pack2' */
  int_T CANPack3_ModeSignalID;         /* '<S7>/CAN Pack3' */
  int_T CANUnpack_ModeSignalID;        /* '<S6>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<S6>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<S6>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<S6>/CAN Unpack1' */
  boolean_T UnitDelay_DSTATE_j;        /* '<Root>/Unit Delay' */
  DW_SPIControllerTransfer1_PDU_T SPIControllerTransfer4_p;/* '<S31>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_PDU_T SPIControllerTransfer3_p;/* '<S31>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_PDU_T SPIControllerTransfer2_p;/* '<S31>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_PDU_T SPIControllerTransfer1_pnaev;/* '<S31>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer_PD_f_T SPIControllerTransfer4;/* '<S7>/SPI Controller Transfer' */
  DW_SPIControllerTransfer_PD_f_T SPIControllerTransfer2;/* '<S7>/SPI Controller Transfer' */
  DW_SPIControllerTransfer_PD_f_T SPIControllerTransfer;/* '<S7>/SPI Controller Transfer' */
  DW_MATLABFunction_PDUSTM32_c_T sf_MATLABFunction2;/* '<S7>/MATLAB Function2' */
  DW_MATLABFunction_PDUSTM32_c_T sf_MATLABFunction1;/* '<S7>/MATLAB Function1' */
  DW_MATLABFunction_PDUSTM32_c_T sf_MATLABFunction_o;/* '<S7>/MATLAB Function' */
  DW_SPIControllerTransfer_PDUS_T SPIControllerTransfer1_pnae;/* '<S6>/SPI Controller Transfer' */
  DW_SPIControllerTransfer_PDUS_T SPIControllerTransfer_p;/* '<S6>/SPI Controller Transfer' */
} DW_PDUSTM32_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T Constant;            /* '<S30>/Constant' */
} ConstB_PDUSTM32_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: uint8([0x90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]))
   * Referenced by:
   *   '<S6>/Read RX Buffer start at RXB0SIDH'
   *   '<S6>/Read RX Buffer start at RXB0SIDH1'
   */
  uint8_T pooled6[14];

  /* Expression: 0xc0
   * Referenced by: '<S31>/Enter Configuration Mode'
   */
  uint8_T EnterConfigurationMode_Value;

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S31>/CNF1'
   */
  uint8_T CNF1_Value[3];

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S31>/CNF2'
   */
  uint8_T CNF2_Value[3];

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S31>/CNF3'
   */
  uint8_T CNF3_Value[3];

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S31>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  uint8_T u00normalmode0dontabortpendingt[3];

  /* Pooled Parameter (Expression: uint8([0, 0]))
   * Referenced by:
   *   '<S1>/Dummy Bits'
   *   '<S2>/Dummy Bits'
   *   '<S3>/Dummy Bits'
   *   '<S4>/Dummy Bits'
   */
  uint8_T pooled7[2];

  /* Pooled Parameter (Expression: 0x81)
   * Referenced by:
   *   '<Root>/RTS0'
   *   '<S7>/RTS'
   *   '<S7>/RTS1'
   *   '<S7>/RTS2'
   */
  uint8_T pooled8;
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
 * '<S6>'   : 'PDUSTM32/CAN Rx'
 * '<S7>'   : 'PDUSTM32/CAN Tx'
 * '<S8>'   : 'PDUSTM32/Digital Port Read1'
 * '<S9>'   : 'PDUSTM32/Digital Port Write'
 * '<S10>'  : 'PDUSTM32/Subsystem1'
 * '<S11>'  : 'PDUSTM32/Switches1'
 * '<S12>'  : 'PDUSTM32/Switches2'
 * '<S13>'  : 'PDUSTM32/Switches3'
 * '<S14>'  : 'PDUSTM32/ADC121S021 1/MATLAB Function'
 * '<S15>'  : 'PDUSTM32/ADC121S021 2/MATLAB Function'
 * '<S16>'  : 'PDUSTM32/ADC121S021 3/MATLAB Function'
 * '<S17>'  : 'PDUSTM32/ADC121S021 4/MATLAB Function'
 * '<S18>'  : 'PDUSTM32/Analog to Digital Converter/ECSoC'
 * '<S19>'  : 'PDUSTM32/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S20>'  : 'PDUSTM32/CAN Rx/MATLAB Function'
 * '<S21>'  : 'PDUSTM32/CAN Rx/MATLAB Function1'
 * '<S22>'  : 'PDUSTM32/CAN Tx/MATLAB Function'
 * '<S23>'  : 'PDUSTM32/CAN Tx/MATLAB Function1'
 * '<S24>'  : 'PDUSTM32/CAN Tx/MATLAB Function2'
 * '<S25>'  : 'PDUSTM32/Digital Port Read1/ECSoC'
 * '<S26>'  : 'PDUSTM32/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S27>'  : 'PDUSTM32/Digital Port Write/ECSoC'
 * '<S28>'  : 'PDUSTM32/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S29>'  : 'PDUSTM32/Subsystem1/Detect Increase'
 * '<S30>'  : 'PDUSTM32/Subsystem1/Initialize'
 * '<S31>'  : 'PDUSTM32/Subsystem1/MCPInit'
 * '<S32>'  : 'PDUSTM32/Switches1/ECSoC'
 * '<S33>'  : 'PDUSTM32/Switches1/ECSoC/ECSimCodegen'
 * '<S34>'  : 'PDUSTM32/Switches2/ECSoC'
 * '<S35>'  : 'PDUSTM32/Switches2/ECSoC/ECSimCodegen'
 * '<S36>'  : 'PDUSTM32/Switches3/ECSoC'
 * '<S37>'  : 'PDUSTM32/Switches3/ECSoC/ECSimCodegen'
 */
#endif                                 /* PDUSTM32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
