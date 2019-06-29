#include "stm8s_conf.h"

#define SDA_PORT         GPIOD
#define SDA_PIN          GPIO_PIN_2
#define SDA_Read()       GPIO_ReadInputPin(SDA_PORT,SDA_PIN)
#define SDA_Set(x)       ((x)?(GPIO_WriteHigh(SDA_PORT,SDA_PIN)):(GPIO_WriteLow(SDA_PORT,SDA_PIN)))

#define SCL_PORT         GPIOD
#define SCL_PIN          GPIO_PIN_3
#define SCL_Read()       GPIO_ReadInputPin(SCL_PORT,SCL_PIN)
#define SCL_Set(x)       ((x)?(GPIO_WriteHigh(SCL_PORT,SCL_PIN)):(GPIO_WriteLow(SCL_PORT,SCL_PIN)))


void IIC_Init(void)
{
    GPIO_Init(SDA_PORT,SDA_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
    SDA_Set(1);
    GPIO_Init(SCL_PORT,SCL_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
    SCL_Set(1);
}

/*Func: 0-->输入，，，，，1-->输出 */
int IIC_Port_SDA_Set(unsigned char Func)
{
    if(Func == 0){
       GPIO_Init(SDA_PORT,SDA_PIN,GPIO_MODE_IN_FL_NO_IT);
       return 0;
    }else if(Func == 1){
       GPIO_Init(SDA_PORT,SDA_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
       return 0;
    }else{
       return 1;
    }
}
/*Add:0-->SDA,,,,,,,,1-->SCL,,,,,,,,,Func:0-->低电平，1-->高电平 */
int IIC_Port_Write(unsigned char Add,unsigned char Func)
{
    if(Add == 0){
        if(Func == 0){
            SDA_Set(Func);
            return 0;
        }else if(Func == 1){
            SDA_Set(Func);
            return 0;
        }else{
            return 1;
        }

    }else if(Add == 1){
        if(Func == 0){
            SCL_Set(Func);
            return 0;
        }else if(Func == 1){
            SCL_Set(Func);
            return 0;
        }else{
            return 1;
        }
    }else{
        return 1;
    }
}

int IIC_Port_Read(unsigned char Func)
{
    if(Func == 0){
        return SDA_Read();
    }else if(Func == 1){
        return SCL_Read();
    }else{
        return 0;
    }
}














