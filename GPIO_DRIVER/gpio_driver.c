#include "gpio_driver.h"

// Simulated register
volatile unsigned int GPIOA_ODR_SIM = 0;

void gpio_init(unsigned int pin)
{
    // Do nothing
}

void gpio_toggle(unsigned int pin)
{
    GPIOA_ODR_SIM ^= (1 << pin);
}