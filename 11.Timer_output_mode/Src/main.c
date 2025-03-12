#include "timer.h"

int main(void) {
    GPIOA_CONFIG();
    TIMER2_CONFIG();

    while (1) {
        // Main loop can be used for other tasks
    }
}

void GPIOA_CONFIG(void) {
    // Enable clock for GPIOA
    RCC->AHB2ENR |= GPIOAEN;

    // Set PA5 to alternate function mode (AF1 for TIM2_CH1)
    GPIOA->MODER &= ~(3U << (5 * 2)); // Clear mode bits for PA5
    GPIOA->MODER |= (2U << (5 * 2));  // Set mode to Alternate Function

    // Set PA5 alternate function to AF1 (TIM2_CH1)
    GPIOA->AFR[0] &= ~(0xF << (5 * 4)); // Clear AF bits for PA5
    GPIOA->AFR[0] |= (1U << (5 * 4));   // Set AF1 for PA5
}

void TIMER2_CONFIG(void) {
    // Enable clock for TIM2
    RCC->APB1ENR1 |= TIM2EN;

    // Disable TIM2 during configuration
    TIM2->CR1 &= ~CEN;

    // Set prescaler and auto-reload for 1 Hz toggle
    TIM2->PSC = 16000 - 1; // Prescaler
    TIM2->ARR = 1000 - 1;  // Auto-reload

    // Configure TIM2 Channel 1 in toggle mode
    TIM2->CCMR1 &= ~(7U << 4); // Clear OC1M bits
    TIM2->CCMR1 |= (3U << 4);  // Set OC1M to toggle mode (0b011)

    // Enable TIM2 Channel 1 output
    TIM2->CCER |= CC1E;

    // Set initial compare value
    TIM2->CCR1 = 0;

    // Enable TIM2 counter
    TIM2->CR1 |= CEN;
}
