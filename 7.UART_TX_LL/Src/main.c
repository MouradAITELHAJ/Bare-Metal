#include "uart_tx_ll.h"


int main(void){

	GPIOA_CONFIG();
	UART2_CONFIG();
	while(1){

		WRITE('x');
		for(int i=0;i<100;i++){
		}
		 Read();

}
}

void GPIOA_CONFIG(void){
	//Enable clk access to GPIOA
	RCC->AHB2ENR	|= 	GPIOAEN;
	//PIN 2 as Alternate function
	GPIOA->MODER	|=	(MODE_AF_TX | MODE_AF_RX);
	//set AF7 at AFSL
	GPIOA->AFR[0]	|=	(AF7TX | AF7RX);
}

void UART2_CONFIG(){
	//enable clock for UART2
	RCC->APB1ENR1	|=	USART2EN;
	//transmitter enable
	USART2->CR1		|=	TE;
	USART2->CR1		|=	RE;
	//set the data length to 8 bits
	USART2->CR1		&=	~M0;
	USART2->CR1		&=	~M1;
	//Set the baud-rate
	USART2->BRR		=	SET_BAUD_RATE(APB_FREQ,BAUD);
	//Set thr stop bits to 1 bit
	USART2->CR2		&=	~(STP0 | STP1);
	//Enable USART2
	USART2->CR1		=	UE;

}
uint32_t SET_BAUD_RATE(uint32_t FREQUENCY,uint32_t SPEED){
	return 2*FREQUENCY/SPEED;
}

void WRITE(char kalma){
	while(!(USART2->ISR & TXE )){}
	USART2->TDR	=	kalma;
}

char Read(void){
	while(!(USART2->ISR & RXNE )){}
	return USART2->RDR;

}
