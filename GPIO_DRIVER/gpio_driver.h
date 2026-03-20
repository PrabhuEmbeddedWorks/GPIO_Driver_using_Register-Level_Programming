#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#define RCC_APB2ENR   (*(volatile unsigned int*)0x40021018)
#define GPIOA_CRL     (*(volatile unsigned int*)0x40010800)
#define GPIOA_ODR     (*(volatile unsigned int*)0x4001080C)
extern volatile unsigned int GPIOA_ODR_SIM;

void gpio_init(unsigned int pin);
void gpio_toggle(unsigned int pin);

#endif