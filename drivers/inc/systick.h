#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stdint.h"

#define SYSTICK_BASE	0xE000E010

typedef struct
{
	volatile uint32_t SYST_CSR;
	volatile uint32_t SYST_RVR;
	volatile uint32_t SYST_CVR;
	volatile uint32_t SYST_CALIB;
}SYSTICK_TypeDef_t;

#define SYSTICK		(*(SYSTICK_TypeDef_t*)SYSTICK_BASE)

void systick_init(uint32_t ticks);
void systick_delay(uint32_t ticks);

#endif /* SYSTICK_H_ */
