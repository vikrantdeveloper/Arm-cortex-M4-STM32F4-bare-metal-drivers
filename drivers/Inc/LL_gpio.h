/*
 * LL_gpio.h
 *
 *  Created on: 18-Aug-2020
 *      Author: vikrant
 */

#ifndef INC_LL_GPIO_H_
#define INC_LL_GPIO_H_

/*!<GPIO registers>*/
typedef struct
{
	vo  uint32_t MODER;                             /*!< configure the mode address offset - 0x00>*/
	vo  uint32_t  OTYPER;							/*!<Output Port address offset - 0x04>*/
	vo  uint32_t OSPEEDR;						/*!< Configure Speed register address offset - 0x08>*/
	vo  uint32_t PUPDR;								/*!< configure the  pull-up down register address offset- 0x0C>*/
	vo  uint32_t IDR;									/*!< configure the read-only register address offset - 0x10>*/
	vo  uint32_t ODR;									/*!< configure the output mode register address offset - 0x14>*/
	vo  uint32_t BSRR;									/*!< configure the output bits as set or reset register address offset - 0x18>*/
	vo  uint32_t LCKR;									/*!< configure the lock mode register address offset - 0x1C>*/
	vo  uint32_t AFRL;									/*!< configure the alternative function register address offset - 0x20>*/
	vo  uint32_t AFRH;								/*!< configure the alternative function register address offset - 0x24*/

}GPIO_regdef_t;

#define GPIOA_ADDR                  (GPIO_regdef_t *)LL_GPIOA_BASE_ADDR

#endif /* INC_LL_GPIO_H_ */
