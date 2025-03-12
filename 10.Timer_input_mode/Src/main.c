#include <timer.h>

int main(void){
	GPIOA_CONFIG();
	TIMER_1HZ();

	while(1){

		while(!(TIM1->SR & UIF)){
			//wait
		}
		TIM1->SR &=~UIF;
		GPIOA->ODR		^=	LED;
	}

}


void TIMER_1HZ(void){
	RCC->APB2ENR |=TIM1EN;
	TIM1->PSC	 =1600-1;
	TIM1->ARR	 =10000-1;
	TIM1->CR1	 |=CEN;

}

void GPIOA_CONFIG(){
//Enable clock for PIOA (GPIO linked to the AHB2 bus)
	RCC->AHB2ENR	|=	 GPIOAEN;
	// 01 means that the pin 5 is an output
	//Set the bit 10 of MODE register
	GPIOA->MODER	|=	 BIT_10_MODE;
	//Clear the bit 11 of MODE register
	GPIOA->MODER	&=	~BIT_11_MODE;
	//initialize the PIN 5
	GPIOA->ODR		&=	~LED;
}

