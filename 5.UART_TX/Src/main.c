#include "UART_TX.h"

int main(void) {
    // Configure GPIOA for UART2
    GPIOA_CONFIG();

    // Configure UART2
    UART2_CONFIG();

    // Transmit a character
    Write_word('H');
    Write_word('e');
    Write_word('l');
    Write_word('l');
    Write_word('o');
    Write_word(' ');
    Write_word('W');
    Write_word('o');
    Write_word('r');
    Write_word('l');
    Write_word('d');
    Write_word('\n');

    // Main loop

    return 0;
}

// GPIOA Configuration
void GPIOA_CONFIG(void)
{
//Enable clock for PIOA (GPIO linked to the AHB2 bus)
	RCC->AHB2ENR	|=	 GPIOAEN;
	// 10 means that the pin  is an AF
	//Configure the pin 2 as an AF
	GPIOA->MODER	&=	~(2U<<4);
	//configure the AF7 (AF7 is uart2)
	GPIOA->AFR[0]	|=	AF7;
}

//
void UART2_CONFIG(void)
{
	/*Enable clock access for USART2*/
	RCC->APB1ENR1	|=	UART2EN;
	/*set the baud-rate*/
	USART2->BRR		 =	Compute_Baud_Rate(APB1CLK,baudrate);
	/*set the data   length to 8*/
	USART2->CR1		&=~(DATAM0 |DATAM1);
	USART2->CR1		|=TE;
	USART2->CR1		|=UE;
}

uint32_t Compute_Baud_Rate(uint32_t BUSCLK,uint32_t baud){

	return BUSCLK/baud;
}
/*Write function*/
void Write_word(char world){


while (!(USART2->ISR & TXE))
{
/*wait until the data register is empty*/
}
USART2->TDR=world;

}








