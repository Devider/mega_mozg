#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include "config.h"

void doArm(int* data);

void doDisarm(int* data);

boolean isArming(int* data);

boolean isDisarming(int* data);

boolean inHalfAutoMode(int* data);

void modifyAltitude(int* data);

#endif NAVIGATOR_H

