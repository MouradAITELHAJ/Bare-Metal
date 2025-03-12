/*
 * interrupts.h
 *
 *  Created on: Jan 31, 2025
 *      Author: Fiodor Dostoïevski
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include"stm32g4xx.h"

#define GPIOAENB		(1U<<0)
#define GPIOCENB		(1U<<2)
#define LED_PIN		(1U<<5)
#define BUTTON		(1U<<13)
#define SYSCFGEN	(1U<<0)
#define EXTI_PC13	(2U<<4)


void GPIO_CONFIG(void);

void EXTI_CONFIG(void);


#endif /* INTERRUPTS_H_ */
