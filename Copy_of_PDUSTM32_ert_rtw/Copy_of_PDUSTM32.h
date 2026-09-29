/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Copy_of_PDUSTM32.h
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

#ifndef Copy_of_PDUSTM32_h_
#define Copy_of_PDUSTM32_h_
#ifndef Copy_of_PDUSTM32_COMMON_INCLUDES_
#define Copy_of_PDUSTM32_COMMON_INCLUDES_
#include <math.h>
#include "rtwtypes.h"
#include "math.h"
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
#include "main.h"
#endif                                 /* Copy_of_PDUSTM32_COMMON_INCLUDES_ */

#include "Copy_of_PDUSTM32_types.h"
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

/* Block signals for system '<S36>/Digital Port Read' */
typedef struct {
  boolean_T DigitalPortRead;           /* '<S36>/Digital Port Read' */
} B_DigitalPortRead_Copy_of_PDU_T;

/* Block states (default storage) for system '<S36>/Digital Port Read' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S36>/Digital Port Read' */
  boolean_T objisempty;                /* '<S36>/Digital Port Read' */
} DW_DigitalPortRead_Copy_of_PD_T;

/* Block states (default storage) for system '<S31>/Enabled Subsystem' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S34>/SPI Controller Transfer7' */
  boolean_T objisempty;                /* '<S34>/SPI Controller Transfer7' */
} DW_EnabledSubsystem_Copy_of_P_T;

/* Block states (default storage) for system '<S7>/MATLAB Function2' */
typedef struct {
  uint16_T count;                      /* '<S7>/MATLAB Function2' */
} DW_MATLABFunction2_Copy_of_PD_T;

/* Block states (default storage) for system '<S7>/SPI Controller Transfer4' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S7>/SPI Controller Transfer4' */
  boolean_T objisempty;                /* '<S7>/SPI Controller Transfer4' */
} DW_SPIControllerTransfer4_Cop_T;

/* Block states (default storage) for system '<S7>/SPI Controller Transfer5' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S7>/SPI Controller Transfer5' */
  boolean_T objisempty;                /* '<S7>/SPI Controller Transfer5' */
} DW_SPIControllerTransfer5_Cop_T;

/* Block states (default storage) for system '<S60>/SPI Controller Transfer1' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S60>/SPI Controller Transfer1' */
  boolean_T objisempty;                /* '<S60>/SPI Controller Transfer1' */
} DW_SPIControllerTransfer1_Cop_T;

/* Block states (default storage) for system '<S60>/SPI Controller Transfer5' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S60>/SPI Controller Transfer5' */
  boolean_T objisempty;                /* '<S60>/SPI Controller Transfer5' */
} DW_SPIControllerTransfer5_C_f_T;

