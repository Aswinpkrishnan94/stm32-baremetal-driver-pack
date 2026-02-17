#ifndef INC_MEMORY_MAP_H_
#define INC_MEMORY_MAP_H_


/* ========================= */
/*        Core Regions       */
/* ========================= */

#define FLASH_BASE          0x08000000UL
#define SRAM_BASE           0x20000000UL
#define DTCM_RAM_BASE       0x20000000UL
#define ITCM_RAM_BASE       0x00000000UL
#define PERIPH_BASE         0x40000000UL


/* ========================= */
/*         Bus Domains       */
/* ========================= */

#define APB1_BASE           (PERIPH_BASE + 0x00000000UL)
#define APB2_BASE           (PERIPH_BASE + 0x00010000UL)
#define APB3_BASE           (PERIPH_BASE + 0x10000000UL)
#define APB4_BASE           (PERIPH_BASE + 0x18000000UL)
#define AHB1_BASE           (PERIPH_BASE + 0x00020000UL)
#define AHB2_BASE           (PERIPH_BASE + 0x08020000UL)
#define AHB3_BASE           (PERIPH_BASE + 0x11000000UL)
#define AHB4_BASE           (PERIPH_BASE + 0x18020000UL)

/* ========================= */
/*     AHB1 Peripherals      */
/* ========================= */

#define DMA1_BASE           (AHB1_BASE + 0x0000UL)
#define DMA2_BASE           (AHB1_BASE + 0x0400UL)
#define RCC_BASE            (AHB4_BASE + 0x4400UL)
#define FLASH_REG_BASE      (AHB3_BASE + 0x01000000UL)


/* ========================= */
/*     AHB4 Peripherals      */
/* ========================= */

#define GPIOA_BASE          (AHB4_BASE + 0x0000UL)
#define GPIOB_BASE          (AHB4_BASE + 0x0400UL)
#define GPIOC_BASE          (AHB4_BASE + 0x0800UL)
#define GPIOD_BASE          (AHB4_BASE + 0x0C00UL)
#define GPIOE_BASE          (AHB4_BASE + 0x1000UL)
#define GPIOF_BASE          (AHB4_BASE + 0x1400UL)
#define GPIOG_BASE          (AHB4_BASE + 0x1800UL)
#define GPIOH_BASE          (AHB4_BASE + 0x1C00UL)


/* ========================= */
/*     APB1 Peripherals      */
/* ========================= */

#define USART2_BASE         (APB1_BASE + 0x4400UL)
#define USART3_BASE         (APB1_BASE + 0x4800UL)
#define UART4_BASE          (APB1_BASE + 0x4C00UL)
#define UART5_BASE          (APB1_BASE + 0x5000UL)
#define I2C1_BASE           (APB1_BASE + 0x5400UL)
#define I2C2_BASE           (APB1_BASE + 0x5800UL)
#define TIM2_BASE           (APB1_BASE + 0x0000UL)
#define TIM3_BASE           (APB1_BASE + 0x0400UL)


/* ========================= */
/*     APB2 Peripherals      */
/* ========================= */

#define USART1_BASE         (APB2_BASE + 0x1000UL)
#define SPI1_BASE           (APB2_BASE + 0x3000UL)
#define TIM1_BASE           (APB2_BASE + 0x0000UL)

/* ========================= */
/*        System Control     */
/* ========================= */

#define SYSTICK_BASE        0xE000E010UL
#define NVIC_BASE           0xE000E100UL

#endif /* INC_MEMORY_MAP_H_ */
