#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF


#define _SUPPRESS_PLIB_WARNING 1
#include <xc.h>
#include <inttypes.h>
#include <plib.h>
#include "alarm_intf_p.h";

// Initialize the alarm interfaces
void initAlarm(){
    ANSELB = 0;  //Dig pins
    PORTSetPinsDigitalIn(IOPORT_B,BIT_4);
    PORTSetPinsDigitalOut(IOPORT_B,BIT_15);
    PORTSetPinsDigitalOut(IOPORT_B,BIT_14);
//door sensor 11 RB4
//LED 26 RB15
// buzzer 25 RB14
}
uint8_t readDoor(){
    return PORTRead(IOPORT_B,BIT_4);
}
void ledOff(){
    PORTWrite(IOPORT_B,BIT_15) = 0 ;
}
void ledOn(){
    PORTWrite(IOPORT_B,BIT_15) = 1;
}
void alarmOff(){
    PORTWrite(IOPORT_B,BIT_14) = 0 ;
}
void alarmOn(){
   PORTWrite(IOPORT_B,BIT_14) = 1 ;
}









