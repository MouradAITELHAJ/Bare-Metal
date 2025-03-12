#include "systick.h"

/* Blinking LED using SysTick Timer */

int main(void) {
    GPIOA_CONFIG();  // Configure GPIOA for LED

    while (1) {
        GPIOA->ODR ^= LED;  // Toggle the LED state
        DelayMs(1000);      // Delay for 1 second
    }
}

void DelayMs(int delay) {
    // Configure SysTick
    SysTick->LOAD = RELOAD;   // Set reload register with calculated value
    SysTick->VAL = 0;         // Clear current value register
    SysTick->CTRL = CLKSOURCE | SysTickEN;  // Enable SysTick

    for (int i = 0; i < delay; i++) {
        // Wait until the COUNTFLAG is set
        while (!(SysTick->CTRL & COUNTFLAG)) {}
    }

    // Disable SysTick after the delay
    SysTick->CTRL = 0;
}

void GPIOA_CONFIG(void) {
    // Enable clock for GPIOA (linked to AHB2 bus)
    RCC->AHB2ENR |= GPIOAEN;

    // Configure PA5 as output
    GPIOA->MODER &= ~(3U << 10); // Clear MODER5[1:0]
    GPIOA->MODER |= (1U << 10);  // Set MODER5[1:0] to 01 (output mode)

    // Initialize PA5 output to low
    GPIOA->ODR &= ~LED;
}