/* Block signals (default storage) */
typedef struct {
  CAN_MESSAGE_BUS CANPack1;            /* '<Root>/CAN Pack1' */
  CAN_MESSAGE_BUS CANPack2;            /* '<Root>/CAN Pack2' */
  CAN_MESSAGE_BUS CANPack3;            /* '<Root>/CAN Pack3' */
  CAN_MESSAGE_BUS CANPack5;            /* '<Root>/CAN Pack5' */
  CAN_MESSAGE_BUS CANPack4;            /* '<Root>/CAN Pack4' */
  CANMessage Message;                  /* '<S39>/MATLAB Function7' */
  CANMessage Message_o;                /* '<S34>/MATLAB Function7' */
  real_T CANUnpack_o1;                 /* '<S6>/CAN Unpack' */
  real_T CANUnpack_o2;                 /* '<S6>/CAN Unpack' */
  real_T CANUnpack_o3;                 /* '<S6>/CAN Unpack' */
  real_T CANUnpack_o4;                 /* '<S6>/CAN Unpack' */
  real_T CANUnpack_o5;                 /* '<S6>/CAN Unpack' */
  real_T CANUnpack_o6;                 /* '<S6>/CAN Unpack' */
  real_T CANUnpack_o7;                 /* '<S6>/CAN Unpack' */
  real_T CANUnpack1_o1;                /* '<S6>/CAN Unpack1' */
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
  real32_T Gain;                       /* '<Root>/Gain' */
  boolean_T OutportBufferForMCPInitialized;/* '<S59>/Constant' */
  B_DigitalPortRead_Copy_of_PDU_T DigitalPortRead_k;/* '<S36>/Digital Port Read' */
  B_DigitalPortRead_Copy_of_PDU_T DigitalPortRead_m;/* '<S36>/Digital Port Read' */
} B_Copy_of_PDUSTM32_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S60>/SPI Controller Transfer' */
  stm32cube_blocks_SPIControlle_T obj_e;/* '<S4>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_o;/* '<S3>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_d;/* '<S2>/SPI Controller Transfer1' */
  stm32cube_blocks_SPIControlle_T obj_l;/* '<S1>/SPI Controller Transfer1' */
  stm32cube_blocks_AnalogInputF_T obj_n;/* '<S30>/Analog to Digital Converter' */
  real_T UnitDelay3_DSTATE;            /* '<S16>/Unit Delay3' */
  real_T UnitDelay2_DSTATE;            /* '<S16>/Unit Delay2' */
  real_T UnitDelay1_DSTATE;            /* '<S16>/Unit Delay1' */
  real_T DelayInput1_DSTATE;           /* '<S58>/Delay Input1' */
  int_T CANPack1_ModeSignalID;         /* '<Root>/CAN Pack1' */
  int_T CANPack2_ModeSignalID;         /* '<Root>/CAN Pack2' */
  int_T CANPack3_ModeSignalID;         /* '<Root>/CAN Pack3' */
  int_T CANPack5_ModeSignalID;         /* '<Root>/CAN Pack5' */
  int_T CANPack4_ModeSignalID;         /* '<Root>/CAN Pack4' */
  int_T CANUnpack_ModeSignalID;        /* '<S6>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<S6>/CAN Unpack' */
  int_T CANUnpack1_ModeSignalID;       /* '<S6>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<S6>/CAN Unpack1' */
  uint8_T Output_DSTATE;               /* '<S11>/Output' */
  DW_SPIControllerTransfer5_C_f_T SPIControllerTransfer7;/* '<S60>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer1_Cop_T SPIControllerTransfer6_p;/* '<S60>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer5_C_f_T SPIControllerTransfer5_pna;/* '<S60>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer1_Cop_T SPIControllerTransfer4_pna;/* '<S60>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_Cop_T SPIControllerTransfer3_p;/* '<S60>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_Cop_T SPIControllerTransfer2_p;/* '<S60>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer1_Cop_T SPIControllerTransfer1_pnaev;/* '<S60>/SPI Controller Transfer1' */
  DW_SPIControllerTransfer5_Cop_T SPIControllerTransfer6;/* '<S7>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer5_Cop_T SPIControllerTransfer5_pn;/* '<S7>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer4_Cop_T SPIControllerTransfer4_pn;/* '<S7>/SPI Controller Transfer4' */
  DW_SPIControllerTransfer4_Cop_T SPIControllerTransfer3;/* '<S7>/SPI Controller Transfer4' */
  DW_SPIControllerTransfer5_Cop_T SPIControllerTransfer2;/* '<S7>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer4_Cop_T SPIControllerTransfer1_pnae;/* '<S7>/SPI Controller Transfer4' */
  DW_MATLABFunction2_Copy_of_PD_T sf_MATLABFunction3;/* '<S9>/MATLAB Function3' */
  DW_MATLABFunction2_Copy_of_PD_T sf_MATLABFunction2_n;/* '<S9>/MATLAB Function2' */
  DW_MATLABFunction2_Copy_of_PD_T sf_MATLABFunction1;/* '<S9>/MATLAB Function1' */
  DW_SPIControllerTransfer5_Cop_T SPIControllerTransfer5_p;/* '<S7>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer4_Cop_T SPIControllerTransfer4_p;/* '<S7>/SPI Controller Transfer4' */
  DW_MATLABFunction2_Copy_of_PD_T sf_MATLABFunction2_o;/* '<S8>/MATLAB Function2' */
  DW_SPIControllerTransfer5_Cop_T SPIControllerTransfer5;/* '<S7>/SPI Controller Transfer5' */
  DW_SPIControllerTransfer4_Cop_T SPIControllerTransfer4;/* '<S7>/SPI Controller Transfer4' */
  DW_MATLABFunction2_Copy_of_PD_T sf_MATLABFunction2;/* '<S7>/MATLAB Function2' */
  DW_EnabledSubsystem_Copy_of_P_T EnabledSubsystem_l;/* '<S32>/Enabled Subsystem' */
  DW_DigitalPortRead_Copy_of_PD_T DigitalPortRead_k;/* '<S36>/Digital Port Read' */
  DW_EnabledSubsystem_Copy_of_P_T EnabledSubsystem;/* '<S31>/Enabled Subsystem' */
  DW_DigitalPortRead_Copy_of_PD_T DigitalPortRead_m;/* '<S36>/Digital Port Read' */
} DW_Copy_of_PDUSTM32_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T Constant;            /* '<S59>/Constant' */
} ConstB_Copy_of_PDUSTM32_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: uint8([0x90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]))
   * Referenced by:
   *   '<S34>/Read RX Buffer start at RXB0SIDH7'
   *   '<S39>/Read RX Buffer start at RXB0SIDH7'
   */
  uint8_T pooled8[15];

  /* Expression: 0xc0
   * Referenced by: '<S60>/Enter Configuration Mode'
   */
  uint8_T EnterConfigurationMode_Value;

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S60>/CNF4'
   */
  uint8_T CNF4_Value[3];

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S60>/CNF2'
   */
  uint8_T CNF2_Value[3];

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S60>/CNF3'
   */
  uint8_T CNF3_Value[3];

  /* Expression: [0x05, 0x2B, 0xFF, 0x01]
   * Referenced by: '<S60>/CANINTE'
   */
  uint8_T CANINTE_Value[4];

  /* Expression: [0x02, 0x60, 0x60]
   * Referenced by: '<S60>/Set acceptance filters'
   */
  uint8_T Setacceptancefilters_Value[3];

  /* Expression: [0x05, 0x2C, 0xFF, 0x00]
   * Referenced by: '<S60>/Clear flags'
   */
  uint8_T Clearflags_Value[4];

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S60>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  uint8_T u00normalmode0dontabortpendingt[3];

  /* Pooled Parameter (Expression: uint8([0, 0]))
   * Referenced by:
   *   '<S1>/Dummy Bits'
   *   '<S2>/Dummy Bits'
   *   '<S3>/Dummy Bits'
   *   '<S4>/Dummy Bits'
   */
  uint8_T pooled9[2];
} ConstP_Copy_of_PDUSTM32_T;

