#include "clock.h"
#include "memory_map.h"
#include "bin_utils.h"


/* System core clock variable */
uint32_t SystemCoreClock = 16000000U;

/*
 * RCC Register Access (minimal subset)
 */
#define RCC_CR          (*(volatile uint32_t *)(RCC_BASE + 0x00))
#define RCC_CFGR        (*(volatile uint32_t *)(RCC_BASE + 0x10))

/* Bit definitions */
#define RCC_CR_HSION        (1 << 0)
#define RCC_CR_HSIRDY       (1 << 2)

#define RCC_CFGR_SW_HSI     (0x0)
#define RCC_CFGR_SWS_MASK   (0xC)


void clock_init_hsi(void)
{
    /* Enable HSI */
    SET_BIT(RCC_CR, RCC_CR_HSION);

    /* Wait until ready */
    while (!(READ_BIT(RCC_CR, RCC_CR_HSIRDY)));

    /* Select HSI as system clock */
    CLEAR_BIT(RCC_CFGR, 0x3U);

    /* Wait until switch complete */
    while ((RCC_CFGR & RCC_CFGR_SWS_MASK) != 0x0U);

    /* Update core clock variable */
    SystemCoreClock = 16000000U;
}

