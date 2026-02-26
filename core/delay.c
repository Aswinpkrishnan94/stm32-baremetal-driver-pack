#include "delay.h"
#include "systick.h"
#include "stdint.h"

static uint32_t ticks_per_us = 0;

void delay_init(uint32_t core_clock_hz)
{
	ticks_per_us = core_clock_hz/1000000;
}

void delay_ms(uint32_t ms)
{
	while(ms--)
		systick_delay(ms);
}

void delay_us(uint32_t us)
{
	while(us--)
		systick_delay(us);
}
