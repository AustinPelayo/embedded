#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>



// Initialize the alarm interfaces
void initAlarm(){
    ANSELB = 0;  //Dig pins
    
    TRISBbits.TRISB4 = 1; //i/o
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
//door sensor 11 RB4
//LED 26 RB15
// buzzer 25 RB14
}
uint8_t readDoor(){
     
            return PORTBbits.RB4;    
}
void ledOff(){
    LATBbits.LATB15 = 0;
}
void ledOn(){
    LATBbits.LATB15 = 1;
}
void alarmOff(){
    LATBbits.LATB14 = 0;
}
void alarmOn(){
    LATBbits.LATB14 = 1;
}

/*
uint8_t readDoor();
// turn warning LED OFF
void ledOff();
// turn warning LED ON
void ledOn();
// turn alarm buzzer OFF
void alarmOff();
// turn alarm buzzer ON
void alarmOn();
*/