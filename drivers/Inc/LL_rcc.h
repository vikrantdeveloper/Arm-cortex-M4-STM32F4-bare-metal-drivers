/* 	MIT License
 * 	LL_rcc.h
 *
 *  Created on: 18 Aug 2020
 *  Author: Vikrant Thakur(vikrantthakur97@gmail.com)
 */

#ifndef INC_LL_RCC_H_
#define INC_LL_RCC_H_
#include "stm32f4xx.h"

/* by default the clock selection mode is 3 */
typedef struct
{
	vo uint32_t  CR; 												/*!< clock selection mode offset - 0x00>*/
	vo uint32_t  PLL_CFGR;										    /*!< PLL clock configuration offset - 0x04>*/
	vo uint32_t  CFGR;                                              /*!< bus clock frequency selection register offset - 0x08>*/
	vo uint32_t  CIR;                                               /*!< clock interrupt peripheral register offset - 0x0C>*/
	vo uint32_t  AHB1RSTR;											/*!< AHB1 peripheral reset register offset - 0x10>*/
	vo uint32_t  AHB2RSTR;											/*!< AHB2 peripheral reset register offset - 0x14>*/
	vo uint32_t  AHB3RSTR;                                          /*!< AHB2 peripheral reset register offset - 0x18>*/
	uint32_t     RESERVED[1];									    /*!< 4 bytes reserved offset - 0x1C>*/
	vo uint32_t  APB1RSTR;											/*!< APB1 peripheral reset register offset - 0x20>*/
	vo uint32_t	 APB2RSTR;											/*!< APB2 peripheral reset register offset - 0x24>*/
	uint32_t     RESERVED[2];                                       /*!< 8 bytes reserved offset - 0x28>*/
	vo uint32_t	 AHB1ENR;                                           /*!< AHB1 peripheral enable register offset - 0x30>*/
	vo uint32_t	 AHB2ENR;										    /*!< AHB2 peripheral enable register offset - 0x34>*/
	uint32_t     RESERVED[1];										/*!< 4 bytes reserved offset - 0x3C>*/
	vo uint32_t	 AHB3ENR;											/*!< AHB2 peripheral enable clock register offset - 0x3C>*/
	vo uint32_t	 APB1ENR;											/*!< APB1 peripheral enable clock register offset - 0x40>*/
	vo uint32_t  APB2ENR;											/*!< APB2 peripheral enable clock register offset - 0x44>*/
	uint32_t     RESERVED[2];                                       /*!< 8 bytes reserved offset - 0x48 - low power mode clocks modes>*/
	vo uint32_t  AHB1LPENR;											/*!< AHB1 clock enable in low power mode register offset - 0x50>*/
	vo uint32_t  AHB3LPENR;											/*!< AHB1 clock enable in low power mode register offset - 0x54>*/
	vo uint32_t  AHB3LPENR;											/*!< AHB3 clock enable in low power mode register offset - 0x58>*/
	uint32_t     RESERVED[1];										/*!< 8 bytes reserved offset - 0x5C>*/
	vo uint32_t  APB1LPENR;                                         /*!< APB1 clock enable in low power mode register offset - 0x60>*/
	vo uint32_t  APB2LPENR;											/*!< APB2 clock enable in low power mode register offset - 0x64>*/
	uint32_t     RESERVED[2];										/*!< 8 bytes reserved offset - 0x68>*/
	vo uint32_t  RCC_BDCR;											/*!< System reset write protected register offset - 0x70>*/
 }RCC_regdef_t;

#define RCC        (RCC_regdef_t *)RCC_ADDR

#endif /* INC_LL_RCC_H_ */
