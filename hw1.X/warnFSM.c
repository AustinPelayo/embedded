#include <inttypes.h>
#include "main.h"
#include "alarm_intf.h"
#include "warnFSM.h"
#include "alarm_intf.h"
#include <stdlib.h>

static uint8_t warn;

void tick() {

    static enum warn_STATES {
        warn_WRNOFF, warn_WRNON
    }
    warn_STATES = warn_WRNOFF;

    switch (warn_STATES) {

        case warn_WRNOFF:
            ledOff();

            if (!warn) warn_STATES = warn_WRNON;
            else {
                warn_STATES = warn_WRNOFF;
            }
            break;

        case warn_WRNON:
            ledOn();
            warn_STATES = warn_WRNOFF;
            break;
    }
}

uint8_t returnWarn() {
    return warn;
}

void setWarn(uint8_t warns) {
    warn = warns;
}