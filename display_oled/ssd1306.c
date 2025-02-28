#include "ssd1306.h"
#include "pico/stdlib.h"
#include <string.h>

// Comandos básicos do SSD1306
static const uint8_t SSD1306_INIT_COMMANDS[] = {
    0xAE,        // Display OFF
    0xD5, 0x80,  // Clock divide ratio
    0xA8, 0x3F,  // Multiplex ratio (64 pixels)
    0xD3, 0x00,  // Display offset
    0x40,        // Start line
    0x8D, 0x14,  // Charge pump
    0x20, 0x00,  // Memory addressing mode (horizontal)
    0xA1,        // Segment remap
    0xC8,        // COM output scan direction
    0xDA, 0x12,  // COM pins configuration
    0x81, 0xCF,  // Contrast control
    0xD9, 0xF1,  // Pre-charge period
    0xDB, 0x40,  // VCOMH deselect level
    0xA4,        // Entire display ON
    0xA6,        // Normal display (não invertido)
    0xAF         // Display ON
};

// Buffer para a tela (128x64 pixels / 8 bits por byte = 1024 bytes)
static uint8_t display_buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

// Fonte simples 5x7 (apenas exemplo para A-Z, adaptado do ASCII básico)
static const uint8_t font_5x7[][5] = {
    // A: Largura cheia com topo pontiagudo
    {0x7E, 0x09, 0x09, 0x09, 0x7E}, // 01111110, 00001001, 00001001, 00001001, 01111110
    // B: Curva à esquerda, linha horizontal no meio
    {0x7F, 0x49, 0x49, 0x49, 0x36}, // 01111111, 01001001, 01001001, 01001001, 00110110
    // C: Arco aberto à direita
    {0x3E, 0x41, 0x41, 0x41, 0x22}, // 00111110, 01000001, 01000001, 01000001, 00100010
    // D: Curva à direita com linha vertical à esquerda
    {0x7F, 0x41, 0x41, 0x41, 0x3E}, // 01111111, 01000001, 01000001, 01000001, 00111110
    // E: Três linhas horizontais
    {0x7F, 0x49, 0x49, 0x49, 0x41}, // 01111111, 01001001, 01001001, 01001001, 01000001
    // F: Duas linhas horizontais no topo
    {0x7F, 0x09, 0x09, 0x09, 0x01}, // 01111111, 00001001, 00001001, 00001001, 00000001
    // G: Arco com linha horizontal
    {0x3E, 0x41, 0x41, 0x49, 0x7A}, // 00111110, 01000001, 01000001, 01001001, 01111010
    // H: Duas verticais com linha horizontal no meio
    {0x7F, 0x08, 0x08, 0x08, 0x7F}, // 01111111, 00001000, 00001000, 00001000, 01111111
    // I: Linha vertical no centro
    {0x41, 0x41, 0x7F, 0x41, 0x41}, // 01000001, 01000001, 01111111, 01000001, 01000001
    // J: Gancho à esquerda
    {0x20, 0x40, 0x41, 0x41, 0x3F}, // 00100000, 01000000, 01000001, 01000001, 00111111
    // K: Diagonal com linha vertical à esquerda
    {0x7F, 0x08, 0x14, 0x22, 0x41}, // 01111111, 00001000, 00010100, 00100010, 01000001
    // L: Linha vertical com base horizontal
    {0x7F, 0x40, 0x40, 0x40, 0x40}, // 01111111, 01000000, 01000000, 01000000, 01000000
    // M: Duas verticais com pico no meio
    {0x7F, 0x02, 0x04, 0x02, 0x7F}, // 01111111, 00000010, 00000100, 00000010, 01111111
    // N: Duas verticais com diagonal
    {0x7F, 0x04, 0x08, 0x10, 0x7F}, // 01111111, 00000100, 00001000, 00010000, 01111111
    // O: Círculo aberto
    {0x3E, 0x41, 0x41, 0x41, 0x3E}, // 00111110, 01000001, 01000001, 01000001, 00111110
    // P: Curva superior à direita
    {0x7F, 0x09, 0x09, 0x09, 0x06}, // 01111111, 00001001, 00001001, 00001001, 00000110
    // Q: Círculo com cauda diagonal
    {0x3E, 0x41, 0x51, 0x21, 0x5E}, // 00111110, 01000001, 01010001, 00100001, 01011110
    // R: Curva superior com diagonal inferior
    {0x7F, 0x09, 0x19, 0x29, 0x46}, // 01111111, 00001001, 00011001, 00101001, 01000110
    // S: Curva em S
    {0x46, 0x49, 0x49, 0x49, 0x31}, // 01000110, 01001001, 01001001, 01001001, 00110001
    // T: Linha horizontal no topo com vertical no centro
    {0x01, 0x01, 0x7F, 0x01, 0x01}, // 00000001, 00000001, 01111111, 00000001, 00000001
    // U: U aberto
    {0x3F, 0x40, 0x40, 0x40, 0x3F}, // 00111111, 01000000, 01000000, 01000000, 00111111
    // V: V aberto
    {0x1F, 0x20, 0x40, 0x20, 0x1F}, // 00011111, 00100000, 01000000, 00100000, 00011111
    // W: Duas Vs unidas
    {0x7F, 0x20, 0x18, 0x20, 0x7F}, // 01111111, 00100000, 00011000, 00100000, 01111111
    // X: Cruzado
    {0x63, 0x14, 0x08, 0x14, 0x63}, // 01100011, 00010100, 00001000, 00010100, 01100011
    // Y: Y com base vertical
    {0x07, 0x08, 0x70, 0x08, 0x07}, // 00000111, 00001000, 01110000, 00001000, 00000111
    // Z: Z diagonal
    {0x61, 0x51, 0x49, 0x45, 0x43}, // 01100001, 01010001, 01001001, 01000101, 01000011
    // Espaço
    {0x00, 0x00, 0x00, 0x00, 0x00}  // 00000000, 00000000, 00000000, 00000000, 00000000
};

