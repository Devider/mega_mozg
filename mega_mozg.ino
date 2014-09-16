#include "pulse.h"
#include "navigator.h"
#include "config.h"
int ch_in [SIZE] = {2, 3,  4,  5,  6,  7};
int ch_out[SIZE] = {8, 9, 10, 11, 12, 13};
int ch_data[SIZE];

ulong val;

ulong pulseRead(int, int);
void pulseWrite(int, int);


void setup(){
  Serial.begin(9600);
  Serial3.begin(9600);

  for (int i = 0; i < SIZE; i++){
    pinMode(ch_in[i], INPUT);
    pinMode(ch_out[i], OUTPUT);
  }
}

void loop(){
    cli();
    for (int i = 0; i < SIZE; i++){
      ch_data[i] = pulseIn(ch_in[i], HIGH);
    }
    sei();
    if (inHalfAutoMode(ch_data)){
      modifyAltitude(ch_data);
    } else     if (isArming(ch_data)){
      doArm(ch_data);
    } else if (isDisarming(ch_data)){
      doDisarm(ch_data);
    } else {
      
    }
    for (int i = 0; i < SIZE; i++){
      pulseWrite(ch_out[i], ch_data[i]);
    }
}



