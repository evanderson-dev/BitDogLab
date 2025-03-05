#include "ssd1306.h"
#include "menu.h"

void menu_one(void) {
    ssd1306_draw_string(6, 0, "HBR-MUSIC PLAYER");
    ssd1306_draw_string(0, 2, "<1-MARIO BROS");
    ssd1306_draw_string(6, 3, "2-TOP GEAR");
    ssd1306_draw_string(6, 4, "3-SONIC");
    ssd1306_draw_string(6, 5, "4-DOOM");
    ssd1306_draw_string(6, 6, "5-CASTLEVANIA");
}

void menu_two(void) {
    ssd1306_draw_string(6, 0, "HBR-MUSIC PLAYER");
    ssd1306_draw_string(6, 2, "1-MARIO BROS");
    ssd1306_draw_string(0, 3, "<2-TOP GEAR");
    ssd1306_draw_string(6, 4, "3-SONIC");
    ssd1306_draw_string(6, 5, "4-DOOM");
    ssd1306_draw_string(6, 6, "5-CASTLEVANIA"); 
}

void menu_three(void) {
    ssd1306_draw_string(6, 0, "HBR-MUSIC PLAYER");
    ssd1306_draw_string(6, 2, "1-MARIO BROS");
    ssd1306_draw_string(6, 3, "2-TOP GEAR");
    ssd1306_draw_string(0, 4, "<3-SONIC");
    ssd1306_draw_string(6, 5, "4-DOOM");
    ssd1306_draw_string(6, 6, "5-CASTLEVANIA"); 
}

void menu_four(void) {
    ssd1306_draw_string(6, 0, "HBR-MUSIC PLAYER");
    ssd1306_draw_string(6, 2, "1-MARIO BROS");
    ssd1306_draw_string(6, 3, "2-TOP GEAR");
    ssd1306_draw_string(6, 4, "3-SONIC");
    ssd1306_draw_string(0, 5, "<4-DOOM");
    ssd1306_draw_string(6, 6, "5-CASTLEVANIA"); 
}

void menu_five(void) {
    ssd1306_draw_string(6, 0, "HBR-MUSIC PLAYER");
    ssd1306_draw_string(6, 2, "1-MARIO BROS");
    ssd1306_draw_string(6, 3, "2-TOP GEAR");
    ssd1306_draw_string(6, 4, "3-SONIC");
    ssd1306_draw_string(6, 5, "4-DOOM");
    ssd1306_draw_string(0, 6, "<5-CASTLEVANIA");
}