/* Real-time Model Data Structure */
struct tag_RTM_Copy_of_PDUSTM32_T {
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
extern B_Copy_of_PDUSTM32_T Copy_of_PDUSTM32_B;

/* Block states (default storage) */
extern DW_Copy_of_PDUSTM32_T Copy_of_PDUSTM32_DW;

/* External data declarations for dependent source files */
extern const real_T Copy_of_PDUSTM32_RGND;/* real_T ground */
extern const ConstB_Copy_of_PDUSTM32_T Copy_of_PDUSTM32_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Copy_of_PDUSTM32_T Copy_of_PDUSTM32_ConstP;

/* Model entry point functions */
extern void Copy_of_PDUSTM32_initialize(void);
extern void Copy_of_PDUSTM32_step(void);
extern void Copy_of_PDUSTM32_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Copy_of_PDUSTM32_T *const Copy_of_PDUSTM32_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S48>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * '<Root>' : 'Copy_of_PDUSTM32'
 * '<S1>'   : 'Copy_of_PDUSTM32/ADC121S021 1'
 * '<S2>'   : 'Copy_of_PDUSTM32/ADC121S021 2'
 * '<S3>'   : 'Copy_of_PDUSTM32/ADC121S021 3'
 * '<S4>'   : 'Copy_of_PDUSTM32/ADC121S021 4'
 * '<S5>'   : 'Copy_of_PDUSTM32/Analog to Digital Converter'
 * '<S6>'   : 'Copy_of_PDUSTM32/CAN Rx'
 * '<S7>'   : 'Copy_of_PDUSTM32/CAN TX2'
 * '<S8>'   : 'Copy_of_PDUSTM32/CAN TX3'
 * '<S9>'   : 'Copy_of_PDUSTM32/CAN TX6'
 * '<S10>'  : 'Copy_of_PDUSTM32/Compare To Constant'
 * '<S11>'  : 'Copy_of_PDUSTM32/Counter Limited'
 * '<S12>'  : 'Copy_of_PDUSTM32/Digital Port Read1'
 * '<S13>'  : 'Copy_of_PDUSTM32/Digital Port Write'
 * '<S14>'  : 'Copy_of_PDUSTM32/Digital Port Write1'
 * '<S15>'  : 'Copy_of_PDUSTM32/Digital Port Write3'
 * '<S16>'  : 'Copy_of_PDUSTM32/Initialize CAN3'
 * '<S17>'  : 'Copy_of_PDUSTM32/Switches1'
 * '<S18>'  : 'Copy_of_PDUSTM32/Switches2'
 * '<S19>'  : 'Copy_of_PDUSTM32/Switches3'
 * '<S20>'  : 'Copy_of_PDUSTM32/Switches4'
 * '<S21>'  : 'Copy_of_PDUSTM32/Switches5'
 * '<S22>'  : 'Copy_of_PDUSTM32/Switches6'
 * '<S23>'  : 'Copy_of_PDUSTM32/Switches7'
 * '<S24>'  : 'Copy_of_PDUSTM32/Switches8'
 * '<S25>'  : 'Copy_of_PDUSTM32/ADC121S021 1/MATLAB Function'
 * '<S26>'  : 'Copy_of_PDUSTM32/ADC121S021 2/MATLAB Function'
 * '<S27>'  : 'Copy_of_PDUSTM32/ADC121S021 3/MATLAB Function'
 * '<S28>'  : 'Copy_of_PDUSTM32/ADC121S021 4/MATLAB Function'
 * '<S29>'  : 'Copy_of_PDUSTM32/Analog to Digital Converter/ECSoC'
 * '<S30>'  : 'Copy_of_PDUSTM32/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S31>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX1'
 * '<S32>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX2'
 * '<S33>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX1/Digital Port Read5'
 * '<S34>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX1/Enabled Subsystem'
 * '<S35>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX1/Digital Port Read5/ECSoC'
 * '<S36>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX1/Digital Port Read5/ECSoC/ECSimCodegen'
 * '<S37>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX1/Enabled Subsystem/MATLAB Function7'
 * '<S38>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX2/Digital Port Read5'
 * '<S39>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX2/Enabled Subsystem'
 * '<S40>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX2/Digital Port Read5/ECSoC'
 * '<S41>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX2/Digital Port Read5/ECSoC/ECSimCodegen'
 * '<S42>'  : 'Copy_of_PDUSTM32/CAN Rx/CAN RX2/Enabled Subsystem/MATLAB Function7'
 * '<S43>'  : 'Copy_of_PDUSTM32/CAN TX2/MATLAB Function2'
 * '<S44>'  : 'Copy_of_PDUSTM32/CAN TX3/MATLAB Function2'
 * '<S45>'  : 'Copy_of_PDUSTM32/CAN TX6/MATLAB Function1'
 * '<S46>'  : 'Copy_of_PDUSTM32/CAN TX6/MATLAB Function2'
 * '<S47>'  : 'Copy_of_PDUSTM32/CAN TX6/MATLAB Function3'
 * '<S48>'  : 'Copy_of_PDUSTM32/Counter Limited/Increment Real World'
 * '<S49>'  : 'Copy_of_PDUSTM32/Counter Limited/Wrap To Zero'
 * '<S50>'  : 'Copy_of_PDUSTM32/Digital Port Read1/ECSoC'
 * '<S51>'  : 'Copy_of_PDUSTM32/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S52>'  : 'Copy_of_PDUSTM32/Digital Port Write/ECSoC'
 * '<S53>'  : 'Copy_of_PDUSTM32/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S54>'  : 'Copy_of_PDUSTM32/Digital Port Write1/ECSoC'
 * '<S55>'  : 'Copy_of_PDUSTM32/Digital Port Write1/ECSoC/ECSimCodegen'
 * '<S56>'  : 'Copy_of_PDUSTM32/Digital Port Write3/ECSoC'
 * '<S57>'  : 'Copy_of_PDUSTM32/Digital Port Write3/ECSoC/ECSimCodegen'
 * '<S58>'  : 'Copy_of_PDUSTM32/Initialize CAN3/Detect Increase'
 * '<S59>'  : 'Copy_of_PDUSTM32/Initialize CAN3/Initialize'
 * '<S60>'  : 'Copy_of_PDUSTM32/Initialize CAN3/MCPInit'
 * '<S61>'  : 'Copy_of_PDUSTM32/Switches1/ECSoC'
 * '<S62>'  : 'Copy_of_PDUSTM32/Switches1/ECSoC/ECSimCodegen'
 * '<S63>'  : 'Copy_of_PDUSTM32/Switches2/ECSoC'
 * '<S64>'  : 'Copy_of_PDUSTM32/Switches2/ECSoC/ECSimCodegen'
 * '<S65>'  : 'Copy_of_PDUSTM32/Switches3/ECSoC'
 * '<S66>'  : 'Copy_of_PDUSTM32/Switches3/ECSoC/ECSimCodegen'
 * '<S67>'  : 'Copy_of_PDUSTM32/Switches4/ECSoC'
 * '<S68>'  : 'Copy_of_PDUSTM32/Switches4/ECSoC/ECSimCodegen'
 * '<S69>'  : 'Copy_of_PDUSTM32/Switches5/ECSoC'
 * '<S70>'  : 'Copy_of_PDUSTM32/Switches5/ECSoC/ECSimCodegen'
 * '<S71>'  : 'Copy_of_PDUSTM32/Switches6/ECSoC'
 * '<S72>'  : 'Copy_of_PDUSTM32/Switches6/ECSoC/ECSimCodegen'
 * '<S73>'  : 'Copy_of_PDUSTM32/Switches7/ECSoC'
 * '<S74>'  : 'Copy_of_PDUSTM32/Switches7/ECSoC/ECSimCodegen'
 * '<S75>'  : 'Copy_of_PDUSTM32/Switches8/ECSoC'
 * '<S76>'  : 'Copy_of_PDUSTM32/Switches8/ECSoC/ECSimCodegen'
 */
#endif                                 /* Copy_of_PDUSTM32_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
