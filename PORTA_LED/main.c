#include "map.h"


rcc_t* RCC = RCC_BASE;

// bit fields
#define RCC_IOPAEN (1 << 2)

 
gpio_t* GPIOA = GPIOA_BASE;

void main(void)
{
    // Enable GPIOC clock
    RCC->apb2enr |= RCC_IOPAEN;
  
    // Configure pin 13 (GPIOC13) as output, 50 MHz, push-pull mode
    GPIOA->crl &= 0;  // Clear the current configuration for pin 13
    GPIOA->crl |= 0x11111111;   // Set mode to output (01) and speed to 50 MHz (11)

    while (1)
    {
        // Set GPIOC13 high
        GPIOA->odr |= (GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 |GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6);

        // Arbitrary delay
        for (int i = 0; i < 500000; i++)
            ;

        // Set GPIOC13 low
        GPIOA->odr &= ~(GPIO_PIN0 | GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3 |GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6);

        // Arbitrary delay
        for (int i = 0; i < 500000; i++)
            ;
    }
}
