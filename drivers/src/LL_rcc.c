/*  MIT License
 * 	stm32f4xx.h
 *
 *  Created on : 17-Aug-2020
 *  Author:  Vikrant thakur
 *  @open source RCC driver
 */
#include "stm32f4xx.h"
#include "LL_rcc.h"

RCC_regdef_t *pRCC = (RCC_regdef_t *)RCC_ADDR;
