#ifndef BUTTONS_H
#define BUTTONS_H

#include "pico/stdlib.h"

// Definição dos pinos usados para os botões
extern const int BUTTON_A_PIN;
extern const int BUTTON_B_PIN;

// Funções para configurar e ler os botões
void setup_buttons(void);
bool is_button_a_pressed(void);
bool is_button_b_pressed(void);

#endif