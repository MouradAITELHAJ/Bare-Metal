#include"stm32g4xx.h"
/*button in PC13 and LED in PA5 
if the vutton is pressed the led 
will turn on
*/


#define GPIOAEN			(1U<<0)
#define GPIOCEN			(1U<<2)
#define PUSH_BUTTON		(1U<<13)
#define LED				(1U<<5)




//GPIOA configuration
void GPIOA_CONFIG(void);

//GPIOC configuration
void GPIOC_CONFIG(void);


