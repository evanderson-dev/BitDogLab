#include "servo.h"          // Inclui o arquivo de cabeçalho com definições do servo
#include "pico/stdlib.h"    // Inclui a biblioteca padrão do Pico SDK para funções como sleep_ms
#include "hardware/gpio.h"  // Inclui a biblioteca para configurar os pinos GPIO
#include "hardware/pwm.h"   // Inclui a biblioteca para controle de PWM (modulação por largura de pulso)
#include <stdio.h>          // Inclui a biblioteca para funções de entrada/saída como printf (opcional, para debug)
#include "buzzer.h"         // Inclui o cabeçalho do buzzer para tocar sons ao travar/destravar

// Inicializa o PWM no pino do servo motor
void init_servo() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); // Configura o GPIO17 como saída PWM
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN); // Obtém o número da "fatia" PWM associada ao GPIO17
    pwm_config config = pwm_get_default_config(); // Carrega a configuração padrão do PWM
    pwm_config_set_clkdiv(&config, 125.0f); // Define o divisor de clock como 125, resultando em uma base de 1 MHz (125 MHz / 125)
    // Nota: O wrap padrão é 65535, mas o período não está explicitamente definido aqui; assume-se 50 Hz ajustado em outro lugar ou pelo hardware
    pwm_init(slice_num, &config, true); // Inicializa o PWM com a configuração e habilita imediatamente
    pwm_set_gpio_level(SERVO_PIN, 400); // Define o duty cycle inicial como 400 (~0.4ms), posição "travada" ao inicializar
}

// Define o servo na posição "travada"
void set_servo_locked() {
    pwm_set_gpio_level(SERVO_PIN, SERVO_LOCKED_DUTY); // Ajusta o PWM para 400 (~0.4ms), girando anti-horário ou parando
    play_buzzer_b(1500, 100); // Toca um bip no buzzer B (GPIO10) com 1500 Hz por 100ms para indicar ação
    sleep_ms(100); // Aguarda 100ms para garantir que o servo complete o movimento e o som termine
}

// Define o servo na posição "destravada"
void set_servo_unlocked() {
    pwm_set_gpio_level(SERVO_PIN, SERVO_UNLOCKED_DUTY); // Ajusta o PWM para 2400 (~2.4ms), girando no sentido horário continuamente
    play_buzzer_b(1500, 100); // Toca um bip no buzzer B (GPIO10) com 1500 Hz por 100ms para indicar ação
    sleep_ms(100); // Aguarda 100ms para garantir que o servo complete o movimento e o som termine
}