#include "adc_hcl.h"

#include <stdbool.h>

static uint16_t ADCValue = 0;       // Variable to store the latest ADC raw value
static float Voltage = 0;           // Variable to store the calculated voltage value
static bool IsADCUpdate = false;    // Flag indicating if the ADC update is complete

/**
 * @brief ADC conversion complete callback function.
 *
 * This function is called when the ADC conversion is complete. It retrieves the ADC value,
 * calculates the corresponding voltage, and sets the ADC update flag to indicate that the
 * ADC value has been updated.
 *
 * @param hadc Pointer to the ADC handle.
 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
    ADCValue = HAL_ADC_GetValue(hadc);
    Voltage = (float) ADCValue / 4095 * 3.3;

    IsADCUpdate = true;
}

/**
 * @brief Selects the ADC channel to be sampled.
 *
 * @param channel_number The channel number to be selected.
 */
void HCL_ADC_SelectChannel(uint8_t channel_number) {
    ADC1->CHSELR = (1UL << channel_number);
}

/**
 * @brief Starts the ADC sampling process.
 *
 * @param hadc Pointer to the ADC handle.
 */
void HCL_ADC_StartSample(ADC_HandleTypeDef* hadc) {
    HAL_ADC_Start_IT(hadc);
}

/**
 * @brief Checks if the ADC update is complete.
 *
 * @return True if the ADC update is complete, false otherwise.
 */
bool HCL_ADC_IsUpdate() {
    return IsADCUpdate;
}

/**
 * @brief Clears the ADC update flag.
 */
void HCL_ADC_ClearUpdate() {
    IsADCUpdate = false;
}

/**
 * @brief Gets the voltage value measured by the ADC.
 *
 * This function retrieves the latest voltage value measured by the ADC and returns it as a floating-point value.
 * The voltage value is calculated by dividing the raw ADC value by the maximum ADC value (4095) and multiplying it
 * by the reference voltage (3.3V).
 *
 * @note This function clears the ADC update flag to indicate that the voltage value has been retrieved.
 *
 * @return The voltage value in volts.
 */
float HCL_ADC_GetVoltage() {
    IsADCUpdate = false;
    return Voltage;
}