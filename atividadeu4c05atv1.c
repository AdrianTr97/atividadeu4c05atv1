#include <stdio.h>
#include "pico/stdlib.h"   // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

// Definição dos GPIOs/pinos dos LEDs
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

// Enumeração para facilitar o controle do semáforo
typedef enum {
    RED, YELLOW, GREEN
} traffic_light_state;

traffic_light_state current_state = RED; // Começa com o sinal vermelho

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {   
    // Mudança de estado do semáforo a cada 3 segundos
    switch (current_state) {
        case RED:
            gpio_put(LED_PIN_RED, 1);
            gpio_put(LED_PIN_YELLOW, 0);
            gpio_put(LED_PIN_GREEN, 0);
            current_state = YELLOW;
            printf("Semáforo: Vermelho\n");
            break;
        case YELLOW:
            gpio_put(LED_PIN_RED, 0);
            gpio_put(LED_PIN_YELLOW, 1);
            gpio_put(LED_PIN_GREEN, 0);
            current_state = GREEN;
            printf("Semáforo: Amarelo\n");
            break;
        case GREEN:
            gpio_put(LED_PIN_RED, 0);
            gpio_put(LED_PIN_YELLOW, 0);
            gpio_put(LED_PIN_GREEN, 1);
            current_state = RED;
            printf("Semáforo: Verde\n");
            break;
    }
    // Retorna true para manter o temporizador repetindo.
    return true;
}

int main() {
    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Adiciona um pequeno delay para garantir que a comunicação serial tenha tempo de ser configurada.
    sleep_ms(500); // Pausa de 500ms

    // Inicializar os pinos GPIO dos LEDs
    //gpio_init(LED_PIN_RED);
    //gpio_set_dir(LED_PIN_RED, true);
    //gpio_init(LED_PIN_YELLOW);
    //gpio_set_dir(LED_PIN_YELLOW, true);
    //gpio_init(LED_PIN_GREEN);
    //gpio_set_dir(LED_PIN_GREEN, true);
    
    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    // Inicializa o semáforo com o LED vermelho aceso
    //gpio_put(LED_PIN_RED, 1);
    //gpio_put(LED_PIN_YELLOW, 0);
    //gpio_put(LED_PIN_GREEN, 0);

    // Declaração de uma estrutura de temporizador de repetição.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos (3000ms).
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução.
    while (true) {
        // Pausa de 1 segundo para imprimir a mensagem.
        sleep_ms(1000);

        // Imprime a mensagem "Passou 1 segundo" a cada 1 segundo.
        printf("rotina de repetição\n");

        // Imprime o estado atual do semáforo.
        //if (current_state == RED) {
        //    printf("Estado atual: Vermelho\n");
        //} else if (current_state == YELLOW) {
        //    printf("Estado atual: Amarelo\n");
        //} else if (current_state == GREEN) {
        //    printf("Estado atual: Verde\n");
        //}
    }

    return 0;
}