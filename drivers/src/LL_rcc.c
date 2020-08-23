/*  MIT License
 * 	stm32f4xx.h
 *
 *  Created on : 17-Aug-2020
 *  Author:  Vikrant thakur
 *  @open source GPIO driver
 */
#include "stm32f4xx.h"
#include "LL_rcc.h"

/*
 * pointer to RCC structure
 */
RCC_regdef_t *pRCC = RCC;

/*
 * clock enable or disable macros - RCC
 */
#define GPIOA_PCLK_EN()  ( pRCC->AHB1ENR | = (1<<0));   // enable clock for GPIOA peripheral
#define GPIOA_PCLK_DI()  ( pRCC->AHB1ENR & = ~(1<<0));  // disable clock for GPIOA peripheral
