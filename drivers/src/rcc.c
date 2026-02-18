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

