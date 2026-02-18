#include "inc/RTCC.h"
#include <string.h>
#include "inc/userFncFile.h"

uint8_t rtc_firstTime = 1;

//setTime("YYMMDDhhmmss");
void setTime(char* strTime)
{
    tm_t auxDate={};
	if(strlen(strTime)>12)
	{
		strTime[12]=0;
	}
    if(strlen(strTime)==12)
	{
		auxDate.tm_year=(((*strTime)-'0')*10);
		strTime++;
		auxDate.tm_year+=((*strTime)-'0');
        auxDate.tm_year += 100;
		strTime++;
		auxDate.tm_mon=(((*strTime)-'0')*10);
		strTime++;
		auxDate.tm_mon+=((*strTime)-'0');
		auxDate.tm_mon+=(-1);
		strTime++;
		auxDate.tm_mday=(((*strTime)-'0')*10);
		strTime++;
		auxDate.tm_mday+=((*strTime)-'0');
		strTime++;
		
		auxDate.tm_hour=(((*strTime)-'0')*10);
		strTime++;
		auxDate.tm_hour+=((*strTime)-'0');
		strTime++;
		auxDate.tm_min=(((*strTime)-'0')*10);
		strTime++;
		auxDate.tm_min+=((*strTime)-'0');
		strTime++;
		auxDate.tm_sec=(((*strTime)-'0')*10);
		strTime++;
		auxDate.tm_sec+=((*strTime)-'0');
	}
    else 
    {
        return;
    }
    if(rtc_firstTime)
    {
        RTCC_init_t(&auxDate);
		rtc_firstTime=0;
    }
    else
    {
        RTCC_setTime(&auxDate);
    }
}

//getTime("DD/MM/YYYY hh:mm:ss");
char* getTime(void)
{
    tm_t* auxDate = RTCC_getTime();
    static char strTime[20];
    strftime(strTime,sizeof(strTime),"%d/%m/%Y %H:%M:%S",auxDate);
    return strTime;
}

void RTCC_Init(void)
{
    if(rtc_firstTime)
    {
        RTCC_init_t(NULL);
        rtc_firstTime = 0;
    }
}