static i2c_inst_t *i2c_instance;

void ssd1306_write_cmd(uint8_t cmd) {
    uint8_t buf[2] = {0x00, cmd}; // Control byte 0x00 para comandos
    i2c_write_blocking(i2c_instance, SSD1306_I2C_ADDR, buf, 2, false);
}

void ssd1306_write_data(uint8_t *data, size_t len) {
    uint8_t buf[1025]; // Máximo de 1024 bytes + control byte
    buf[0] = 0x40;     // Control byte 0x40 para dados
    memcpy(buf + 1, data, len);
    i2c_write_blocking(i2c_instance, SSD1306_I2C_ADDR, buf, len + 1, false);
}

void ssd1306_init(i2c_inst_t *i2c, uint sda_pin, uint scl_pin) {
    i2c_instance = i2c;
    i2c_init(i2c, 400000); // 400 kHz
    gpio_set_function(sda_pin, GPIO_FUNC_I2C);
    gpio_set_function(scl_pin, GPIO_FUNC_I2C);
    gpio_pull_up(sda_pin);
    gpio_pull_up(scl_pin);

    // Inicialização do display
    for (size_t i = 0; i < sizeof(SSD1306_INIT_COMMANDS); i++) {
        ssd1306_write_cmd(SSD1306_INIT_COMMANDS[i]);
    }
    ssd1306_clear();
    ssd1306_update();
}

void ssd1306_clear(void) {
    memset(display_buffer, 0, sizeof(display_buffer));
}

void ssd1306_draw_char(uint8_t x, uint8_t y, char c) {
    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT / 8) return;
    // Mapeia caracteres A-Z e espaço
    uint8_t char_idx;
    if (c >= 'A' && c <= 'Z') {
        char_idx = c - 'A'; // A=0, B=1, ..., Z=25
    } else if (c == ' ') {
        char_idx = 26; // Espaço
    } else {
        return; // Ignora outros caracteres por enquanto
    }
    for (uint8_t i = 0; i < 5; i++) {
        if (x + i < SSD1306_WIDTH) {
            display_buffer[y * SSD1306_WIDTH + x + i] = font_5x7[char_idx][i];
        }
    }
}

void ssd1306_draw_string(uint8_t x, uint8_t y, const char *str) {
    while (*str) {
        ssd1306_draw_char(x, y, *str++);
        x += 6; // Largura do caractere (5) + 1 de espaço
        if (x >= SSD1306_WIDTH) break;
    }
}

void ssd1306_update(void) {
    ssd1306_write_cmd(0x21); // Coluna inicial
    ssd1306_write_cmd(0);
    ssd1306_write_cmd(127);
    ssd1306_write_cmd(0x22); // Página inicial
    ssd1306_write_cmd(0);
    ssd1306_write_cmd(7);
    ssd1306_write_data(display_buffer, sizeof(display_buffer));
}