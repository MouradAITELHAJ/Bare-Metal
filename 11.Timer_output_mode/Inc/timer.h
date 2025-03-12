#ifndef TIMER_H_
#define TIMER_H_

#include "stm32g4xx.h"

// RCC AHB2 peripheral clock enable register
#define GPIOAEN     (1U << 0)  // GPIOA clock enable

// RCC APB1 peripheral clock enable register 1
#define TIM2EN      (1U << 0)  // TIM2 clock enable

// TIM2 control register 1
#define CEN         (1U << 0)  // Counter enable

// TIM2 capture/compare enable register
#define CC1E        (1U << 0)  // Capture/Compare 1 output enable

// Function prototypes
void GPIOA_CONFIG(void);
void TIMER2_CONFIG(void);

#endif /* TIMER_H_ */
