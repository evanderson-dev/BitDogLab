#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

// Definição dos pinos usados para o joystick
extern const int VRX;
extern const int VRY;
extern const int SW;

// Funções para configurar e ler o joystick
void setup_joystick(void);
void setup(void);
void joystick_read_axis(uint16_t *vrx_value, uint16_t *vry_value);

#endif