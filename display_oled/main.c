#include <stdio.h>
#include "pico/stdlib.h"
#include "ssd1306.h"

int main() {
    stdio_init_all();

    // Inicializa o I2C1 com GPIO14 (SDA) e GPIO15 (SCL)
    ssd1306_init(i2c1, 14, 15);

    // Limpa o display
    ssd1306_clear();

    // Exibe texto simples
    ssd1306_draw_string(0, 0, "OLA MUNDO");
    ssd1306_draw_string(0, 1, "RASPBERRY PI");
    ssd1306_draw_string(0, 2, "PICO");

    // Atualiza o display
    ssd1306_update();

    // Loop infinito
    while (true) {
        sleep_ms(1000);
    }
}