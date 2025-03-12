#include <SPI.h>


/*For SPI 1
 * NSS or SC -------------->PA4
 * SCL--------------------->PA5
 * MISO-------------------->PA6
 * MOSI-------------------->PA7
 * AF5--------------------->
 * */

int main(void) {

   SPI_INIT();


}


void SPI_INIT(void){

	//Enable clock for GPIOA
	RCC->AHB2ENR |= (0x1<<0);

	//Enable clock for SPI1
	RCC->APB2ENR |= (0x1<<12);

	//configure pins as AF
	GPIOA->MODER &= ~(0xFF<4*2);
	GPIOA->MODER |= ((0x2<<4*2) |	//PA 4
					 (0x2<<5*2)	|	//PA5
					 (0x2<<6*2)	|	//PA6
					 (0x2<<7*2));	//PA7

	//Select the alternate function
	GPIOA->AFR[0] &= ~(0xFFFF<<16);
	GPIOA->AFR[0] |= ((0x5<<4*4)
					 |(0x5<<4*5)
					 |(0x5<<4*6)
					 |(0x5<<4*7));
	//Configure the control register 1
	SPI1->CR1 = 0x820F;
	//Configure the control register 2
	SPI1->CR2 = 0x0F04;

}

uint8_t SPI_TRANSFET(uint8_t data){
	uint8_t DataReceived=0;

	//Enable the SPI
	SPI1->CR1 |= (0x1<<6);

	//Put the memory address in data register
	SPI1->DR = (uint16_t)(data<<8);
	//wait until the SPI is not busy and the RX buffer is not empty
	while ((SPI1->SR & (0x1<<7)) && !(SPI1->SR & 0x1));

	//read the data
	DataReceived =(uint8_t)SPI1->DR;

	return DataReceived;
}
