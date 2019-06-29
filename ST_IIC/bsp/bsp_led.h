#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "stm8s_conf.h"

#define LED_PORT      GPIOD
#define LED_PIN       GPIO_PIN_4
#define LED_SET(X)    ((X)?(GPIO_WriteHigh(LED_PORT,LED_PIN)):(GPIO_WriteLow(LED_PORT,LED_PIN)))








void Led_Init(void);



#endif
