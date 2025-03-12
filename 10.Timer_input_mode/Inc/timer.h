#ifndef TIMER_H_
#define TIMER_H_

#include "stm32g4xx.h"
#define TIM1EN		(1U<<11)

#define CEN			(1U<<0)
#define UIF			(1U<<0)

#define GPIOAEN			(1U<<0)
#define LED				(1U<<5)
#define BIT_10_MODE		(1U<<10)
#define BIT_11_MODE		(1U<<11)


//GPIOA configuration
void GPIOA_CONFIG(void);
void TIMER_1HZ(void);

#endif /* TIMER_H_ */
