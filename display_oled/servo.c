#include "servo.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include "buzzer.h"

void init_servo() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f);    // Divisor de clock
    pwm_config_set_wrap(&config, 19999);       // Período de 20ms (50 Hz)
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(SERVO_PIN, 400);
}

void set_servo_locked() {
    pwm_set_gpio_level(SERVO_PIN, SERVO_LOCKED_DUTY);
    play_buzzer_b(1500, 100);                         // Bip ao travar
    sleep_ms(100);
}

void set_servo_unlocked() {
    pwm_set_gpio_level(SERVO_PIN, SERVO_UNLOCKED_DUTY);
    play_buzzer_b(1500, 100);                           // Bip ao destravar
    sleep_ms(100);
}