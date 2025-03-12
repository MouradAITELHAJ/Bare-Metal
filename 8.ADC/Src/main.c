#include "adc.h"

/* ADC IN5
 * PA0
 */

int Status;

void delay(void) {
    for (int i = 0; i < 10000; i++) {
        // Simple delay loop
    }
}

int main(void) {
    GPIOA_CONFIG();
    ADC_CONFIG();
    delay();
    ADC_START_CONVERSION();

    Status = ADC_READ();

    // Use the Status variable as needed
}

void GPIOA_CONFIG(void) {
    // Enable GPIOA clock
    RCC->AHB2ENR |= GPIOAEN;
    // Set PA0 to analog mode
    GPIOA->MODER |= ANALOG_MODE_PA0;
}

void ADC_CONFIG(void) {
    // Enable ADC1 clock
    RCC->AHB2ENR |= ADC1EN;
    // Set ADC clock mode (asynchronous clock mode)
    ADC12_COMMON->CCR |= CMODE;
    // Set continuous conversion mode
    ADC1->CFGR |= CON_CONV;
    // Select channel 5 (PA0) in regular sequence register
    ADC1->SQR1 |= CHANNEL_5;
    // Disable deep power-down mode
    ADC1->CR &= ~DEEPMODE;
    // Enable voltage regulator
    ADC1->CR |= VOLREGULATOR;
    // Wait for voltage regulator to stabilize
    delay();
    // Start ADC calibration
    ADC1->CR |= ADCCALIB;
    // Wait for calibration to complete
    while (ADC1->CR & ADCCALIB);
    // Enable ADC
    ADC1->CR |= ADC1ENB;
    // Wait for ADC to be ready
    while (!(ADC1->ISR & ADC_ISR_ADRDY));
}

void ADC_START_CONVERSION(void) {
    // Start ADC conversion
    ADC1->CR |= ADSTART;
}

uint32_t ADC_READ(void) {
    // Wait for end of conversion
    while (!(ADC1->ISR & EOC));
    // Read and return ADC data
    return ADC1->DR;
}
