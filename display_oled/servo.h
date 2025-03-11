#ifndef SERVO_H
#define SERVO_H

// Definições para o servo motor
#define SERVO_PIN 17             // Pino GPIO17 (pino físico 22) conectado ao sinal PWM do servo motor
#define SERVO_LOCKED_DUTY 400    // Valor do duty cycle (~0.4ms) para a posição "travada"
#define SERVO_UNLOCKED_DUTY 2400 // Valor do duty cycle (~2.4ms) para a posição "destravada"

// Declarações das funções do servo
void init_servo();        // Inicializa o PWM no pino do servo motor
void set_servo_locked();  // Define o servo na posição "travada"
void set_servo_unlocked(); // Define o servo na posição "destravada"

#endif