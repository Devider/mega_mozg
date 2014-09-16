#include <avr/io.h>
#include <util/delay.h>

#include "config.h"
#include "pulse.h"

void pulseWrite(int pinNumber, int const pulseWidth) {
  if (pulseWidth > 0) {
    ulong wait_ms = pulseWidth - 20;
    digitalWrite(pinNumber, HIGH);
    delayMicroseconds(wait_ms);
    digitalWrite(pinNumber, LOW);
  }
}

