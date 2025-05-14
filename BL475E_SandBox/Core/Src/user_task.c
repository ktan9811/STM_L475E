/*
 * user_task.c
 *
 *  Created on: May 14, 2025
 *      Author: user
 */

#include "user_task.h"
#include "cmsis_os2.h"
#include "main.h"

extern osMessageQueueId_t buttonQueueHandle;

void LedTask(void *argument)
{
#if 1
  uint8_t signal = 0;
  uint8_t ledState = 0;

  for (;;)
  {
    if (osMessageQueueGet(buttonQueueHandle, &signal, NULL, osWaitForever) == osOK)
    {
      ledState ^= 1;
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, ledState ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
  }
#elif
  while (1)
  {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
    osDelay(1000); // 500ms마다 토글
  }
#endif
}
