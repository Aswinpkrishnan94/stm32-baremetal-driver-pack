#include "stdint.h"

#define RCC_BASE	  0x58024400
#define GPIOB_BASE	0x58020400

#define RCC_AHB4ENR		(*(volatile uint32_t*)(RCC_BASE + 0x0E0))
#define GPIOB_MODER		(*(volatile uint32_t*)(GPIOB_BASE + 0x00))
#define GPIOB_ODR		  (*(volatile uint32_t*)(GPIOB_BASE + 0x14))

void delay(int ms)
{
	for(uint32_t i=0;i<ms;i++)
	{
		for(uint32_t j=0;j<3125;j++);
	}
}

int main(void)
{
	RCC_AHB4ENR |= (1 << 1);

	GPIOB_MODER &= ~(3 << 0);
	GPIOB_MODER |=  (1 << 0);

	while(1)
	{
		GPIOB_ODR |=  (1 << 0);
		delay(1000);
		GPIOB_ODR &= ~(1 << 0);
		delay(2000);
	}
	return 0;
}
