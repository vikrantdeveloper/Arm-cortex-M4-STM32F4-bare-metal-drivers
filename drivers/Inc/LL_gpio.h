/* MIT License
 * LL_gpio.h
 *
 *  Created on: 18 Aug 2020
 *  Author: Vikrant Thakur(vikrantthakur97@gmail.com)
 */

#ifndef INC_LL_GPIO_H_
#define INC_LL_GPIO_H_
#include "stm32f4xx.h"

/*!<GPIO registers>*/
typedef struct
{
	vo  uint32_t MODER;                             /*!< configure the mode address offset - 0x00>*/
	vo  uint32_t OTYPER;							/*!< Output Port address offset - 0x04>*/
	vo  uint32_t OSPEEDR;							/*!< Configure Speed register address offset - 0x08>*/
	vo  uint32_t PUPDR;								/*!< configure the  pull-up down register address offset- 0x0C>*/
	vo  uint32_t IDR;								/*!< configure the read-only register address offset - 0x10>*/
	vo  uint32_t ODR;								/*!< configure the output mode register address offset - 0x14>*/
	vo  uint32_t BSRR;								/*!< configure the output bits as set or reset register address offset - 0x18>*/
	vo  uint32_t LCKR;								/*!< configure the lock mode register address offset - 0x1C>*/
	vo  uint32_t AFRL;								/*!< configure the alternative function register address offset - 0x20>*/
	vo  uint32_t AFRH;								/*!< configure the alternative function register address offset - 0x24*/
}GPIO_regdef_t;

#define GPIOA_ADDR                  (GPIO_regdef_t *)LL_GPIOA_BASE_ADDR


/*
 * GPIO Pin configuration structure
 */
typedef struct
{
	uint8_t GPIO_pinnumber;                        /*!<GPIO pinnumber>*/
	uint8_t GPIO_mode;                             /*!<GPIO modepin>*/
	uint8_t GPIO_pinspeed;						   /*!<GPIO pinspeed>*/
	uint8_t GPIO_pinoptype;						   /*!<GPIO outputvalue>*/
	uint8_t GPIO_pinpupdcontrol;				   /*!<GPIO pupdcontrol>*/
	uint8_t GPIO_pinaltfunction;				   /*!<GPI0 pinaltfunction -uart/spi/i2c>*/
}GPIO_pinconfig_t;

/*
 * GPIO handler structure
 */
typedef struct
{
	GPIO_regdef_t *pGPIOaddr;    				   /*!<base address of GPIO peripheral>*/
	GPIO_pinconfig_t GPIOpinconfig;

}GPIO_handle_t;

/*
 * GPIO driver function API
 */
// Initialisation GPIO API
extern void GPIO_init(void);
extern void GPIO_deinit(void);

// Clock Configuration API
extern void GPIO_clock_control(void);

// GPIO read & write pin ,port
extern void GPIO_read_input_pin(void);
extern void GPIO_read_input_port(void);
extern void GPIO_write_output_pin(void);
extern void GPIO_write_output_port(void);

// Interrupt IRQ No. & Handling
extern void GPIO_IRQ_Config(void);
extern void GPIO_IRQ_Handling(void);

#endif /* INC_LL_GPIO_H_ */
