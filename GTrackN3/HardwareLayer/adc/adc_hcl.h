#ifndef __ADC_HCL_H
#define __ADC_HCL_H

#include "adc.h"
#include <stdbool.h>

/**
 * @brief Selects the ADC channel to be sampled.
 *
 * @param channel_number The channel number to be selected.
 */
void HCL_ADC_SelectChannel(uint8_t channel_number);

/**
 * @brief Starts the ADC sampling process.
 *
 * @param hadc Pointer to the ADC handle.
 */
void HCL_ADC_StartSample(ADC_HandleTypeDef* hadc);

/**
 * @brief Checks if the ADC update is complete.
 *
 * @return True if the ADC update is complete, false otherwise.
 */
bool HCL_ADC_IsUpdate();

/**
 * @brief Clears the ADC update flag.
 */
void HCL_ADC_ClearUpdate();

/**
 * @brief Gets the voltage value measured by the ADC.
 *
 * @note This function clears the ADC update flag after retrieving the voltage value.
 *
 * @return The voltage value in volts.
 */
float HCL_ADC_GetVoltage();

#endif // __ADC_HCL_H