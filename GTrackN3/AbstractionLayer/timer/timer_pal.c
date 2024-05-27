#include "timer/timer_pal.h"
#include "signal/signal_pal.h"

// External boolean variables
extern bool UAL_MC60_isTurningOn;
extern bool UAL_MC60_isGettingGNSS;
extern bool UAL_MC60_isSendingToMQTT;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
  // Static counters for different tasks
  static uint8_t mc60TurnOnCount = 0;
  static uint8_t mc60GetGNSSCount = 0;
  static uint8_t mc60SendMQTTCount = 0;
  
  // Check if the callback is triggered by TIM3
  if (htim != &htim3) return;
  
  // Increment or reset the counters based on the corresponding flags and timer scale
  mc60TurnOnCount = (UAL_MC60_isTurningOn && mc60TurnOnCount < PAL_TIM_GETSCALE(htim, 500)) ? mc60TurnOnCount + 1 : 0;
  mc60GetGNSSCount = (UAL_MC60_isGettingGNSS && mc60GetGNSSCount < PAL_TIM_GETSCALE(htim, 100)) ? mc60GetGNSSCount + 1 : 0;
  mc60SendMQTTCount = (UAL_MC60_isSendingToMQTT && mc60SendMQTTCount < PAL_TIM_GETSCALE(htim, 20)) ? mc60SendMQTTCount + 1 : 0;
  
  // Toggle the LED based on the counter values
  if (mc60TurnOnCount == 1) PAL_SIGNAL_LED_Toggle();
  if (mc60GetGNSSCount == 1) PAL_SIGNAL_LED_Toggle();
  if (mc60SendMQTTCount == 1) PAL_SIGNAL_LED_Toggle();
}