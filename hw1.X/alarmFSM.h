
#ifndef _ALARMFSM_H    /* Guard against multiple inclusion */
#define _ALARMFSM_H
#include <inttypes.h>
#include "main.h"
#include "alarm_intf.h"
#include "warnFSM.h"
#include "alarm_intf_p.h"
#include <stdlib.h>
#endif

extern void alarmTick();

extern uint8_t warn;
extern uint32_t time;