#include "stm32g4xx.h"
#include <stdint.h>

#define APB1CLK        (16000000U / 2U) // Adjust based on your actual APB1 clock
#define BAUDRATE       115200U
#define GPIOAEN        (1U << 0)
#define UART2EN        (1U << 17)
#define AF7            (7U) // Alternate function 7 for USART2
#define TE             (1U << 3)
#define UE             (1U << 0)
#define TXE            (1U << 7)

void GPIOA_CONFIG(void);
void UART2_CONFIG(void);
void Write_char(char ch);

int main(void) {
    GPIOA_CONFIG();
    UART2_CONFIG();

    while (1) {
        Write_char('Y');

        // Optional: Add a delay to prevent flooding the receiver
        for (volatile uint32_t i = 0; i < 1000; i++) {
            // Simple delay loop
        }
    }
}

void GPIOA_CONFIG(void) {
    // Enable clock for GPIOA
    RCC->AHB2ENR |= GPIOAEN;

    // Set PA2 to Alternate Function mode (AF7 for USART2_TX)
    GPIOA->MODER &= ~(3U << (2 * 2)); // Clear mode bits for PA2
    GPIOA->MODER |=  (2U << (2 * 2));  // Set mode to Alternate Function

    // Set PA2 to AF7 (USART2_TX)
    GPIOA->AFR[0] &= ~(0xFU << (4 * 2)); // Clear AF bits for PA2
    GPIOA->AFR[0] |= (AF7 << (4 * 2));   // Set AF7 for PA2
}

void UART2_CONFIG(void) {
    // Enable clock for USART2
    RCC->APB1ENR1 |= UART2EN;

    // Configure baud rate
    USART2->BRR = APB1CLK / BAUDRATE;

    // Set data length to 8 bits (default), no parity, 1 stop bit
    USART2->CR1 &= ~((1U << 12) | (1U << 28)); // Clear M0 and M1 for 8-bit word length

    // Enable transmitter
    USART2->CR1 |= TE;

    // Enable USART
    USART2->CR1 |= UE;
}

void Write_char(char ch) {
    // Wait until transmit data register is empty
    while (!(USART2->ISR & TXE)) {
        // Wait
    }
    // Transmit character
    USART2->TDR = ch;
}
