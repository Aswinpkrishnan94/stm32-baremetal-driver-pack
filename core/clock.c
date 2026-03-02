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
#define RCC_PLLCFGR     (*(volatile uint32_t *)(RCC_BASE + 0x2C))
#define RCC_PLL1DIVR    (*(volatile uint32_t *)(RCC_BASE + 0x30))

/* Bit definitions */
#define RCC_CR_HSION        (1 << 0)
#define RCC_CR_HSIRDY       (1 << 2)

#define RCC_CFGR_SW_HSI     (0x0)
#define RCC_CFGR_SWS_MASK   (0xC)

#define RCC_CR_PLL1ON       (1U << 24)
#define RCC_CR_PLL1RDY      (1U << 25)


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

void clock_init_pll(void)
{
    /* 1. Disable PLL */
    CLEAR_BIT(RCC_CR, RCC_CR_PLL1ON);
    while (READ_BIT(RCC_CR, RCC_CR_PLL1RDY));

    /*
     * 2. Configure PLL
     * HSI = 16 MHz
     * M = 1
     * N = 8
     * P = 2
     *
     * VCO = 16 * 8 = 128 MHz
     * SYSCLK = 128 / 2 = 64 MHz
     */

    RCC_PLL1DIVR =
        ((8 - 1) << 0)  |   /* N */
        ((2 - 1) << 9);     /* P */

    /* Select HSI as PLL source */
    RCC_PLLCFGR |= (1U << 0);   /* PLL1 source = HSI */
    RCC_PLLCFGR |= (1U << 16);  /* Enable PLL1P output */

    /* 3. Enable PLL */
    SET_BIT(RCC_CR, RCC_CR_PLL1ON);
    while (!READ_BIT(RCC_CR, RCC_CR_PLL1RDY));

    /* 4. Switch system clock to PLL */
    RCC_CFGR = (RCC_CFGR & ~0x3U) | RCC_CFGR_SW_PLL1;
    while ((RCC_CFGR & RCC_CFGR_SWS_MASK) != (RCC_CFGR_SW_PLL1 << 2));

    /* 5. Update system clock variable */
    SystemCoreClock = 64000000U;
}
