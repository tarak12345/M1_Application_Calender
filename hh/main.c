#include "stm32f4xx.h"
#include "gpio.h"
#include "rcc.h"
#include <stdio.h>



static void init_config(void)
{
	config_rcc(GPIOD);
	config_gpiox(GPIOD, PIN_12, GPIO_OUTPUT_PP, GPIO_SPEED_VERY_HIGH);
	config_gpiox(GPIOD, PIN_13, GPIO_OUTPUT_PP, GPIO_SPEED_VERY_HIGH);
	config_gpiox(GPIOD, PIN_14, GPIO_OUTPUT_PP, GPIO_SPEED_VERY_HIGH);
	config_gpiox(GPIOD, PIN_15, GPIO_OUTPUT_PP, GPIO_SPEED_VERY_HIGH);
	
	config_rcc(GPIOA);
	config_gpiox(GPIOA, PIN_0, GPIO_INPUT, GPIO_SPEED_VERY_HIGH);
		
}


int main(void)
{
	int key, red;
	
	long long wait = 0;

	init_config();
	

	while (1)
	{

    	key = gpiox_read_pin(GPIOA, PIN_0); 
	
		if (key == 1)
		{
			for (wait = 0x1FFFFFFF; wait--;);

		    gpiox_set(GPIOD, PIN_14);  // RED LED ON
		    for (wait = 0x1FFFFFFF; wait--;);
				
		}
		
		red = gpiox_read_pin(GPIOD, PIN_14); 
		
		if (red == 1)
		{
			
			gpiox_toggle(GPIOD, PIN_15);  // BLUE LED BLINKS
	        gpiox_toggle(GPIOD, PIN_12);  // GREEN LED BLINKS
	        gpiox_toggle(GPIOD, PIN_13);  // ORANGE LED BLINKS
		}	

    }
}
