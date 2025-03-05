#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"
#include <stdint.h>

// Definição dos pinos usados para os buzzers
extern const int BUZZER_A_PIN;
extern const int BUZZER_B_PIN;

// Funções para configurar e controlar os buzzers
void setup_buzzers(void);
void pwm_init_buzzer(uint32_t pin);
void play_buzzer_a(uint32_t frequency, uint32_t duration);
void play_buzzer_b(uint32_t frequency, uint32_t duration);
void play_mario(uint32_t pin);
void play_mario_accompaniment(uint32_t pin);

#endif