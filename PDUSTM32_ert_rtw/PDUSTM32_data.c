/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PDUSTM32_data.c
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

#include "PDUSTM32.h"

/* Invariant block signals (default storage) */
const ConstB_PDUSTM32_T PDUSTM32_ConstB = {
  true                                 /* '<S35>/Constant' */
};

/* Constant parameters (default storage) */
const ConstP_PDUSTM32_T PDUSTM32_ConstP = {
  /* Expression: 0xc0
   * Referenced by: '<S36>/Enter Configuration Mode'
   */
  192U,

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S36>/CNF1'
   */
  { 2U, 42U, 192U },

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S36>/CNF2'
   */
  { 2U, 41U, 153U },

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S36>/CNF3'
   */
  { 2U, 40U, 2U },

  /* Expression: [0x05, 0x2B, 0xFF, 0x01]
   * Referenced by: '<S36>/CANINTE'
   */
  { 5U, 43U, 255U, 1U },

  /* Expression: [0x02, 0x60, 0x60]
   * Referenced by: '<S36>/Set acceptance filters'
   */
  { 2U, 96U, 96U },

  /* Expression: [0x05, 0x2C, 0xFF, 0x00]
   * Referenced by: '<S36>/Clear flags'
   */
  { 5U, 44U, 255U, 0U },

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S36>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  { 2U, 15U, 0U },

  /* Expression: uint8([0x90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
   * Referenced by: '<Root>/Read RX Buffer start at RXB0SIDH'
   */
  { 144U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: uint8([0, 0]))
   * Referenced by:
   *   '<S1>/Dummy Bits'
   *   '<S2>/Dummy Bits'
   *   '<S3>/Dummy Bits'
   *   '<S4>/Dummy Bits'
   */
  { 0U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
