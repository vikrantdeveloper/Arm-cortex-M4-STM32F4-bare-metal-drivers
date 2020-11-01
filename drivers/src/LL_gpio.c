/*
 *  MIT License
 * 	LL_gpio.c
 *  Created on: 18 Aug 2020
 *  Author: Vikrant Thakur(vikrantthakur97@gmail.com)
 *  Copyright (c) 2020
 */
#include "stm32f4xx.h"
#include "LL_rcc.h"
#include "LL_gpio.h"

void GPIO_init(GPIO_handle_t *pGPIOx)
{
	// configure the mode
	uint32_t regtemp = 0;
	uint8_t mode = pGPIOx->GPIOpinconfig.GPIO_mode;
	uint8_t alterpin = 0;
	switch(mode)
	{
		case GPIO_MODE_OP:

			regtemp =  GPIO_MODE_OP << (2 * pGPIOx->GPIOpinconfig.GPIO_pinnumber);
			pGPIOx->pGPIOaddrx->MODER &= ~(0x3 << pGPIOx->GPIOpinconfig.GPIO_pinnumber);
			pGPIOx->pGPIOaddrx->MODER |= regtemp;
			regtemp = 0;
			// configure the mode of operation
			if(pGPIOx->GPIOpinconfig.GPIO_pinoptype == GPIO_OP_PP)
			{
				regtemp = GPIO_OP_PP << (pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->OTYPER &= ~(0x3 << pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->OTYPER |= regtemp;
				regtemp = 0;
			}
			if(pGPIOx->GPIOpinconfig.GPIO_pinoptype == GPIO_OP_DR)
			{
				regtemp = GPIO_OP_DR << (pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->OTYPER &= ~(0x3 << pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->OTYPER |= regtemp;
				regtemp = 0;
			}
			break;

		case GPIO_MODE_IN:
			// read mode
			regtemp =  GPIO_MODE_IN << (2 * pGPIOx->GPIOpinconfig.GPIO_pinnumber);
			pGPIOx->pGPIOaddrx->OTYPER &= ~(0x3 << pGPIOx->GPIOpinconfig.GPIO_pinnumber);
			pGPIOx->pGPIOaddrx->MODER |= regtemp;
			regtemp = 0;
			break;

		case GPIO_MODE_ALT:
			// alernative functionality
			alterpin = pGPIOx->GPIOpinconfig.GPIO_pinnumber / 8;
			gpio_alt_fun gpio_alt = pGPIOx->GPIOpinconfig.GPIO_pinaltfunction;
			if(alterpin == 0)
			{
				regtemp = gpio_alt << (4 * (pGPIOx->GPIOpinconfig.GPIO_pinnumber % 8));
				pGPIOx->pGPIOaddrx->AFRL &= ~(0x3 << pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->AFRL |= regtemp;
			}
			else if(alterpin == 1)
			{
				regtemp = gpio_alt << (4 * (pGPIOx->GPIOpinconfig.GPIO_pinnumber % 8));
				pGPIOx->pGPIOaddrx->AFRH &= ~(0x3 << pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->AFRH |= regtemp;
			}
			break;

		case GPIO_MODE_ANG:
			// need to write
			break;
	}
	// configure the speed
	uint8_t speed = pGPIOx->GPIOpinconfig.GPIO_pinspeed;
	pGPIOx->pGPIOaddrx->OSPEEDR &= ~(0x3 << pGPIOx->GPIOpinconfig.GPIO_pinnumber);
	switch(speed)
	{
			case GPIO_LOW_SPEED:
				regtemp =  GPIO_LOW_SPEED << (2 * pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->OSPEEDR |= regtemp;
				regtemp = 0;
				break;
			case GPIO_MED_SPEED:
				regtemp =  GPIO_MED_SPEED << (2 * pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->OSPEEDR |= regtemp;
				regtemp = 0;
				break;
			case GPIO_FAST_SPEED:
				regtemp =  GPIO_FAST_SPEED << (2 * pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->OSPEEDR |= regtemp;
				regtemp = 0;
				break;
			case GPIO_HIGH_SPEED:
				regtemp =  GPIO_HIGH_SPEED << (2 * pGPIOx->GPIOpinconfig.GPIO_pinnumber);
				pGPIOx->pGPIOaddrx->OSPEEDR |= regtemp;
				regtemp = 0;
				break;
	}
	//configure the pushpull configuration
	regtemp =  pGPIOx->GPIOpinconfig.GPIO_pinpupdcontrol << (2 * pGPIOx->GPIOpinconfig.GPIO_pinnumber);
	pGPIOx->pGPIOaddrx->PUPDR &= ~(0xF << pGPIOx->GPIOpinconfig.GPIO_pinnumber);
	pGPIOx->pGPIOaddrx->PUPDR |= regtemp;
	regtemp = 0;
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
void GPIO_deinit(GPIO_regdef_t *pGPIOx)
{
	if(pGPIOx == GPIOA_ADDR)
		GPIOA_RST();
	if(pGPIOx == GPIOB_ADDR)
		GPIOB_RST();
	if(pGPIOx == GPIOC_ADDR)
		GPIOC_RST();
	if(pGPIOx == GPIOD_ADDR)
		GPIOD_RST();
	if(pGPIOx == GPIOE_ADDR)
		GPIOE_RST();
	if(pGPIOx == GPIOF_ADDR)
		GPIOF_RST();
	if(pGPIOx == GPIOG_ADDR)
		GPIOG_RST();
	if(pGPIOx == GPIOH_ADDR)
		GPIOH_RST();
}
uint8_t GPIO_read_input_pin(GPIO_regdef_t *pGPIOreadhandle ,uint8_t pinnumber)
{
	    /*right shift the pin value to 0 pin location and then & with 0x01 to obtain 1 or 0*/
		uint8_t pinvalue = (uint8_t)((pGPIOreadhandle->IDR >> pinnumber) & 0x01);
		return pinvalue;
}
uint16_t GPIO_read_input_port(GPIO_regdef_t *pGPIOhandle)
{
	uint16_t readport = (uint16_t)(pGPIOhandle->IDR);
	return readport;
}
void GPIO_toggle_pin(GPIO_regdef_t *pGPIOtogglehandle ,uint8_t pinnumber)
{
	uint8_t readpinvalue = (uint8_t)((pGPIOtogglehandle->IDR >> pinnumber) & 0x01);
	uint8_t togglepin = 1 << pinnumber;
	if(readpinvalue == 1)
		pGPIOtogglehandle->ODR &= ~togglepin;
	else
		pGPIOtogglehandle->ODR |= togglepin;

}
void GPIO_write_output_pin(GPIO_regdef_t *pGPIOhandle ,uint8_t pinnumber , gpio_write_pin value)
{
	uint8_t writepin = 1 << pinnumber;
	if(value == GPIO_PIN_SET)
	{
		pGPIOhandle->ODR |= writepin;
	}
	else if(value == GPIO_PIN_RESET)
	{
		pGPIOhandle->ODR &= ~writepin;
	}
}
void GPIO_write_output_port(GPIO_regdef_t *pGPIOhandle, uint16_t portvalue)
{
	pGPIOhandle->ODR = portvalue;
}
