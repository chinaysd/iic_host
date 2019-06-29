#include "bsp_led.h"




void Led_Init(void)
{
    GPIO_Init(LED_PORT,LED_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
    LED_SET(1);
}


