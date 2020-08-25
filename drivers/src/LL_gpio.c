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
	if(status == CLK_SET)
	{
		if(pGPIOx == GPIOA_ADDR)
			GPIOA_PCLK_EN();
		if(pGPIOx == GPIOB_ADDR)
			GPIOB_PCLK_EN();
		if(pGPIOx == GPIOC_ADDR)
			GPIOC_PCLK_EN();
		if(pGPIOx == GPIOD_ADDR)
			GPIOD_PCLK_EN();
		if(pGPIOx == GPIOE_ADDR)
			GPIOE_PCLK_EN();
		if(pGPIOx == GPIOF_ADDR)
			GPIOF_PCLK_EN();
		if(pGPIOx == GPIOG_ADDR)
			GPIOG_PCLK_EN();
		if(pGPIOx == GPIOH_ADDR)
			GPIOH_PCLK_EN();

	}
	else if(status == CLK_RESET)
	{
		if(pGPIOx == GPIOA_ADDR)
			GPIOA_PCLK_DI();
		if(pGPIOx == GPIOB_ADDR)
			GPIOB_PCLK_DI();
		if(pGPIOx == GPIOC_ADDR)
			GPIOC_PCLK_DI();
		if(pGPIOx == GPIOD_ADDR)
			GPIOD_PCLK_DI();
		if(pGPIOx == GPIOE_ADDR)
			GPIOE_PCLK_DI();
		if(pGPIOx == GPIOF_ADDR)
			GPIOF_PCLK_DI();
		if(pGPIOx == GPIOG_ADDR)
			GPIOG_PCLK_DI();
		if(pGPIOx == GPIOH_ADDR)
			GPIOH_PCLK_DI();
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
