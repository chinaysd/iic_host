#ifndef _IIC_H_
#define _IIC_H_


#define IIC_DelayTime     0

#define IIC_SDA           0
#define IIC_SCL           1

#define IN                0
#define OUT               1

















void IIC_Port_Init(void);
int IIC_Write_Data(unsigned char Add,unsigned char Write_Data);
int IIC_Read_Data(unsigned char Add,unsigned char *Read_Data);


#endif



