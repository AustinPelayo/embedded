#ifdef ALARM_INTF_H
#define ALARM__INTF_H
#include <inttypes.h>
// Initialize the alarm interfaces
void initAlarm();
uint8_t readDoor();
// turn warning LED OFF
void ledOff();
// turn warning LED ON
void ledOn();
// turn alarm buzzer OFF
void alarmOff();
// turn alarm buzzer ON
void alarmOn();
#endif