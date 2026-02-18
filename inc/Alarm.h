#ifndef ALARM_API_H
#define ALARM_API_H

#include <stdint.h>

extern uint16_t persist_ DailyFlags;
extern uint16_t persist_ WeeklyFlags;
extern uint16_t persist_ MonthlyFlags;
extern uint32_t persistArray_ dailyAlarm[16];
extern uint32_t persistArray_ weeklyAlarm[40];
extern uint32_t persistArray_ monthlyAlarm[4];

void setDailyAlarm(uint8_t AlarmNumber,char* AlarmTime);
void setWeeklyAlarm(uint8_t AlarmNumber,uint8_t DayOfWeek,char* AlarmTime);
void setMonthlyAlarm(uint8_t AlarmNumber,uint8_t DayOfMonth,char* AlarmTime);
void cancelAlarm(uint8_t AlarmNumber, uint8_t AlarmType);

void initAlarms(void);

void pollAlarms(void);

#endif

