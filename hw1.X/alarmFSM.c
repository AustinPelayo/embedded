#include <inttypes.h>
#include "main.h"
#include "alarm_intf.h"
#include "warnFSM.h"
#include "alarm_intf.h"
#include <stdlib.h>

extern uint8_t warn;
extern uint32_t time;

void alarmTick() {

    static enum alarm_STATES {
        alarm_INIT, alarm_ON, alarm_OFF, alarm_BUZZER
    }
    alarm_STATES = alarm_INIT;

    switch (alarm_STATES) {

        case alarm_INIT:
            initAlarm();
            if(readDoor() == 1) 
            {
            alarm_STATES = alarm_ON;
            }
            else{
            alarm_STATES = alarm_OFF;
            }
            break;

        case alarm_ON:
            //do stuff 
           alarmOn();
           warn = 1; 
           ledOn();
           //tick();
           if(readDoor() == 0)
           {
           alarm_STATES = alarm_OFF;
           }
           else if (time = 30000) //in MS
           {
           alarm_STATES = alarm_BUZZER;
           }
           else 
           {
           alarm_STATES = alarm_ON;
           }
            break;
            
        case alarm_OFF:
            warn = 0;
            ledOff();
            alarmOff();
            //do stuff 
            if(readDoor() == 0)
            alarm_STATES = alarm_OFF;
            else
            {
                alarm_STATES = alarm_ON;
            }
            break;
            
        case alarm_BUZZER:
            alarmOn();
            //do stuff 
            if(readDoor() == 0)
            {
            alarm_STATES = alarm_OFF;
            } else 
            {
            alarm_STATES = alarm_BUZZER;
            
            }
            break;

    }

}






