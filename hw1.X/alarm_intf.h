//#ifdef ALARM_INTF_H
#define ALARM__INTF_H
//#include <inttypes.h>
// Initialize the alarm interfaces
extern void initAlarm();
extern uint8_t readDoor();
// turn warning LED OFF
extern void ledOff();
// turn warning LED ON
extern void ledOn();
// turn alarm buzzer OFF
extern void alarmOff();
// turn alarm buzzer ON
extern void alarmOn();
//#endif