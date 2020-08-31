/*
 * 	MIT License
 * 	Created on : 17-Aug-2020
  	Author:  Vikrant thakur
	Copyright (c) 2020 Vikrant Thakur(vikrantthakur97@gmail.com)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.

 */
#include "stm32f4xx.h"
#include "main.h"

int main(void)
{
	GPIO_clock_control(GPIOA_ADDR, CLK_SET);
	GPIO_regdef_t *port = gpio_config(GPIOA_ADDR, GPIO_MODE_OP , GPIO_PIN_5, GPIO_OP_PP, GPIO_NO_PULLUPDOWN ,GPIO_MED_SPEED);
	while(1)
	{
		GPIO_toggle_pin(port, GPIO_PIN_5);
		delay(50);
	}
}
