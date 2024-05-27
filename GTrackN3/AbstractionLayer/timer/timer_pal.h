#ifndef __TIMER_PAL_H
#define __TIMER_PAL_H

#include "timer/timer_hcl.h"

/**
 * @brief Calculates the timer scale based on the desired time in milliseconds.
 *
 * This macro calculates the timer scale based on the desired time in milliseconds and the timer period of the given timer handle.
 *
 * @param htim Pointer to the timer handle.
 * @param ms The desired time in milliseconds.
 * @return The calculated timer scale.
 */
#define PAL_TIM_GETSCALE(htim, ms) ((ms) / ((htim)->Init.Period))

/**
 * @brief Timer period elapsed callback function.
 *
 * This function is called by the timer hardware abstraction layer when the timer period has elapsed.
 *
 * @param htim Pointer to the timer handle.
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim);

#endif