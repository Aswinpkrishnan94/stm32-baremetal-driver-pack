#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stdint.h"
#define RCC_BASE_ADDR		0x58024400

typedef struct{
		volatile uint32_t CR;           // 0x00: Clock control
	    volatile uint32_t HSICFGR;      // 0x04: HSI calibration
	    volatile uint32_t CFGR;         // 0x08: Clock configuration
	    volatile uint32_t PLLCKSELR;    // 0x0C: PLL clock source selection (H7!)
	    volatile uint32_t PLLCFGR;      // 0x10: PLL config
	    volatile uint32_t PLL1DIVR;     // 0x14
	    volatile uint32_t PLL1FRACR;    // 0x18
	    volatile uint32_t PLL2DIVR;     // 0x1C
	    volatile uint32_t PLL2FRACR;    // 0x20
	    uint32_t RESERVED1[2];          // 0x24-0x28
	    volatile uint32_t PLL3DIVR;     // 0x2C
	    volatile uint32_t PLL3FRACR;    // 0x30
	    volatile uint32_t PLLCKSELR2;   // 0x34
	    uint32_t RESERVED2[4];          // 0x38-0x48
	    volatile uint32_t AHB1RSTR;     // 0x4C: AHB1 reset
	    volatile uint32_t AHB2RSTR;     // 0x50
	    volatile uint32_t AHB3RSTR;     // 0x54
	    volatile uint32_t AHB4RSTR;     // 0x58: AHB4 reset (GPIOI-K)
	    uint32_t RESERVED3[12];         // 0x5C-0x8C
	    volatile uint32_t AHB1ENR;      // 0x90: AHB1 clock enable (GPIOA-H)
	    volatile uint32_t AHB2ENR;      // 0x94: DMA1/2, USB
	    volatile uint32_t AHB3ENR;      // 0x98: FMC/QSPI
	    volatile uint32_t AHB4ENR;      // 0x9C: GPIOI-K, BDMA
	    uint32_t RESERVED4[8];          // 0xA0-BC
	    volatile uint32_t APB1LENR;     // 0xE0: Low-speed APB1 (TIM2-7, USART2-5)
	    volatile uint32_t APB1HENR;     // 0xE4
	    volatile uint32_t APB2LENR;     // 0xE8: USART1, TIM1, SPI1
	    volatile uint32_t APB2HENR;     // 0xEC
	    volatile uint32_t APB3ENR;      // 0xF0
	    volatile uint32_t APB4ENR;      // 0xF4
}RCC_RegDef_t;

#define RCC		((RCC_RegDef_t*)RCC_BASE_ADDR)

#define RCC_AHB1ENR			(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0D8))
#define RCC_AHB2ENR			(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0DC))
#define RCC_AHB3ENR			(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0D4))
#define RCC_AHB4ENR			(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0E0))
#define RCC_APB1LENR		(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0E8))
#define RCC_APB1HENR		(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0EC))
#define RCC_APB2ENR			(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0F0))
#define RCC_APB3ENR			(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0E4))
#define RCC_APB4ENR			(*(volatile uint32_t*)(RCC_BASE_ADDR + 0x0F4))

#define RCC_CR_HSION          (1 << 0)   // HSI enable
#define RCC_CR_HSIKERON       (1 << 8)   // HSI keep during run
#define RCC_CR_HSIRDY         (1 << 10)  // HSI ready
#define RCC_CR_HSEON          (1 << 16)  // HSE enable
#define RCC_CR_PLL1ON         (1 << 25)  // PLL1 enable
#define RCC_CR_PLL1RDY        (1 << 26)  // PLL1 ready

#define RCC_AHB1ENR_GPIOAEN   (1 << 0)   // GPIOA clock enable
#define RCC_AHB1ENR_GPIOBEN   (1 << 1)	 // GPIOB clock enable
#define RCC_AHB1ENR_GPIOCEN   (1 << 2)	 // GPIOC clock enable
#define RCC_AHB1ENR_GPIODEN   (1 << 3)	 // GPIOD clock enable
#define RCC_AHB1ENR_GPIOEEN   (1 << 4)	 // GPIOE clock enable
#define RCC_AHB1ENR_GPIOFEN   (1 << 5)   // GPIOF clock enable
#define RCC_AHB1ENR_GPIOGEN   (1 << 6)   // GPIOG clock enable
#define RCC_AHB1ENR_GPIOHEN   (1 << 7)	 // GPIOH clock enable

#define RCC_GPIOA_CLK_EN_BIT     0
#define RCC_GPIOB_CLK_EN_BIT     1
#define RCC_GPIOC_CLK_EN_BIT     2
#define RCC_GPIOD_CLK_EN_BIT     3
#define RCC_GPIOE_CLK_EN_BIT     4
#define RCC_GPIOF_CLK_EN_BIT     5
#define RCC_GPIOG_CLK_EN_BIT     6
#define RCC_GPIOH_CLK_EN_BIT     7

#define RCC_GPIOA_CLK_EN()    RCC_AHB1_CLK_EN(RCC_GPIOA_CLK_EN_BIT)
#define RCC_GPIOB_CLK_EN()    RCC_AHB1_CLK_EN(RCC_GPIOB_CLK_EN_BIT)
#define RCC_USART2_CLK_EN()   RCC_APB1_CLK_EN(RCC_USART2_CLK_EN_BIT)
#define RCC_SPI2_CLK_EN()     RCC_APB1_CLK_EN(RCC_SPI2_CLK_EN_BIT)
#define RCC_GPIOI_CLK_EN()    RCC_AHB4_CLK_EN(RCC_GPIOI_CLK_EN_BIT)
#define RCC_GPIOK_CLK_EN()    RCC_AHB4_CLK_EN(RCC_GPIOK_CLK_EN_BIT)

void RCC_AHB1_CLK_EN(uint32_t mask);
void RCC_AHB1_CLK_DI(uint32_t mask);
void RCC_AHB2_CLK_EN(uint32_t mask);
void RCC_AHB2_CLK_DI(uint32_t mask);
void RCC_AHB3_CLK_EN(uint32_t mask);
void RCC_AHB3_CLK_DI(uint32_t mask);
void RCC_AHB4_CLK_EN(uint32_t mask);
void RCC_AHB4_CLK_DI(uint32_t mask);

void RCC_APB1_CLK_EN(uint32_t mask);
void RCC_APB1_CLK_DI(uint32_t mask);
void RCC_APB2_CLK_EN(uint32_t mask);
void RCC_APB2_CLK_DI(uint32_t mask);
void RCC_APB3_CLK_EN(uint32_t mask);
void RCC_APB3_CLK_DI(uint32_t mask);
void RCC_APB4_CLK_EN(uint32_t mask);
void RCC_APB4_CLK_DI(uint32_t mask);

#endif /* INC_RCC_H_ */
