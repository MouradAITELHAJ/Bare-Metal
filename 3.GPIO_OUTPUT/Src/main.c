#include<gpio_output.h>


int main(void){

	GPIOA_CONFIG();

	while(1){
		GPIOA->ODR	^=	LED;
		for(int i=0;i<1720000;i++){
				// making a delay
		}
	}
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
