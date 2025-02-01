#ifndef MAP_H
#define MAP_H

#define GPIO_PIN0 (1U << 0)
#define GPIO_PIN1 (1U << 1)
#define GPIO_PIN2 (1U << 2)
#define GPIO_PIN3 (1U << 3)
#define GPIO_PIN4 (1U << 4)
#define GPIO_PIN5 (1U << 5)
#define GPIO_PIN6 (1U << 6)
#define GPIO_PIN7 (1U << 7)
#define GPIO_PIN8 (1U << 8)
#define GPIO_PIN9 (1U << 9)
#define GPIO_PIN10 (1U << 10)
#define GPIO_PIN11 (1U << 11)
#define GPIO_PIN12 (1U << 12)
#define GPIO_PIN13 (1U << 13)
#define GPIO_PIN14 (1U << 14)

#define FLASH_BASE       (0x08000000U)
#define PRERIPHERAL_BASE (0x40000000U)
// GPIOC structure
typedef struct {
    volatile unsigned int crl;    // GPIO configuration low register
    volatile unsigned int crh;    // GPIO configuration high register
    volatile unsigned int idr;    // GPIO input data register
    volatile unsigned int odr;    // GPIO output data register
    volatile unsigned int bsrr;   // GPIO bit set/reset register
    volatile unsigned int brr;    // GPIO bit reset register
    volatile unsigned int lckr;   // GPIO lock register
} gpio_t;

typedef struct 
{
  volatile unsigned int cr;
  volatile unsigned int cfgr;
  volatile unsigned int cir;
  volatile unsigned int apb2rstr;
  volatile unsigned int apb1rstr;
  volatile unsigned int ahbenr;
  volatile unsigned int apb2enr;
  volatile unsigned int apb1enr;
  volatile unsigned int bdcr;
}rcc_t;

#define GPIOC_BASE (gpio_t *)0x40011000

#define RCC_BASE (rcc_t *)0x40021000
#define GPIOA_BASE (gpio_t *)0x40010800 



#endif