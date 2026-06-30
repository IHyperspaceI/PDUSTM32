/**
 * adc_reader.h
 */

#ifndef ADC_READER_H
#define ADC_READER_H

#include <stdint.h>

#define ADC_READER_NUM_CHANNELS 5U

/**
 * Initialise ADC1 + DMA1 Stream0 + start TIM2.
 * Safe to call multiple times (no-op after first call).
 * Call once from Simulink "Initialize function" custom code.
 */
void adc_reader_init(void);

/**
 * Read latest ADC values from DMA buffer.
 * out[0] = CH10 (PC0)
 * out[1] = CH11 (PC1)
 * out[2] = CH12 (PC2)
 * out[3] = CH16 (PA0)
 * out[4] = CH17 (PA1)
 * Values are 16-bit (0-65535).
 * Call each Simulink step.
 */
void adc_reader_step(uint32_t out[ADC_READER_NUM_CHANNELS]);

#endif /* ADC_READER_H */
