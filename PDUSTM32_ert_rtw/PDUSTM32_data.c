/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PDUSTM32_data.c
 *
 * Code generated for Simulink model 'PDUSTM32'.
 *
 * Model version                  : 13.196
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Mon Jul 27 13:32:56 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PDUSTM32.h"

/* Invariant block signals (default storage) */
const ConstB_PDUSTM32_T PDUSTM32_ConstB = {
  true                                 /* '<S28>/Constant' */
};

/* Constant parameters (default storage) */
const ConstP_PDUSTM32_T PDUSTM32_ConstP = {
  /* Expression: 0xc0
   * Referenced by: '<S29>/Enter Configuration Mode'
   */
  192U,

  /* Expression: [0x02, 0x2A, 0xC0]
   * Referenced by: '<S29>/CNF1'
   */
  { 2U, 42U, 192U },

  /* Expression: [0x02, 0x29, 0x99]
   * Referenced by: '<S29>/CNF2'
   */
  { 2U, 41U, 153U },

  /* Expression: [0x02, 0x28, 0x02]
   * Referenced by: '<S29>/CNF3'
   */
  { 2U, 40U, 2U },

  /* Expression: [0x02, 0x0F, 0x00]
   * Referenced by: '<S29>/ 000: normal mode, 0: don't abort pending transmit buffers, 0: one-shot disabled, 0: CLKOUT disabled, 00: sysclk//1 | 0000 0000 | 0x00'
   */
  { 2U, 15U, 0U },

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
