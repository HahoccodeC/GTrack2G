#ifndef __SIGNAL_PAL_H
#define __SIGNAL_PAL_H

#include "main.h"
#include <stdbool.h>

/**
 * @brief Set the state of the power signal.
 *
 * This function is used to set the state of the power signal.
 *
 * @param state The desired state of the power signal.
 */
void PAL_SIGNAL_PWR_SetState(bool state);

/**
 * @brief Set the state of the LED signal.
 *
 * This function is used to set the state of the LED signal.
 *
 * @param state The desired state of the LED signal.
 */
void PAL_SIGNAL_LED_SetState(bool state);

/**
 * @brief Toggle the state of the LED signal.
 *
 * This function is used to toggle the state of the LED signal.
 */
void PAL_SIGNAL_LED_Toggle();

/**
 * @brief Blink the LED signal using a timer.
 *
 * This function is used to blink the LED signal using a timer.
 *
 * @param htim Pointer to the timer handle.
 */
void PAL_SIGNAL_LED_BlinkTimer(TIM_HandleTypeDef* htim);

#endif