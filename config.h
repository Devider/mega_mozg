#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define SIZE 6
#define TIME_OUT 40000

#define ALT_ECHO_PIN 15
#define ALT_TRIG_PIN 14

#define TARGET_ALT_MM 500

#define NEUTRAL_SIGNAL 1500
#define MIN_SIGNAL 1010
#define MAX_SIGNAL 1990

#define ROLL_ITEM 0
#define PITCH_ITEM 1
#define THROTTLE_ITEM 2
#define YAW_ITEM 3
#define MODE_SWITCH_ITEM 5

#define MANUAL_THRESHOLD 1170
#define ARMING_THRESHOLD 1500
#define HALF_AUTO_MODE_THRESHOLD 1800



typedef unsigned long ulong;
typedef unsigned int uint;




#endif

