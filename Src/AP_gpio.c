#include "AP_gpio.h"
#include  "main.h"


GPIO_regdef_t *gpio_config(GPIO_regdef_t *port , uint8_t mode , uint8_t pinnumber, uint8_t output_mode_type , uint8_t pullup ,uint8_t speed)
{

	GPIO_handle_t GPIO_handle;
	GPIO_handle.pGPIOaddrx = port;
	GPIO_handle.GPIOpinconfig.GPIO_mode = mode;
	GPIO_handle.GPIOpinconfig.GPIO_pinnumber = pinnumber;
	GPIO_handle.GPIOpinconfig.GPIO_pinpupdcontrol = pullup;
	if(GPIO_handle.GPIOpinconfig.GPIO_mode == GPIO_MODE_OP && output_mode_type != -1)
	{
		GPIO_handle.GPIOpinconfig.GPIO_pinspeed =  speed;
		GPIO_handle.GPIOpinconfig.GPIO_pinoptype = output_mode_type;
	}
	GPIO_init(&GPIO_handle);
	return port;
}
