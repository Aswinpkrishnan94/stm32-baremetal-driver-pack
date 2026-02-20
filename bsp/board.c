#include "board.h"
#include "rcc.h"
#include "gpio.h"

#define BOARD_LED_PORT    GPIOB
#define BOARD_LED_PIN     0

void Board_Init(void)
{
	RCC_GPIOB_CLK_EN();
	GPIO_Init(BOARD_LED_PORT, BOARD_LED_PIN, ENABLE);
}

void board_led_on(void)
{
	GPIO_WriteToOutputPin(BOARD_LED_PORT, BOARD_LED_PIN, 1);
}

void board_led_off(void)
{
	GPIO_WriteToOutputPin(BOARD_LED_PORT, BOARD_LED_PIN, 0);
}

void board_led_toggle(void)
{
	GPIO_ToggleOutputPin(BOARD_LED_PORT, BOARD_LED_PIN);
}
