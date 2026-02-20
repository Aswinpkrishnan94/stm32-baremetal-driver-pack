#ifndef INC_SYSTEM_H_
#define INC_SYSTEM_H_

#include "stdint.h"
/*
 * ================================================================
 *  System Initialization
 * ================================================================
 *
 * Responsibilities:
 * - Core configuration
 * - Clock setup
 * - Cache / MPU
 * - Low-level platform initialization
 *
 * Called once from Reset_Handler before main()
 */

/* Future Work:
 * - PLL configuration
 * - Cache enable (H7)
 * - MPU setup
 * - Clock tree configuration
 */

void System_Init(void);

#endif /* INC_SYSTEM_H_ */
