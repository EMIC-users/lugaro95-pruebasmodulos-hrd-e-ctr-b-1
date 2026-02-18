#include "inc/Alarm.h"
#include "inc/RTCC.h"
#include <string.h>
#include "inc/userFncFile.h"

static int previousDay = -1;
static int previousWeek = -1;
static int previousMonth = -1;

uint16_t persist_ DailyFlags;
uint16_t persist_ WeeklyFlags;
uint16_t persist_ MonthlyFlags;
uint32_t persistArray_ dailyAlarm[16];
uint32_t persistArray_ weeklyAlarm[40];
uint32_t persistArray_ monthlyAlarm[4];

extern tm_t rtc_date;
extern uint8_t rtc_newTimeSetted;
extern uint32_t daySeconds;
extern uint32_t weekSeconds;
extern uint32_t monthSeconds;

void initAlarms(void)
{
	for(int i = 0; i < 16; i++)
	{
		dailyAlarm[i] = -1;
	}
	for(int i = 0; i < 40; i++)
	{
		weeklyAlarm[i] = -1;
	}
	for(int i = 0; i < 4; i++)
	{
		monthlyAlarm[i] = -1;
	}
	DailyFlags     = 0;
	WeeklyFlags    = 0;
	MonthlyFlags   = 0;
}

void pollAlarms(void)
{
	resetAlarmFlags();
	if(!rtc_firstTime)
	{
		if(rtc_newTimeSetted)
		{
			rtc_newTimeSetted = 0;
			AlarmCheckOld();
			return;
		}
		static uint8_t aux = 0;
		#ifdef event_eDailyAlarm_active
		for(int i = 0; i < 16; i++)
		{
			if((daySeconds>=dailyAlarm[i]) && !(DailyFlags & (1 << i)))
			{
				aux = i+1;
				eDailyAlarm(&aux);
				DailyFlags |= (1 << i);
			}
		}
		#endif
		#ifdef event_eWeeklyAlarm_active
		for(int i = 0; i < 40; i++)
		{
			if((weekSeconds>=weeklyAlarm[i]) && !(WeeklyFlags & (1 << i)))
			{
				aux = i+1;
				eWeeklyAlarm(&aux);
				WeeklyFlags |= (1 << i);
			}
		}
		#endif
		#ifdef event_eMonthlyAlarm_active
		for(int i = 0; i < 4; i++)
		{
			if((monthSeconds>=monthlyAlarm[i]) && !(MonthlyFlags & (1 << i)))
			{
				aux = i+1;
				eMonthlyAlarm(&aux);
				MonthlyFlags |= (1 << i);
			}
		}
		#endif
	}
}

void setDailyAlarm(uint8_t AlarmNumber,char* AlarmTime)
{
	dailyAlarm[AlarmNumber-1] = hourToSeconds(AlarmTime);
	if((daySeconds>=dailyAlarm[AlarmNumber-1]))
	{
		DailyFlags |= (1 << (AlarmNumber-1));
	}
}

void setWeeklyAlarm(uint8_t AlarmNumber,uint8_t DayOfWeek,char* AlarmTime)
{
	weeklyAlarm[AlarmNumber-1] = (DayOfWeek*86400)+hourToSeconds(AlarmTime);
	if((weekSeconds>=weeklyAlarm[AlarmNumber-1]))
	{
		WeeklyFlags |= (1 << (AlarmNumber-1));
	}
}

void setMonthlyAlarm(uint8_t AlarmNumber,uint8_t DayOfMonth,char* AlarmTime)
{
	monthlyAlarm[AlarmNumber-1] = ((DayOfMonth-1)*86400)+hourToSeconds(AlarmTime);
	if((monthSeconds>=monthlyAlarm[AlarmNumber-1]))
	{
		MonthlyFlags |= (1 << (AlarmNumber-1));
	}
}

uint32_t hourToSeconds(char* AlarmTime)
{
	if(strlen(AlarmTime)>6)
	{
		AlarmTime[6]=0;
	}
	if(strlen(AlarmTime)==6)
	{
		uint8_t hour,minute,seconds;
		hour=(((*AlarmTime)-'0')*10);
		AlarmTime++;
		hour+=((*AlarmTime)-'0');
		AlarmTime++;
		minute=(((*AlarmTime)-'0')*10);
		AlarmTime++;
		minute+=((*AlarmTime)-'0');
		AlarmTime++;
		seconds=(((*AlarmTime)-'0')*10);
		AlarmTime++;
		seconds+=((*AlarmTime)-'0');
		return (uint32_t)hour*3600+(uint32_t)minute*60+(uint32_t)seconds;
	}
    else 
    {
        return -1;
    }
}

void resetAlarmFlags(void)
{
    if( rtc_date.tm_yday != previousDay)
    {
		previousDay = rtc_date.tm_yday;
		DailyFlags	= 0;
    }
	uint8_t actual_week = rtc_date.tm_yday/7;
	if( actual_week != previousWeek)
    {
		previousWeek =actual_week;
        WeeklyFlags	= 0;
    }
    if( rtc_date.tm_mon != previousMonth)
    {
		previousMonth = rtc_date.tm_mon;
		MonthlyFlags= 0;
    }
}

void AlarmCheckOld(void)
{
	uint32_t aux = ((uint32_t)rtc_date.tm_wday*86400);
	for(int i = 0; i < 40; i++)
	{
		if(aux > weeklyAlarm[i])
		{
			WeeklyFlags |= (1 << (i));
		}
	}
	aux = (((uint32_t)rtc_date.tm_mday-1)*86400);
	for(int i = 0; i < 4; i++)
	{
		if(aux > monthlyAlarm[i])
		{
			MonthlyFlags |= (1 << (i));
		}
	}
}

void cancelAlarm(uint8_t AlarmNumber, uint8_t AlarmType)
{
	switch(AlarmType)
	{
		case 0:
			dailyAlarm[AlarmNumber-1] = -1;
			break;
		case 1:
			weeklyAlarm[AlarmNumber-1] = -1;
			break;
		case 2:
			monthlyAlarm[AlarmNumber-1] = -1;
			break;
		default:
		break;
	}
}

