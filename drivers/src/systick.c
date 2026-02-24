#include "systick.h"

void systick_init(uint32_t ticks)
{
	SYSTICK->SYST_CSR = 0;					// disable SYSTICK
	SYSTICK->SYST_RVR  = ticks-1;			// set reload value
	SYSTICK->SYST_CVR  = 0;					// current value
	SYSTICK->SYST_CSR |= (0x5 << 0);		// enable clock source and enable counter
}

// Blocking delay using polling
void systick_delay(uint32_t ticks)
{
	SYSTICK->SYST_RVR = ticks-1;
	SYSTICK->SYST_CVR = 0;
	SYSTICK->SYST_CSR |= (1 << 0);			// start the timer

	while(!(SYSTICK->SYST_CSR & (1 << 16)));	// wait until count flag is set
		SYSTICK->SYST_CSR &= ~(1 << 0);			// stop the timer
}
