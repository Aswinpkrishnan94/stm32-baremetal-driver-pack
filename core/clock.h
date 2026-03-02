#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_

#include "stdint.h"

extern uint32_t SystemCoreClock;

void clock_init_hsi(void);
void clock_init_pll(void);

#endif /* INC_CLOCK_H_ */
