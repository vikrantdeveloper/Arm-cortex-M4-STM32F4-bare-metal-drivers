/*
 *  MIT License
 * 	LL_gpio.h
 *  Created on: 18 Aug 2020
 *  Author: Vikrant Thakur(vikrantthakur97@gmail.com)
 *  Copyright (c) 2020
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
	uint8_t GPIO_pinnumber;                        /*!<GPIO pinnumber @GPIO pin number>*/
	uint8_t GPIO_mode;                             /*!<GPIO modepin @GPIO modes>*/
	uint8_t GPIO_pinspeed;						   /*!<GPIO pinspeed @GPIO Output Speed> , configure the slew rate of the GPIO*/
	uint8_t GPIO_pinoptype;						   /*!<GPIO outputvalue @GPIO Output Type>*/
	uint8_t GPIO_pinpupdcontrol;				   /*!<GPIO pupdcontrol @GPIO Push-pull resistance>*/
	uint8_t GPIO_pinaltfunction;				   /*!<GPI0 pinaltfunction >*/
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
 * GPIO pin number
 */
typedef enum
{
	GPIO_PIN_1 = 1,
	GPIO_PIN_2 = 2,
	GPIO_PIN_3 = 3,
	GPIO_PIN_4 = 4,
	GPIO_PIN_5 = 5,
	GPIO_PIN_6 = 6,
	GPIO_PIN_7 = 7,
	GPIO_PIN_8 = 8,
	GPIO_PIN_9 = 9,
	GPIO_PIN_10 = 10,
	GPIO_PIN_11 = 11,
	GPIO_PIN_12 = 12,
	GPIO_PIN_13 = 13,
	GPIO_PIN_14 = 14,
	GPIO_PIN_15 = 15
}gpio_pins;
/*
 * GPIO modes
 */
#define GPIO_MODE_IN     0             // INPUT MODE //
#define GPIO_MODE_OP     1			   // OUTPUT MODE //
#define GPIO_MODE_ALT    2			   // ALTERNATE MODE //
#define GPIO_MODE_ANG    3			   // ANALOG MODE //
#define GPIO_MODE_IT_FT  4             // GPIO INTERRUPT GENERATE IN FALLING EDGE READ//
#define GPIO_MODE_IT_RT  5			   // GPIO INTERRUPT GENERATE IN RISING EDGE READ//
#define GPIO_MODE_IT_RFT 6             // GPIO INTERRUPT GENERATE IN RISING FAILING EDGE READ //
/*
 * GPIO Output Type
 */
#define GPIO_OP_PP    0                // PUSH PULL OUTPUT //
#define GPIO_OP_DR    1			   	   // OPEN DRAIN //
/*
 * GPIO Output Speed
 */
#define GPIO_LOW_SPEED  0			   // GPIO LOW SPEED //
#define GPIO_MED_SPEED  1			   // GPIO MEDIUM SPEED //
#define GPIO_FAST_SPEED 2			   // GPIO FAST SPEED //
#define GPIO_HIGH_SPEED 3			   // GPIO HIGH SPEED //
/*
 * GPIO Push-pull resistance
 */
#define GPIO_NO_PULLUPDOWN 0           // GPIO NO PULL UP DOWN RESISTANCE //
#define GPIO_PULLUP        1		   // GPIO PULL UP //
#define GPIO_PULLDOWN	   2		   // GPIO PULL DOWN //
#define GPIO_RESERVED      3		   // GPIO RESERVED //
/*
 * GPIO Alternative functionality
 */
typedef enum
{
	GPIO_AF1 = 0,  // SYSTEM //
	GPIO_AF2,  // TIM1/TIM2 //
	GPIO_AF3,  // TIM3/TIM4/TIM5/TIM6/TIM7/TIM8//
	GPIO_AF4,  // I2C1/I2C2/I2C3/I2C4/CEC//
	GPIO_AF5,  // SPI1/2/3/4
	GPIO_AF6,
	GPIO_AF7,
	GPIO_AF8,
	GPIO_AF9,
	GPIO_AF10,
	GPIO_AF11,
	GPIO_AF12,
	GPIO_AF13,
	GPIO_AF14,
	GPIO_AF15
}gpio_alt_fun;
/*
 * GPIO write pin value
 */
