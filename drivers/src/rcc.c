#include "rcc.h"

void RCC_AHB1_CLK_EN(uint32_t mask)
{
	RCC_AHB1ENR |= (1 << mask);
}

void RCC_AHB2_CLK_EN(uint32_t mask)
{
	RCC_AHB2ENR |= (1 << mask);
}

void RCC_AHB3_CLK_EN(uint32_t mask)
{
	RCC_AHB3ENR |= (1 << mask);
}

void RCC_AHB4_CLK_EN(uint32_t mask)
{
	RCC_AHB4ENR |= (1 << mask);
}

void RCC_APB1_CLK_EN(uint32_t mask)
{
	if(mask < 16)
		RCC_APB1LENR |= (1 << mask);
	else
		RCC_APB1HENR |= (1 << mask);
}

void RCC_APB2_CLK_EN(uint32_t mask)
{
	RCC_APB2ENR |= (1 << mask);
}

void RCC_APB3_CLK_EN(uint32_t mask)
{
	RCC_APB3ENR |= (1 << mask);
}

void RCC_APB4_CLK_EN(uint32_t mask)
{
	RCC_APB4ENR |= (1 << mask);
}

void RCC_AHB1_CLK_DI(uint32_t mask)
{
	RCC_AHB1ENR &= ~(1 << mask);
}

void RCC_AHB2_CLK_DI(uint32_t mask)
{
	RCC_AHB2ENR &= ~(1 << mask);
}

void RCC_AHB3_CLK_DI(uint32_t mask)
{
	RCC_AHB3ENR &= ~(1 << mask);
}

void RCC_AHB4_CLK_DI(uint32_t mask)
{
	RCC_AHB4ENR &= ~(1 << mask);
}

void RCC_APB1_CLK_DI(uint32_t mask)
{
	if(mask < 16)
		RCC_APB1LENR &= ~(1 << mask);
	else
		RCC_APB1HENR &= ~(1 << mask);
}

void RCC_APB2_CLK_DI(uint32_t mask)
{
	RCC_APB2ENR &= ~(1 << mask);
}

void RCC_APB3_CLK_DI(uint32_t mask)
{
	RCC_APB3ENR &= ~(1 << mask);
}

void RCC_APB4_CLK_DI(uint32_t mask)
{
	RCC_APB4ENR &= ~(1 << mask);
}

void SystemClock_Config(void)
{
	RCC->CR |= RCC_CR_HSION;
	while (!(RCC->CR & RCC_CR_HSIRDY));

	    // Configure PLL1 for 480MHz (HCLK target)
	    RCC->PLLCKSELR = (2U << 0);  // PLLSRC=HSI/2 = 32MHz
	    RCC->PLL1DIVR = (1 << 0);    // DIVM1=1 (32MHz)
	    RCC->PLL1FRACR = 0;          // FRACN1=0
	    RCC->PLL1DIVR |= (79 << 8);  // DIVN1=79 (32*79=2528MHz)
	    RCC->PLL1DIVR |= (2 << 19);  // DIVP1=2 (1264MHz)
	    RCC->PLL1DIVR |= (4 << 16);  // DIVQ1=4 (632MHz)

	    RCC->CR |= RCC_CR_PLL1ON;
	    while (!(RCC->CR & RCC_CR_PLL1RDY));

	    // Set system clocks
	    RCC->CFGR = (0 << 0);        // SYSCLK=PLL1 (1264MHz/2? Wait HCLK mux)

	    // Flash latency for 480MHz
	    FLASH->ACR |= (7U << 0);     // 7 wait states
}

