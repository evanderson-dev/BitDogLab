#include "ssd1306.h" // Biblioteca para controle do display SSD1306
#include "menu.h"    // Cabeçalho do menu com a declaração da função draw_menu
#include <stdio.h>   // Biblioteca padrão C para funções como snprintf (formatação de strings)

// Lista de itens do menu (sem o "<" ou número, que serão adicionados dinamicamente)
static const char *menu_items[] = {
    "MARIO BROS",
    "TOP GEAR",
    "SONIC",
    "DOOM",
    "CASTLEVANIA"
};

// Número total de itens no menu (calculado automaticamente)
#define MENU_ITEM_COUNT (sizeof(menu_items) / sizeof(menu_items[0]))

// Função para desenhar o menu no display
// Param: selected_item - índice do item selecionado (1 a 5)
void draw_menu(int selected_item) {
    // Desenha o título do menu na linha 0, com offset de 6 pixels para centralizar
    ssd1306_draw_string(6, 0, "HBR-MUSIC PLAYER");

    // Itera sobre os itens do menu para desenhá-los nas linhas 2 a 6
    for (int i = 0; i < MENU_ITEM_COUNT; i++) {
        int row = i + 2; // Linhas começam em 2 (após o título)
        int col = 6;     // Coluna padrão (sem destaque)

        // Se o item atual for o selecionado, adiciona "<" e move para a coluna 0
        if (i == selected_item - 1) {
            col = 0; // Move para a esquerda para destacar
            char buffer[16]; // Buffer para construir a string com "<" e número
            snprintf(buffer, sizeof(buffer), "<%d-%s", i + 1, menu_items[i]);
            ssd1306_draw_string(col, row, buffer);
        } else {
            // Item não selecionado: apenas número e texto, sem "<"
            char buffer[16]; // Buffer para construir a string com número
            snprintf(buffer, sizeof(buffer), "%d-%s", i + 1, menu_items[i]);
            ssd1306_draw_string(col, row, buffer);
        }
    }
}