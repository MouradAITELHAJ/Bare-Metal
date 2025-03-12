#include "interrupts.h"




int main(void) {
    GPIO_CONFIG();
    EXTI_CONFIG();


}


void GPIO_CONFIG(void) {
    // Enable clock for GPIOA and GPIOC(linked to AHB2 bus)
    RCC->AHB2ENR |= (GPIOAENB | GPIOCENB);

    // Configure PA5 as output
    GPIOA->MODER &= ~(3U << 10); // Clear MODER5[1:0]
    GPIOA->MODER |= (1U << 10);  // Set MODER5[1:0] to 01 (output mode)

//Configure PC13 as an input
    GPIOC->MODER &= ~(3U<<26);

    // Initialize PA5 output to low
    GPIOA->ODR &= ~LED_PIN;
}

void EXTI_CONFIG(void){
	//Enable clk access for SYSCFG (APB2)
	RCC->APB2ENR |= SYSCFGEN;
	//Select the source interrupt (PC13)
	SYSCFG->EXTICR[3] |= EXTI_PC13;
	//unmask the interrupt for bit 13
	//enable interrupt for PIN13
	EXTI->IMR1 |= (1U<<13);
	//select falling trigger
	EXTI->FTSR1 |= (1U<<13);
	//Enable NVIC for EXTI13
    NVIC_EnableIRQ(EXTI15_10_IRQn);

}
void EXTI15_10_IRQHandler(void){
	if((EXTI->PR1 & BUTTON)){
		EXTI->PR1=(1U<<13);
		for(int i=0; i<4 ;i++){
		    GPIOA->ODR |= LED_PIN;
		    for(int j=0; j<1600000 ;j++){}
		    GPIOA->ODR &= ~LED_PIN;
		   	for(int j=0; j<1600000 ;j++){}
		}
	}

}
