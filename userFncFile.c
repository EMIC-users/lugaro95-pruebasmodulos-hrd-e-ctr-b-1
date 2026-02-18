#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_Led1.h"
#include "inc/led_Led2.h"
#include "inc/led_Led3.h"
#include "inc/timer_api1.h"
#include "inc/Transport.h"
#include "inc/EmicFieldBus.h"
#include "inc/EMICBus.h"

void onReset()
{
    LEDs_Led1_blink(125, 250, 3);
    LEDs_Led2_blink(125, 250, 3);
    LEDs_Led3_blink(125, 250, 3);
}


void emicFBe(char* TAG, const streamIn_t* const Message)
{
    pI2C("$s\t$r", TAG, Message);
    LEDs_Led1_blink(125, 250, 1);
}


void eI2C(char* tag, const streamIn_t* const msg)
{
    emicFBp("$s\t$r", tag, msg);
    LEDs_Led2_blink(125, 250, 1);
}



