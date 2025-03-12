#include <stdint.h>
/*In this code i tried to create or to define the register without using CMSIS library */
#define PERIPH_BASE        (0x40000000U)
#define AHB1_OFFSET        (0x00020000U)
#define AHB2_OFFSET        (0x08000000U)
// AHB1 0x4002 0000
#define AHB1_BASE          (PERIPH_BASE + AHB1_OFFSET)
// 0x4800 0000
#define AHB2_BASE          (PERIPH_BASE + AHB2_OFFSET)
#define GPIOA_OFFSET       (0x0000U)
// Port A has the same start address of AHB2
#define GPIOA_BASE         (AHB2_BASE + GPIOA_OFFSET)
#define RCC_OFFSET         (0X00001000U)
// RCC address 0X4002 1000
#define RCC_BASE           (AHB1_BASE + RCC_OFFSET)

#define BIT10              (1U << 10)
#define BIT11              (1U << 11)
#define LED_PIN            (1U << 5)  // Pin 5
#define GPIOA_CLK          (1U << 0)

typedef struct
{
    volatile uint32_t MODER;        // 0x00
    volatile uint32_t EMPTY[4];     // 0x04
    volatile uint32_t ODR;          // 0x14
} GPIO_REG;

typedef struct
{
    volatile uint32_t EMPTY[19];
    volatile uint32_t RCC_AHB2ENR;  // 0x4C
} RCC_REG;

// Give the start address of GPIOA to the structure of GPIO
#define GPIOA   ((GPIO_REG *)GPIOA_BASE)
// Same for RCC register
#define RCC     ((RCC_REG *)RCC_BASE)

int main(void)
{
    // Enable GPIOA clock
    RCC->RCC_AHB2ENR |= GPIOA_CLK;

    // Configure PA5 as output
    GPIOA->MODER &= ~(BIT11 | BIT10); // Clear both bits for PA5
    GPIOA->MODER |= BIT10;           // Set bit 10 for output mode

    // Initialize LED state to OFF
    GPIOA->ODR &= ~LED_PIN;

    // Toggle the LED
    while (1)
    {
        // Toggle only PA5
        GPIOA->ODR ^= LED_PIN;
        for (int i = 0; i < 840000; i++) // Simple delay
        {
        }
    }

    return 0;
}
