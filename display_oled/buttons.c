#include "buttons.h"

// Definição dos pinos usados para os botões
const int BUTTON_A_PIN = 5;
const int BUTTON_B_PIN = 6;

void setup_buttons(void) {
    // Configura os pinos dos botões como entrada com pull-up
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);
}

bool is_button_a_pressed(void) {
    // Retorna verdadeiro se o botão A estiver pressionado
    return !gpio_get(BUTTON_A_PIN);
}

bool is_button_b_pressed(void) {
    // Retorna verdadeiro se o botão B estiver pressionado
    return !gpio_get(BUTTON_B_PIN);
}