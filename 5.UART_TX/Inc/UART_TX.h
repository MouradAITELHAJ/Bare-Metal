#include"stm32g4xx.h"
#include <stdint.h>
/*UART2 connected to APB1
 * TX connected to PA2
 * RX connected to PA3*
 * This UART not completed/


#define APB1CLK			((172000000/2)U)
#define baudrate		(115200U)
#define GPIOAEN			(1U<<0)
#define UART2EN			(1U<<17)
#define AF7				(7U<<8)
#define DATAM0			(1U<<12)
#define DATAM1			(1U<<28)
#define TE				(1U<<3)
#define UE				(1U<<0)
#define TXE				(1U<<7)





//GPIOA configuration
void GPIOA_CONFIG(void);

//GPIOC configuration
void UART2_CONFIG(void);
//Calculate the value of baud-rate
uint32_t Compute_Baud_Rate(uint32_t , uint32_t);
/*write in the uart*/
void Write_word(char word);

