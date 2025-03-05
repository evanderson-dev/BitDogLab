#include "notes.h"
#include "buzzer.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// Toca uma nota com a frequência e duração especificadas
void play_tone(uint32_t pin, uint32_t frequency, uint32_t duration_ms) {
    if (frequency == 0) {
        sleep_ms(duration_ms);
        return;
    }
    uint slice_num = pwm_gpio_to_slice_num(pin);
    uint32_t clock_freq = clock_get_hz(clk_sys);
    uint32_t top = clock_freq / frequency - 1;
    pwm_set_wrap(slice_num, top);
    pwm_set_gpio_level(pin, top / 2); // 50% de duty cycle
    pwm_set_enabled(slice_num, true);
    sleep_ms(duration_ms);
    pwm_set_enabled(slice_num, false);
    sleep_ms(50); // Pausa entre notas
}