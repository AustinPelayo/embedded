#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include "alarmFSM.h"
#include "alarm_intf.h"
#include "main.h"
#include "ztimer.h"
extern uint16_t time;
int16_t ta1, ta2;

void main()
{
     zTimerOn();
     ta1 = zTimerReadms(); 

    while(1){
        time = zTimerReadms();
        alarmTick();
        tick();
    }

}