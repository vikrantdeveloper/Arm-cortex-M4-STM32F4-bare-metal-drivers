/* MIT License
 * LL_gpio.h
 *
 *  Created on: 18 Aug 2020
 *  Author: Vikrant Thakur(vikrantthakur97@gmail.com)
 */

#ifndef INC_LL_GPIO_H_
#define INC_LL_GPIO_H_
#include "stm32f4xx.h"

/*
 * GPIO registers
 */
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
/*
 * GPIO's base address
 */
#define GPIOA_ADDR                  (GPIO_regdef_t *)LL_GPIOA_BASE_ADDR
#define GPIOB_ADDR                  (GPIO_regdef_t *)LL_GPIOB_BASE_ADDR
#define GPIOC_ADDR					(GPIO_regdef_t *)LL_GPIOC_BASE_ADDR
#define GPIOD_ADDR					(GPIO_regdef_t *)LL_GPIOD_BASE_ADDR
#define GPIOE_ADDR					(GPIO_regdef_t *)LL_GPIOE_BASE_ADDR
#define GPIOF_ADDR					(GPIO_regdef_t *)LL_GPIOF_BASE_ADDR
#define GPIOG_ADDR					(GPIO_regdef_t *)LL_GPIOG_BASE_ADDR
#define GPIOH_ADDR					(GPIO_regdef_t *)LL_GPIOH_BASE_ADDR

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
	GPIO_regdef_t *pGPIOaddrx;    				   /*!<base address of GPIO peripheral>*/
	GPIO_pinconfig_t GPIOpinconfig;

}GPIO_handle_t;

/*
 * enable or disable GPIO clock
 */
typedef enum
{
	CLK_SET = 0,
	CLK_RESET = 1
}gpio_enum;

/*
 * GPIO driver function API
 */
// Initialisation GPIO API
void GPIO_init(GPIO_handle_t *pGPIOx);
void GPIO_deinit(GPIO_regdef_t *pGPIOx);    // only one register can reset the value in GPIO RTS


/*
 * @brief :- Clock Configuration API for GPIO
 *
 * @param[in]
 * @param[in]
 *
 * @note
 */

void GPIO_clock_control(GPIO_regdef_t *pGPIOx, gpio_enum status);

// GPIO read & write pin ,port
uint8_t GPIO_read_input_pin(GPIO_regdef_t *pGPIOhandle ,uint8_t pinnumber);
uint16_t GPIO_read_input_port(GPIO_regdef_t *pGPIOhandle);
uint8_t GPIO_write_output_pin(GPIO_regdef_t *pGPIOhandle ,uint8_t pinnumber);
uint16_t GPIO_write_output_port(GPIO_regdef_t *pGPIOhandle, uint16_t portvalue);
void GPIO_toggle_pin(GPIO_regdef_t *pGPIOhandle ,uint8_t pinnumber);

// Interrupt IRQ No. & Handling
void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t IRQPriority , gpio_enum update);
void GPIO_IRQ_Handling(uint8_t pinnumber);

#endif /* INC_LL_GPIO_H_ */
