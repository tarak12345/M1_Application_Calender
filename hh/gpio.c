#include "stm32f4xx.h"

void config_gpiox(GPIORegDef *gpiox, int pin, int mode, int speed)
{
	switch (mode & 0x3)
	{
		case 0:
			break;
		case 1:
			gpiox->MODER = (gpiox->MODER & ~(0x3 << (pin * 2))) | ((mode & 0x3) << (pin * 2));
			gpiox->OTYPER = (gpiox->OTYPER & ~(0x1 << pin)) | ((mode >> 0x4) << pin);
			gpiox->OSPEEDR = (gpiox->OSPEEDR & ~(0x3 << (pin * 2))) | (speed << (pin * 2));
			break;
		case 2:
			break;
		case 3:
			break;
	}
}

void gpiox_set(GPIORegDef *gpiox, int pin)
{
	gpiox->BSRR = 1 << pin;
}

void gpiox_clear(GPIORegDef *gpiox, int pin)
{
	gpiox->BSRR = (1 << 16) << pin;
}

void gpiox_write(GPIORegDef *gpiox, int pin, int value)
{
	gpiox->ODR = value ? ((gpiox->ODR) | (1 << pin)) : ((gpiox->ODR) & ~(1 << pin));
}

void gpiox_toggle(GPIORegDef *gpiox, int pin)
{
	gpiox->BSRR = (gpiox->ODR & (1 << pin)) ? ((1 << 16) << pin) : (1 << pin);
}

int gpiox_read_pin(GPIORegDef *gpiox, int pin)
{
	return (gpiox->IDR >> pin) & 1;
}
