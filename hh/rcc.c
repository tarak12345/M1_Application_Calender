#include "stm32f4xx.h"

void config_rcc(void *ptr)
{
	if ((GPIORegDef *) ptr == GPIOD)
	{
		RCC->AHB1ENR = RCC->AHB1ENR | 0x8;
	}
	
	if ((GPIORegDef *) ptr == GPIOA)
	{
		RCC->AHB1ENR = RCC->AHB1ENR | 0x1;
	}
}


