#ifndef SERVO_H
#define SERVO_H

#include "pico/stdlib.h"

#define SERVO_PIN 17
#define SERVO_LOCKED_DUTY 400
#define SERVO_UNLOCKED_DUTY 2400

void init_servo();
void set_servo_locked();
void set_servo_unlocked();

#endif