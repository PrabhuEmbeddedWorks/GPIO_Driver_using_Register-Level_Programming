#include <stdio.h>
#include "gpio_driver.h"

void delay()
{
    for(volatile int i = 0; i < 100000; i++);
}

int main(void)
{
    gpio_init(5);

    while(1)
    {
        gpio_toggle(5);
        delay();
    }
}