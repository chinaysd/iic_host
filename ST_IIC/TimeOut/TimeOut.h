#ifndef _TIMEOUT_H_
#define _TIMEOUT_H_

typedef unsigned int clock_time_t;

typedef struct
{
	clock_time_t RecordValue;
	clock_time_t timeoutcnt;
}
TIMEOUT_PARA;



/*  function defined*/

void TimeOutDet_Init(void);
void TimeOutDet_DecHandle(void);
clock_time_t TimeOut_BaseValue(void);
void TimeOut_Record(TIMEOUT_PARA * TimeOutPara,clock_time_t timeoutvalue);
//void TimeOut_Record(TIMEOUT_PARA * TimeOutPara,unsigned int timeoutvalue);
void TimeOut_restart(TIMEOUT_PARA *TimeOutPara);
clock_time_t TimeOutDet_Check(TIMEOUT_PARA * TimeOutPara);

#endif



