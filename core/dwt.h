/*
 * dwt.h
 *
 *  Created on: Feb 12, 2026
 *      Author: Ashwin
 */

#ifndef INC_DWT_H_
#define INC_DWT_H_

#include <stdint.h>

void DWT_Init(void);
void DWT_ResetCycleCounter(void);
uint32_t DWT_GetCycleCount(void);
void DWT_DelayCycles(uint32_t cycles);

#endif /* INC_DWT_H_ */
