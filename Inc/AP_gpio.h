/*
  * 	MIT License
  * 	Created on : 17-Aug-2020
  * 	Author:  Vikrant thakur
  * 	Copyright (c) 2020 Vikrant Thakur(vikrantthakur97@gmail.com)
 */

#ifndef AP_GPIO_H_
#define AP_GPIO_H_

#include "LL_gpio.h"

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


#endif /* AP_GPIO_H_ */
