#include "i2c.h"


/*we will use the I2C1 it means the SDA is connected to PA14 and SCL to PA13
 * */

int main(void) {

   I2C_INIT();


}

void I2C_INIT(void){

	//Enable clock for GPIOA
	RCC->AHB2ENR |= (0x1<<0);

	//Enable clock for I2C1
	RCC->APB1ENR1 |= (0x1<<21);
	//disable I2C before configuration
	I2C1->CR1 &=~(0x1);
	//Configure PA13 and PA14 as an alternate function
	GPIOA->MODER &= ~(0x1<<26);
	GPIOA->MODER |=  (0x1<<27);

	GPIOA->MODER &= ~(0x1<<28);
	GPIOA->MODER |=  (0x1<<29);

	//Configure PA13 and PA14 as open drain
	GPIOA->OTYPER |= (0x3<<13);

	//Configure the pin 13 and PA14 as pull up
	GPIOA->PUPDR &= ~(0xF<<13);
	GPIOA->PUPDR |=  (0x5<<13);

	// Set the alternate functions as PA4
	GPIOA->AFR[1] &= ~(0xFF<<20);
	GPIOA->AFR[1] |=  (0x4<<20); //for PIN13
	GPIOA->AFR[1] |=  (0x4<<24); //for PA14

	//Reset the i2c
	RCC->APB1RSTR1 &= ~(0x1<<21);
	RCC->APB1RSTR1 |=  (0x1<<21);

	/*determine the speed of I2C (standard mode)
	Refer to RM I2C timing register configuration examples for 100 kHz
	*/
	I2C1->TIMINGR |= (0x3<<28) | (0x4<<20) | (0x2<<16) | (0x0F<<8) | (0x04<<0);

	//Enable the I2C
	I2C1->CR1 |= (0x1);
}

//This function aims to generate the bit of start frame
void I2C_START(uint16_t SlaveAddress, uint8_t Direction){
	while((I2C1->ISR & BUSY)){/*Wait until the bus is available*/}

	/*Set the slave size address to 10 bits
	 * Set the slave address
	 * set direction read 1 or write 0
	 */
	I2C1->CR2 |= (0x1<<11) | (SlaveAddress<<0) | (Direction<<10);

	// wait until the slave address is transmitted
	while(!(I2C1->ISR & (0x1<<3)));

	//Clear the slave address flag
	I2C1->ICR |= (0x1<<3);
	//generate the start bit
	I2C1->CR2 |= (0x1<<13);

// this one aims to generate the stop
void I2C_STOP(void){

	I2C1->CR2 |= (0x1<<14);
	// waiting for stop bit to detected in the bus
	while(!(I2C1->ISR & (0x1<<3)));
	//clear the stop flag bit
	I2C1->ICR |=(0x1<<5);
}

void BYTESEND(uint8_t Data){

	//check if the data register is empty
	while(!(I2C1->ISR & 0x1));

	//Load the data into TX register
	I2C1->TXDR=Data;
	//Wait until the TXDR is empty
	while(I2C1->ISR & (0x1<<1));
}

uint8_t BYTEREAD(void){

	//wait for data to be received
	while(!(I2C1->ISR & (0x1<<2)));

	return I2C1->RXDR;
}









}
