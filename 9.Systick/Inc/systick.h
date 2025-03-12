#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32g4xx.h"

/* SysTick Timer Configurations */
#define SysTickEN   (1U << 0)    // Enable SysTick
#define CLKSOURCE   (1U << 2)    // Use processor clock
#define COUNTFLAG   (1U << 16)   // SysTick Count Flag
#define RELOAD      (16000 - 1) // Reload value for 1ms delay (assuming 170MHz clock)

/* GPIOA Configurations */
#define GPIOAEN     (1U << 0)    // GPIOA clock enable
#define LED         (1U << 5)    // PA5 (connected to LED)

/* Function Prototypes */
void GPIOA_CONFIG(void);
void DelayMs(int delay);

#endif /* SYSTICK_H_ */
