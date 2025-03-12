#include<gpio_output.h>
#include<stdint.h>




int main(void){


	GPIOA_CONFIG();
	GPIOC_CONFIG();

	while(1){
		if(GPIOC->IDR & PUSH_BUTTON){
			GPIOA->ODR 	|=	LED;
		}
		else
			GPIOA->ODR 	&=	~LED;

	}
}
// GPIO Configuration

void GPIOA_CONFIG(void)
{
//Enable clock for PIOA (GPIO linked to the AHB2 bus)
	RCC->AHB2ENR	|=	 GPIOAEN;
	// 01 means that the pin 5 is an output
	//Clear the bit 11 of MODE register
	GPIOA->MODER	&=	~(3U<<10);
	//Set the bit 10 of MODE register
	GPIOA->MODER	|=	 (1U<<10);
	//initialize the pin 5
	GPIOA->ODR		&=	 ~LED;
}
void GPIOC_CONFIG(void)
{
	RCC->AHB2ENR	|=	GPIOCEN;
	/*Clear bit 26 and 27
	 * 00 means that the pin selected is an output*/
	GPIOC->MODER	&=	~(3U<<13 * 2); // each bit n represented by 2n and 2n+1
	//Set pin 13 as output
}
