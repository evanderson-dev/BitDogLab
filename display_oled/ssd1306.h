#ifndef SSD1306_H
#define SSD1306_H

#include "hardware/i2c.h"

#define SSD1306_I2C_ADDR 0x3C  // Endereço I2C padrão do SSD1306
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

void ssd1306_init(i2c_inst_t *i2c, uint sda_pin, uint scl_pin);
void ssd1306_clear(void);
void ssd1306_draw_char(uint8_t x, uint8_t y, char c);
void ssd1306_draw_string(uint8_t x, uint8_t y, const char *str);
void ssd1306_update(void);

#endif