#include "dwt.h"

#define DEMCR      (*(volatile uint32_t*)0xE000EDFC)
#define DWT_CTRL    (*(volatile uint32_t*)0xE0001000)
#define DWT_CYCCNT  (*(volatile uint32_t*)0xE0001004)

#define DEMCR_TRCENA (1 << 24)
#define DWT_CYCCNTENA (1 << 0)

void DWT_Init(void)
{
    // Enable trace and debug block
    DEMCR |= DEMCR_TRCENA;

    // Reset cycle counter
    DWT_CYCCNT = 0;

    // Enable cycle counter
    DWT_CTRL |= DWT_CYCCNTENA;
}

void DWT_ResetCycleCounter(void)
{
    DWT_CYCCNT = 0;
}

uint32_t DWT_GetCycleCount(void)
{
    return DWT_CYCCNT;
}

void DWT_DelayCycles(uint32_t cycles)
{
    uint32_t start = DWT_CYCCNT;
    while ((DWT_CYCCNT - start) < cycles);
}
