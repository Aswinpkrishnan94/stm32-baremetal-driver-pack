#ifndef DELAY_H_
#define DELAY_H_
#include "stdint.h"

void delay_init(uint32_t core_clock_hz);
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);

#endif /* DELAY_H_ */
