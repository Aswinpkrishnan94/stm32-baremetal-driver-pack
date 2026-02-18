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

void System_Init(void);

#endif /* INC_SYSTEM_H_ */
