#include "config.h"
#include "pulse.h"

ulong time = 0; 
ulong alt = 0;  
int altDelta = 0;
int high, low, a;



void doArm(int* data){
  *(data + ROLL_ITEM) = 0;
  *(data + PITCH_ITEM) = 0;
  *(data + THROTTLE_ITEM) = MIN_SIGNAL;
  *(data + YAW_ITEM) = MAX_SIGNAL;
  *(data + MODE_SWITCH_ITEM) = 0;
}

void doDisarm(int* data){
  *(data + ROLL_ITEM) = 0;
  *(data + PITCH_ITEM) = 0;
  *(data + THROTTLE_ITEM) = MIN_SIGNAL;
  *(data + YAW_ITEM) = MIN_SIGNAL;
  *(data + MODE_SWITCH_ITEM) = 0;
}

boolean isArming(int* data){
  return (*(data + MODE_SWITCH_ITEM) > MANUAL_THRESHOLD) && (*(data + MODE_SWITCH_ITEM) < ARMING_THRESHOLD);
}

boolean inHalfAutoMode(int* data){
  return (*(data + MODE_SWITCH_ITEM) > ARMING_THRESHOLD) && (*(data + MODE_SWITCH_ITEM) < HALF_AUTO_MODE_THRESHOLD);
}

boolean isDisarming(int* data){
  return (*(data + MODE_SWITCH_ITEM) > HALF_AUTO_MODE_THRESHOLD);
}

uint getCurrentAltitude(){
  Serial3.flush();  
  Serial3.write(0X55);                           
  delayMicroseconds(50);                                  
  if(Serial3.available() >= 2)                
  {
      high = Serial3.read();               
      low  = Serial3.read();               
      a  = high * 256 + low;         
      if((a > 1) && (a < 10000)){
         return a;
      }
  }
  return -1;
}

void modifyAltitude(int* data){
  alt = getCurrentAltitude();

/*  if ((alt < TARGET_ALT_MM) && (NEUTRAL_SIGNAL + altDelta <= MAX_SIGNAL)){
#ifndef RELEASE
    Serial.print(alt, DEC);
    Serial.print("    Higher! Delta now:");
    Serial.print(altDelta, DEC);
    Serial.print(" and throttler is ");
    Serial.println(NEUTRAL_SIGNAL + altDelta, DEC);
#endif
    altDelta += 10;
  } else if ((alt > TARGET_ALT_MM) && (NEUTRAL_SIGNAL + altDelta >= MIN_SIGNAL)) {
    Serial.print(alt, DEC);
    Serial.print("    Lower! Delta now:");
    Serial.println(altDelta, DEC);
    Serial.print(" and throttler is ");
    Serial.println(NEUTRAL_SIGNAL + altDelta, DEC);
    altDelta -= 3;
  }*/
    altDelta = (alt - TARGET_ALT_MM) / 10;
#ifndef RELEASE
    Serial.print(alt, DEC);
    if (altDelta > 0){
      Serial.print("    Higher! Delta now:");
    } else {
      Serial.print("    Lower! Delta now:");
    }
    Serial.println(altDelta, DEC);
    Serial.print(" and throttler is ");
    Serial.println(NEUTRAL_SIGNAL + altDelta, DEC);
#endif
  
  *(data + THROTTLE_ITEM) = NEUTRAL_SIGNAL + altDelta;
}



