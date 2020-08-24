/* 	MIT License
 * 	LL_gpio.c
 *  Created on: 18 Aug 2020
 *  Author: Vikrant Thakur(vikrantthakur97@gmail.com)
 */
#include "stm32f4xx.h"
#include "LL_rcc.h"
#include "LL_gpio.h"

void GPIO_init(GPIO_handle_t *pGPIOx)
{

}
void GPIO_clock_control(GPIO_regdef_t *pGPIOx, gpio_enum status)
{
	if(status == ENABLE)
	{
		if(pGPIOx == GPIOA_ADDR)
			GPIOA_PCLK_EN();

	}
	else
	{
		if(pGPIOx == GPIOA_ADDR)
			GPIOA_PCLK_DI();
	}
}
uint8_t GPIO_read_input_pin(GPIO_regdef_t *pGPIOhandle ,uint8_t pinnumber)
{

}
uint16_t GPIO_read_input_port(GPIO_regdef_t *pGPIOhandle)
{

}
void GPIO_toggle_pin(GPIO_regdef_t *pGPIOhandle ,uint8_t pinnumber)
{

}
uint8_t GPIO_write_output_pin(GPIO_regdef_t *pGPIOhandle ,uint8_t pinnumber)
{

}
uint16_t GPIO_write_output_port(GPIO_regdef_t *pGPIOhandle, uint16_t portvalue)
{

}
