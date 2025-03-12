/*
 * I2C.h
 *
 * to be tested 
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32g4xx.h"
#include <stdint.h>


#define BUSY 0x1<<15

void I2C_INIT(void);
void I2C_START(uint16_t, uint8_t);
void I2C_STOP(void);
void BYTESEND(uint8_t );
uint8_t BYTEREAD(void);

#endif /* I2C_H_ */
