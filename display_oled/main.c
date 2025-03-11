#include <stdio.h>
#include "pico/stdlib.h"
#include "ssd1306.h"
#include "joystick.h"
#include "menu.h"
#include "buzzer.h"
#include "buttons.h"
#include "notes.h"
#include "servo.h"

int main() {
    stdio_init_all();
    ssd1306_init(i2c1, 14, 15);
    ssd1306_clear();
    setup_joystick(); // Configura o joystick
    setup_buzzers(); // Configura os buzzers
    setup_buttons(); // Configura os botões
    init_servo(); // Inicializa o servo motor

    uint16_t vrx_value, vry_value;
    int current_menu = 1;

    while (true) {
        joystick_read_axis(&vrx_value, &vry_value);

        // Lógica para alternar entre os menus usando apenas as direções para cima e para baixo
        if (vrx_value < 1000) {
            current_menu++;
            if (current_menu > 5) {
                current_menu = 1;
            }
            play_buzzer_a(2000, 100); // Toca o buzzer A ao mover para baixo
        } else if (vrx_value > 3000) {
            current_menu--;
            if (current_menu < 1) {
                current_menu = 5;
            }
            play_buzzer_b(2000, 100); // Toca o buzzer B ao mover para cima
        }

        // Lógica para os botões
        if (is_button_a_pressed()) {
            play_buzzer_a(2000, 100);
            pwm_set_gpio_level(SERVO_PIN, SERVO_LOCKED_DUTY); // 1ms (~0°)
        }

        if (is_button_b_pressed()) {
            play_buzzer_b(2000, 50);
            pwm_set_gpio_level(SERVO_PIN, SERVO_UNLOCKED_DUTY); // 2ms (~180°)
        }

        ssd1306_clear();
        switch (current_menu) {
            case 1: menu_one(); break;
            case 2: menu_two(); break;
            case 3: menu_three(); break;
            case 4: menu_four(); break;
            case 5: menu_five(); break;
        }
        ssd1306_update();
        sleep_ms(200); // Aumenta o delay para evitar múltiplas mudanças rápidas
    }
}