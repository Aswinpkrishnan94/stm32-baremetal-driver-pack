#include "stdint.h"

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#define ENABLE 1
#define DISABLE 0

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
}GPIO_RegDef_t;

typedef struct
{
    uint8_t GPIO_PinNumber;         /* GPIO_PIN_NUMBERS                           */
    uint8_t GPIO_PinMode;           /* GPIO_PIN_MODES                             */
    uint8_t GPIO_PinSpeed;          /* GPIO_PIN_SPEED                             */
    uint8_t GPIO_PinPuPdControl;    /* GPIO_PIN_PULL_UP_PULL_DOWN                 */
    uint8_t GPIO_PinOPType;         /* GPIO_PIN_OUTPUT_TYPE                       */
    uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

typedef struct
{
    GPIO_RegDef_t *pGPIOx;              /* This holds the base address of the GPIO port to which the pin belongs */
    GPIO_PinConfig_t GPIO_PinConfig;    /* This holds GPIO pin configuration settings                            */
}GPIO_Handle_t;

#define GPIOA				(GPIO_RegDef_t*)GPIOA_BASE)
#define GPIOB				(GPIO_RegDef_t*)GPIOB_BASE)
#define GPIOC				(GPIO_RegDef_t*)GPIOC_BASE)
#define GPIOD				(GPIO_RegDef_t*)GPIOD_BASE)
#define GPIOE				(GPIO_RegDef_t*)GPIOE_BASE)
#define GPIOF				(GPIO_RegDef_t*)GPIOF_BASE)
#define GPIOG				(GPIO_RegDef_t*)GPIOG_BASE)
#define GPIOH				(GPIO_RegDef_t*)GPIOH_BASE)

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0       0
#define GPIO_PIN_NO_1       1
#define GPIO_PIN_NO_2       2
#define GPIO_PIN_NO_3       3
#define GPIO_PIN_NO_4       4
#define GPIO_PIN_NO_5       5
#define GPIO_PIN_NO_6       6
#define GPIO_PIN_NO_7       7
#define GPIO_PIN_NO_8       8
#define GPIO_PIN_NO_9       9
#define GPIO_PIN_NO_10      10
#define GPIO_PIN_NO_11      11
#define GPIO_PIN_NO_12      12
#define GPIO_PIN_NO_13      13
#define GPIO_PIN_NO_14      14
#define GPIO_PIN_NO_15      15

/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN        0 /* GPIO Input mode                          */
#define GPIO_MODE_OUT       1 /* GPIO Output mode                         */
#define GPIO_MODE_ALTFN     2 /* GPIO Alternate functionality             */
#define GPIO_MODE_ANALOG    3 /* GPIO Analog mode                         */
#define GPIO_MODE_IT_FT     4 /* GPIO Input mode falling edge trigger     */
#define GPIO_MODE_IT_RT     5 /* GPIO Input mode rising edge trigger      */
#define GPIO_MODE_IT_FRT    6 /* GPIO Input mode fall-rising edge trigger */

/*
 * @GPIO_PIN_OUTPUT_TYPE
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP     0 /* GPIO Output type push-pull mode  */
#define GPIO_OP_TYPE_OD     1 /* GPIO Output type open-drain mode */

/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW      0
#define GPIO_SPEED_MEDIUM   1
#define GPIO_SPEED_FAST     2
#define GPIO_SPEED_HIGH     3

/*
 * @GPIO_PIN_PULL_UP_PULL_DOWN
 * GPIO pin pull-up and pull-down configuration macros
 */
#define GPIO_PIN_NO_PUPD    0 /* GPIO configuration no pull-up, pull-down */
#define GPIO_PIN_PU         1 /* GPIO configuration pull-up               */
#define GPIO_PIN_PD         2 /* GPIO configuration pull-down             */


void GPIO_PCLKCTRL(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

#endif /* INC_GPIO_H_ */
