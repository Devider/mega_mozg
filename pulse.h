#ifndef PULSE_H
#define PULSE_H

#include "config.h"

ulong pulseRead(int pin, int timeout);
void pulseWrite(int pinNumber, int pulseWidth);

#endif

