
#ifndef UART_TX_LL_H_
#define UART_TX_LL_H_

#include"stm32g4xx.h"
#include<stdint.h>

#define	GPIOAEN		(1U<<0)
#define MODE_AF_TX	(2U<<4)
#define MODE_AF_RX	(2U<<6)
#define AF7TX		(7U<<8)
#define AF7RX		(7U<<12)
#define USART2EN	(1U<<17)
#define M0			(1U<<12)
#define M1			(1U<<28)
#define TE			(1U<<3)
#define RE			(1U<<2)
#define APB_FREQ	(16000000U)
#define BAUD		(115200U)
#define STP0		(1U<<13)
#define STP1		(1U<<12)
#define UE			(1U<<0)
#define TXE			(1U<<7)
#define RXNE		(1U<<5)







void GPIOA_CONFIG(void);
void UART2_CONFIG(void);
uint32_t SET_BAUD_RATE(uint32_t FREQUENCY,uint32_t SPEED);
void WRITE(char);
char Read(void);
#endif /* UART_TX_LL_H_ */