typedef enum{
	GPIO_PIN_SET = 0,
	GPIO_PIN_RESET = 1
}gpio_write_pin;
/*
 * @brief :- 	GPIO initialisation -> mode ,speed ,output type mode
 *
 * @param[in] :- pointer to GPIOs handler
 *
 * @note :- clear the bits before set them
 */
void GPIO_init(GPIO_handle_t *pGPIOx);
/*
 * @brief :- 	GPIO deinitialisation
 *
 * @param[in] :-pointer to GPIOs register
 *
 * @note :- reset the value in GPIO RTS
 */
void GPIO_deinit(GPIO_regdef_t *pGPIOx);
/*
 * @brief :- 	 Initialise the clock for given GPIO peripheral
 *
 * @param[in] :- pointer to GPIOs register definition
 * @param[in] :- SET OR RESET status for clock enable /disables
 *
 * @note :- None
 */
void GPIO_clock_control(GPIO_regdef_t *pGPIOx, gpio_enum status);
/*
 * @brief :- 	 read the pin for given GPIO peripheral pin
 *
 * @param[in] :- pointer to GPIOs register definition
 * @param[in] :- pin number
 *
 * @note :-      right shift the pin value to 0 pin location and then & with 0x01 to obtain 1 or 0 read logic
 */
uint8_t GPIO_read_input_pin(GPIO_regdef_t *pGPIOreadhandle ,uint8_t pinnumber);
/*
 * @brief :- 	 read the port for given GPIO peripheral
 *
 * @param[in] :- pointer to GPIOs register definition
 *
 * @note :-      None
 */
uint16_t GPIO_read_input_port(GPIO_regdef_t *pGPIOreadhandle);
/*
 * @brief :- 	 write the pin value for given GPIO peripheral pin
 *
 * @param[in] :- pointer to GPIOs register handle
 * @param[in] :- pin number of the port
 * @param[in] :- Write value to pin
 *
 * @note :-      None
 */
void GPIO_write_output_pin(GPIO_regdef_t *pGPIOhandle ,uint8_t pinnumber , gpio_write_pin value);
/*
 * @brief :- 	 write the port for given GPIO peripheral
 *
 * @param[in] :- pointer to GPIOs register handle
 * @param[in] :- port value of the port
 *
 * @note :-      None
 */
void GPIO_write_output_port(GPIO_regdef_t *pGPIOhandle, uint16_t portvalue);
/*
 * @brief :- 	 toggle the pin for given GPIO peripheral
 *
 * @param[in] :- pointer to GPIOs register handle
 * @param[in] :- pin number of the port
 *
 * @note :-      None
 */
void GPIO_toggle_pin(GPIO_regdef_t *pGPIOtogglehandle ,uint8_t pinnumber);
/*
 * @brief :- 	 GPIO config function
 *
 * @param[in] :- port of the select pin
 * @param[in] :- mode of the select pin
 * @param[in] :- pinnumber if not pass -1
 * @param[in] :- output type mode config - if the output mode is there select the output type mode else pass -1
 * @param[in] :- select the speed of the pin if the port is output type else pass -1
 * @note :-      None
 *
 * return :- 	address of the peripheral port
 */

GPIO_regdef_t *gpio_config(GPIO_regdef_t *port , uint8_t mode , uint8_t pinnumber, uint8_t output_mode_type , uint8_t pullup ,uint8_t speed);

// Interrupt IRQ No. & Handling
void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t IRQPriority , gpio_enum update);
void GPIO_IRQ_Handling(uint8_t pinnumber);

#endif /* INC_LL_GPIO_H_ */
