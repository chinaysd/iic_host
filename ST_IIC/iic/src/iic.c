#include "iic.h"


extern  void IIC_Init(void);
extern int IIC_Port_SDA_Set(unsigned char Func);
extern int IIC_Port_Write(unsigned char Add,unsigned char Func);
extern int IIC_Port_Read(unsigned char Func);


static void IIC_Delay_us(unsigned int delay)
{
    unsigned int Cnts;
    while(delay -- )
    {
          for(Cnts = IIC_DelayTime; Cnts > 0; Cnts -- );
    }
}

void IIC_Port_Init(void)
{
    IIC_Init();
}

static void IIC_Start(void)
{
   IIC_Port_Write(IIC_SDA,1);
   IIC_Delay_us(IIC_DelayTime);
   IIC_Port_Write(IIC_SCL,1);
   IIC_Delay_us(IIC_DelayTime);
   IIC_Port_Write(IIC_SDA,0);
   IIC_Delay_us(IIC_DelayTime);
   IIC_Port_Write(IIC_SCL,0);
   IIC_Delay_us(IIC_DelayTime);
}

static unsigned char IIC_WriteData(unsigned char Data)
{
    unsigned char i,AckStatus;
    for(i = 0; i < 8 ; i ++){
        if(Data & 0x80){
           IIC_Port_Write(IIC_SDA,1);
        }else{
           IIC_Port_Write(IIC_SDA,0);
        }
        IIC_Delay_us(IIC_DelayTime);
        Data <<= 1;
        IIC_Port_Write(IIC_SCL,1);
        IIC_Delay_us(IIC_DelayTime);
        IIC_Port_Write(IIC_SCL,0);
        IIC_Delay_us(IIC_DelayTime);
    }
    IIC_Port_SDA_Set(IN);
    IIC_Port_Write(IIC_SCL,1);
    IIC_Delay_us(IIC_DelayTime);
    if(!IIC_Port_Read(IIC_SDA)){
        AckStatus = 1;
    }else{
        AckStatus = 0;
    }
    IIC_Port_Write(IIC_SCL,0);
    IIC_Delay_us(IIC_DelayTime);
    IIC_Port_SDA_Set(OUT);
    return AckStatus;
}

static void IIC_Stop(void)
{
    IIC_Port_Write(IIC_SCL,0);
    IIC_Delay_us(IIC_DelayTime);
    IIC_Port_Write(IIC_SCL,1);
    IIC_Delay_us(IIC_DelayTime);
    IIC_Port_Write(IIC_SDA,1);
    IIC_Delay_us(IIC_DelayTime);
    IIC_Delay_us(1000);
}

static void IIC_Nck(void)
{
    IIC_Port_Write(IIC_SDA,1);
    IIC_Delay_us(IIC_DelayTime);
    IIC_Port_Write(IIC_SCL,1);
    IIC_Delay_us(IIC_DelayTime);
    IIC_Port_Write(IIC_SCL,0);
    IIC_Delay_us(IIC_DelayTime);
    IIC_Port_Write(IIC_SDA,0);
    IIC_Delay_us(IIC_DelayTime);
}

static unsigned char IIC_ReadData(void)
{
    unsigned char j,Read = 0;
    IIC_Port_SDA_Set(IN);
    IIC_Delay_us(IIC_DelayTime);
    for(j = 0;j < 8 ;j ++)
    {
       IIC_Port_Write(IIC_SCL,1);
       IIC_Delay_us(IIC_DelayTime); 
       if(IIC_Port_Read(IIC_SDA)){
          Read = Read | (0x80 >> j);
       }
       IIC_Port_Write(IIC_SCL,0);
       IIC_Delay_us(IIC_DelayTime);
    }
    IIC_Port_SDA_Set(OUT);
    return Read;
}


int IIC_Write_Data(unsigned char Add,unsigned char Write_Data)
{
    IIC_Start();
    if(!IIC_WriteData(Add)){
        IIC_Stop();
        return 0;
    }
    if(!IIC_WriteData(Write_Data)){
        IIC_Stop();
        return 0;
    }
    IIC_Nck();
    IIC_Stop();
    return 0;
}

int IIC_Read_Data(unsigned char Add,unsigned char *Read_Data)
{
    IIC_Start();
    if(!IIC_WriteData(Add)){
        IIC_Stop();
        return 0;
    }
    *Read_Data = IIC_ReadData();
    IIC_Nck();
    IIC_Stop();
    return 0;
}




