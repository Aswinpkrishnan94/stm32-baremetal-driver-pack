#include "system.h"
#include "delay.h"

#define SYSTEM_CORE_CLK		64000000

void System_Init(void)
{
	/*
		- Clock configuration (PLL)
	    - Enable FPU
	    - Cache enable (H7)
	    - MPU setup
	*/
	clock_init_hsi();
	delay_init(SYSTEM_CORE_CLK);
}
