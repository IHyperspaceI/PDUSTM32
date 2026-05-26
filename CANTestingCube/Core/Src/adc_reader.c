/**
 * adc_reader.c
 * Custom ADC read function for use as a Simulink C Caller block.
 *
 * Handles full ADC1 init, DMA setup, TIM2 start, and per-step readout.
 * Call adc_reader_init() once at startup, then adc_reader_step() each step.
 *
 * Channels (in rank order):
 *   out[0] = CH10 (PC0)
 *   out[1] = CH11 (PC1)
 *   out[2] = CH12 (PC2)
 *   out[3] = CH16 (PA0)
 *   out[4] = CH17 (PA1)
 */

#include "adc_reader.h"
#include "stm32h7xx_ll_adc.h"
#include "stm32h7xx_ll_dma.h"
#include "stm32h7xx_ll_tim.h"
#include "stm32h7xx_ll_bus.h"

#define ADC_NUM_CHANNELS 5U

/* DMA buffer - placed in D2 SRAM (accessible by DMA1).
 * Must be 32-bit aligned; 16-bit ADC results are packed into lower half. */
static __attribute__((section(".dma_buffer")))
__attribute__((aligned(32)))
volatile uint32_t adc_dma_buf[ADC_NUM_CHANNELS];

static uint8_t adc_initialised = 0;

/* ------------------------------------------------------------------ */
/* Init                                                                 */
/* ------------------------------------------------------------------ */
void adc_reader_init(void)
{
    if (adc_initialised) return;

    /* --- DMA1 Stream0 for ADC1 --- */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

    LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_0);
    while (LL_DMA_IsEnabledStream(DMA1, LL_DMA_STREAM_0));

    LL_DMA_SetPeriphRequest   (DMA1, LL_DMA_STREAM_0, LL_DMAMUX1_REQ_ADC1);
    LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_STREAM_0, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
    LL_DMA_SetStreamPriorityLevel  (DMA1, LL_DMA_STREAM_0, LL_DMA_PRIORITY_VERYHIGH);
    LL_DMA_SetMode            (DMA1, LL_DMA_STREAM_0, LL_DMA_MODE_CIRCULAR);
    LL_DMA_SetPeriphIncMode   (DMA1, LL_DMA_STREAM_0, LL_DMA_PERIPH_NOINCREMENT);
    LL_DMA_SetMemoryIncMode   (DMA1, LL_DMA_STREAM_0, LL_DMA_MEMORY_INCREMENT);
    LL_DMA_SetPeriphSize      (DMA1, LL_DMA_STREAM_0, LL_DMA_PDATAALIGN_HALFWORD);
    LL_DMA_SetMemorySize      (DMA1, LL_DMA_STREAM_0, LL_DMA_MDATAALIGN_HALFWORD);
    LL_DMA_SetDataLength      (DMA1, LL_DMA_STREAM_0, ADC_NUM_CHANNELS);
    LL_DMA_SetPeriphAddress   (DMA1, LL_DMA_STREAM_0, LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA));
    LL_DMA_SetMemoryAddress   (DMA1, LL_DMA_STREAM_0, (uint32_t)adc_dma_buf);

    LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_0);

    /* --- ADC1 --- */
    LL_ADC_DisableDeepPowerDown(ADC1);
    LL_ADC_EnableInternalRegulator(ADC1);
    /* Wait for regulator startup (~20us) */
    for (volatile uint32_t i = 0; i < 10000; i++);

    /* Calibrate */
    LL_ADC_StartCalibration(ADC1, LL_ADC_CALIB_OFFSET, LL_ADC_SINGLE_ENDED);
    while (LL_ADC_IsCalibrationOnGoing(ADC1));

    /* Configure regular sequence */
    LL_ADC_REG_SetSequencerLength(ADC1, LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS);
    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_10);
    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_2, LL_ADC_CHANNEL_11);
    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_3, LL_ADC_CHANNEL_12);
    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_4, LL_ADC_CHANNEL_16);
    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_5, LL_ADC_CHANNEL_17);

    LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_10, LL_ADC_SAMPLINGTIME_810CYCLES_5);
    LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_11, LL_ADC_SAMPLINGTIME_810CYCLES_5);
    LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_12, LL_ADC_SAMPLINGTIME_810CYCLES_5);
    LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_16, LL_ADC_SAMPLINGTIME_810CYCLES_5);
    LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_17, LL_ADC_SAMPLINGTIME_810CYCLES_5);

    LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_10, LL_ADC_SINGLE_ENDED);
    LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_11, LL_ADC_SINGLE_ENDED);
    LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_12, LL_ADC_SINGLE_ENDED);
    LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_16, LL_ADC_SINGLE_ENDED);
    LL_ADC_SetChannelSingleDiff(ADC1, LL_ADC_CHANNEL_17, LL_ADC_SINGLE_ENDED);

    /* External trigger: TIM2 TRGO, rising edge */
    LL_ADC_REG_SetTriggerSource(ADC1, LL_ADC_REG_TRIG_EXT_TIM2_TRGO);
    LL_ADC_REG_SetTriggerEdge  (ADC1, LL_ADC_REG_TRIG_EXT_RISING);

    /* DMA circular */
    LL_ADC_REG_SetDataTransferMode(ADC1, LL_ADC_REG_DMA_TRANSFER_UNLIMITED);

    LL_ADC_REG_SetOverrun(ADC1, LL_ADC_REG_OVR_DATA_OVERWRITTEN);
    LL_ADC_REG_SetContinuousMode(ADC1, LL_ADC_REG_CONV_SINGLE);
    LL_ADC_REG_SetSequencerDiscont(ADC1, LL_ADC_REG_SEQ_DISCONT_DISABLE);

    /* Enable ADC */
    LL_ADC_Enable(ADC1);
    while (!LL_ADC_IsActiveFlag_ADRDY(ADC1));

    /* Start conversions - hardware trigger from TIM2 will fire them */
    LL_ADC_REG_StartConversion(ADC1);

    /* --- Start TIM2 AFTER ADC is ready --- */
    LL_TIM_EnableCounter(TIM2);

    adc_initialised = 1;
}

/* ------------------------------------------------------------------ */
/* Step - call each Simulink step to read latest DMA buffer values     */
/* ------------------------------------------------------------------ */
void adc_reader_step(uint32_t out[ADC_NUM_CHANNELS])
{
    if (!adc_initialised)
    {
        for (uint32_t i = 0; i < ADC_NUM_CHANNELS; i++) out[i] = 0;
        return;
    }

    for (uint32_t i = 0; i < ADC_NUM_CHANNELS; i++)
    {
        out[i] = adc_dma_buf[i] & 0xFFFFU;
    }
}
