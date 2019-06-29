#include "system.h"


unsigned char RevBuf[2];

void System_Init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV2);
    Led_Init();
    IIC_Port_Init();
}


void System_Handle(void)
{
    //IIC_Write_Data(0x5a,0xbf);
    IIC_Read_Data(0x5b,&RevBuf[1]);
    switch(RevBuf[1])
    {
        case 0x01:
             LED_SET(1);
             break;
        case 0x02:
             LED_SET(0);
             break;
        case 0x04:
             LED_SET(1);
             break;
        case 0x08:
             LED_SET(0);
             break;
        case 0x10:
             LED_SET(1);
             break;
        case 0x20:
             LED_SET(0);
             break;
        case 0x40:
             LED_SET(1);
             break;
        case 0x80:
             LED_SET(0);
             break;
        default:
             break;
    }
}


