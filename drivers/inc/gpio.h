#include "stdint.h"

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#define PERIPH_BASE         0x40000000UL
#define AHB4_BASE          (PERIPH_BASE + 0x18020000UL)

#define GPIOA_BASE          (AHB4_BASE + 0x0000UL)
#define GPIOB_BASE          (AHB4_BASE + 0x0400UL)
#define GPIOC_BASE          (AHB4_BASE + 0x0800UL)
#define GPIOD_BASE          (AHB4_BASE + 0x0C00UL)
#define GPIOE_BASE          (AHB4_BASE + 0x1000UL)
#define GPIOF_BASE          (AHB4_BASE + 0x1400UL)
#define GPIOG_BASE          (AHB4_BASE + 0x1800UL)
#define GPIOH_BASE          (AHB4_BASE + 0x1C00UL)

typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
}GPIO_TypeDef_t;

#define GPIOA				(GPIO_TypeDef_t*)GPIOA_BASE)
#define GPIOB				(GPIO_TypeDef_t*)GPIOB_BASE)
#define GPIOC				(GPIO_TypeDef_t*)GPIOC_BASE)
#define GPIOD				(GPIO_TypeDef_t*)GPIOD_BASE)
#define GPIOE				(GPIO_TypeDef_t*)GPIOE_BASE)
#define GPIOF				(GPIO_TypeDef_t*)GPIOF_BASE)
#define GPIOG				(GPIO_TypeDef_t*)GPIOG_BASE)
#define GPIOH				(GPIO_TypeDef_t*)GPIOH_BASE)

void GPIO_Init(uint32_t *pGPIOx, uint8_t EnorDi);
void GPIO_DeInit(uint32_t *pGPIOx, uint8_t EnorDi);
void GPIO_WritePin(uint32_t* pGPIOx, uint16_t Pin_Number, uint8_t Pin_State);
void GPIO_ReadPin(uint32_t* pGPIOx, uint16_t Pin_Number);
void GPIO_TogglePin(uint32_t* pGPIOx,uint16_t Pin_Number);
