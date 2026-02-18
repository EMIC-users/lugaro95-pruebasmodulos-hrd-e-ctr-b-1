#ifndef RTC_API_H
#define RTC_API_H

#include <stdint.h>
#include "time.h"

extern uint8_t rtc_firstTime;

void setTime(char* strTime);
char* getTime(void);

void RTCC_Init(void);

#endif

