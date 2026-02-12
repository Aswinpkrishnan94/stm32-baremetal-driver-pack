#include "dwt.h"

#define SYSCLK_HZ 400000000U

volatile uint32_t boot_cycles = 0;
volatile float boot_time_us = 0;

int main(void)
{
    boot_cycles = DWT_GetCycleCount();
    boot_time_us = (float)boot_cycles / (SYSCLK_HZ / 1000000.0f);

    while (1)
    {
    }
}
