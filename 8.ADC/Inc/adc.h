/**this ADC module to be tested*/

#ifndef ADC_H_
#define ADC_H_

#include "stm32g4xx.h"
#include <stdint.h>

#define GPIOAEN         (1U << 0)
#define ANALOG_MODE_PA0 (3U << 0)  // Set PA0 to analog mode
#define ADC1EN          (1U << 13)
#define CMODE           (2U << 16) // Asynchronous clock mode
#define CON_CONV        (1U << 13) // Continuous conversion mode
#define CHANNEL_5       (1U << 6)  // Select channel 5 (PA0)
#define DEEPMODE        (1U << 29)
#define VOLREGULATOR    (1U << 28)
#define ADCCALIB        (1U << 31)
#define ADC1ENB         (1U << 0)
#define ADSTART         (1U << 2)
#define EOC             (1U << 2)

void GPIOA_CONFIG(void);
void ADC_CONFIG(void);
void ADC_START_CONVERSION(void);
uint32_t ADC_READ(void);

#endif /* ADC_H_ */
