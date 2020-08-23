/*  MIT License
 * 	stm32f4xx.h
 *
 *  Created on : 17-Aug-2020
 *  Author:  Vikrant thakur
 *  @open source GPIO driver
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_

// Req. Definition
#include <stdint.h>

#define vo volatile

/*
 * base address for the RCC
 */
#define RCC_ADDR       0x40023800U //<!RCC start address - clock>
/*
 * base address for the Internal memories
 */
#define FLASH_ADDR 	   0x08000000U   //<!Flash start address>

#define SRAM1_ADDR 	   0x20000000U   //<!SRAM1 start address>

#define SRAM2_ADDR 	   0x2001C000U   //<!SRAM2 start address>

#define ROM_ADDR   	   0x1FFF0000U    // <!ROM start address>

/*
 * base address of the Buses - APB & AHB bus in ARM M controllers
 */
#define PERIPH_BASE_ADDR      	0x40000000U          		//<!Peripheral base address>

#define APB1PERIPH_BASE_ADDR 	PERIPH_BASE_ADDR    		//<!APB1 Peripheral Address>

#define APB2PERIPH_BASE_ADDR    0x40010000U   				//<!APB2 Peripheral Address>

#define AHB1PERIPH_BASE_ADDR    0x40020000U 				//<!AHB1 Peripheral Address>

#define AHB2PERIPH_BASE_ADDR    0x50000000U					//<!AHB2 Peripheral Address>

/*
 * base address of the GPIO PORTS
 */
#define LL_GPIOA_BASE_ADDR                                        (AHB1PERIPH_BASE_ADDR + 0x0000)

#define LL_GPIOB_BASE_ADDR										  (AHB1PERIPH_BASE_ADDR +  0x0400)

#define LL_GPIOC_BASE_ADDR                                        (AHB1PERIPH_BASE_ADDR + 0x0800)

#define LL_GPIOD_BASE_ADDR										  (AHB1PERIPH_BASE_ADDR +  0x0C00)

#define LL_GPIOE_BASE_ADDR                                        (AHB1PERIPH_BASE_ADDR +  0x1000)

#define LL_GPIOF_BASE_ADDR										  (AHB1PERIPH_BASE_ADDR +  0x1400)

#define LL_GPIOG_BASE_ADDR										  (AHB1PERIPH_BASE_ADDR +  0x1800)

#define LL_GPIOH_BASE_ADDR									      (AHB1PERIPH_BASE_ADDR +   0x1C00)

#endif /* INC_STM32F4XX_H_ */
