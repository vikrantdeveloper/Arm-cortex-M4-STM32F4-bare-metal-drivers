/*
 * LL_rcc.h
 *
 *  Created on: 18-Aug-2020
 *      Author: vikrant
 */

#ifndef INC_LL_RCC_H_
#define INC_LL_RCC_H_
#include "stm32f4xx.h"

typedef struct
{
	vo uint32_t  CR; 												/*!< configure the mode address offset - 0x00>*/
	vo uint32_t PLL_CFGR;
	vo uint32_t  CFGR;
	vo uint32_t CIR;
	vo uint32_t AHB1RSTR;
	vo uint32_t AHB2RSTR;
	vo uint32_t AHB3RSTR;
	vo uint32_t APB1RSTR;
	vo uint32_t	APB2RSTR;
	uint32_t       RESERVED[2];
	vo uint32_t	AHB1ENR;
	vo uint32_t	AHB2ENR;
	vo uint32_t	AHB3ENR;
	uint32_t       RESERVED[1];
	vo uint32_t	APB1ENR;
	vo uint32_t  APB2ENR;
	uint32_t       RESERVED[2];
};

#endif /* INC_LL_RCC_H_ */
