#include "TimeOut.h"


volatile clock_time_t InsBaseNum=0;

void TimeOutDet_Init(void)
{
	InsBaseNum=0;
}


void TimeOutDet_DecHandle(void)
{
	InsBaseNum++;
}

clock_time_t TimeOut_BaseValue(void)
{
	return InsBaseNum;
}


//void TimeOut_Record(TIMEOUT_PARA * TimeOutPara,unsigned int timeoutvalue)
void TimeOut_Record(TIMEOUT_PARA * TimeOutPara,clock_time_t timeoutvalue)

{
	TimeOutPara->RecordValue=TimeOut_BaseValue();
	TimeOutPara->timeoutcnt=timeoutvalue;
}


void TimeOut_restart(TIMEOUT_PARA *TimeOutPara)
{	
	TimeOutPara->RecordValue = TimeOut_BaseValue();
}

clock_time_t TimeOutDet_Check(TIMEOUT_PARA * TimeOutPara)
{
	return (((clock_time_t)(InsBaseNum-TimeOutPara->RecordValue)>=TimeOutPara->timeoutcnt)?1:0);
}


