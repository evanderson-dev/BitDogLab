#include "buzzer.h"
#include "notes.h"
#include "hardware/pwm.h"

// Definição dos pinos usados para os buzzers
const int BUZZER_A_PIN = 21;
const int BUZZER_B_PIN = 10;

// Inicializa o PWM no pino do buzzer
void pwm_init_buzzer(uint32_t pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(pin, 0);
}

void setup_buzzers(void) {
    pwm_init_buzzer(BUZZER_A_PIN);
    pwm_init_buzzer(BUZZER_B_PIN);
}

void play_buzzer(uint gpio, uint32_t frequency, uint32_t duration) {
    if (frequency == 0) {
        sleep_ms(duration);
        return;
    }
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint32_t clock = 125000000;
    uint32_t divider = clock / frequency;
    pwm_set_clkdiv(slice_num, 1.0f);
    pwm_set_wrap(slice_num, divider);
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), divider / 2);
    pwm_set_enabled(slice_num, true);
    sleep_ms(duration);
    pwm_set_enabled(slice_num, false);
}

void play_buzzer_a(uint32_t frequency, uint32_t duration) {
    play_tone(BUZZER_A_PIN, frequency, duration);
}

void play_buzzer_b(uint32_t frequency, uint32_t duration) {
    play_tone(BUZZER_B_PIN, frequency, duration);
}

void play_mario(uint32_t pin) {
    const uint32_t mario_melody[] = {
        MI_Oitava_7, MI_Oitava_7, 0, MI_Oitava_7,           // Mi7 Mi7 - Mi7
        0, DO_Oitava_7, MI_Oitava_7, 0,                     // - Dó7 Mi7 -
        SOL_Oitava_7, 0, 0, 0,                              // Sol7 - - -
        SOL_Oitava_6, 0, 0, 0,                              // Sol6 - - -

        DO_Oitava_7, 0, 0, SOL_Oitava_6,                    // Dó7 - - Sol6
        0, 0, MI_Oitava_6, 0,                               // - - Mi6 -
        0, LA_Oitava_6, 0, SI_Oitava_6,                     // - Lá6 - Si6
        0, LA_S_Oitava_6, LA_Oitava_6, 0,                   // - Lá#6 Lá6 -

        SOL_Oitava_6, MI_Oitava_7, SOL_Oitava_7,            // Sol6 Mi7 Sol7
        LA_Oitava_7, 0, FA_Oitava_7, SOL_Oitava_7,          // Lá7 - Fá7 Sol7
        0, MI_Oitava_7, 0, DO_Oitava_7,                     // - Mi7 - Dó7
        RE_Oitava_7, SI_Oitava_6, 0, 0,                     // Ré7 Si6 - -

        DO_Oitava_7, 0, 0, SOL_Oitava_6,                    // Dó7 - - Sol6
        0, 0, MI_Oitava_6, 0,                               // - - Mi6 -
        0, LA_Oitava_6, 0, SI_Oitava_6,                     // - Lá6 - Si6
        0, LA_S_Oitava_6, LA_Oitava_6, 0,                   // - Lá#6 Lá6 -

        SOL_Oitava_6, MI_Oitava_7, SOL_Oitava_7,            // Sol6 Mi7 Sol7
        LA_Oitava_7, 0, FA_Oitava_7, SOL_Oitava_7,          // Lá7 - Fá7 Sol7
        0, MI_Oitava_7, 0, DO_Oitava_7,                     // - Mi7 - Dó7
        RE_Oitava_7, SI_Oitava_6, 0, 0                      // Ré7 Si6 - -
    };

    const uint32_t mario_durations[] = {
        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,

        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,

        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,

        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,

        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125,
        125, 125, 125, 125
    };

    int note_count = sizeof(mario_melody) / sizeof(mario_melody[0]);
    for (int i = 0; i < note_count; i++) {
        play_tone(pin, mario_melody[i], mario_durations[i]);
    }
}