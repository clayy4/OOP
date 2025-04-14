#include "game.h"


void print_menu(int game_mode) {
    std::cout << "\n\n[1] Информация об игре";
    std::cout << "\n[2] Найстроки игры";
    if (game_mode != 0) {
        std::cout << "\n[3] Симуляция игры";
    }
    std::cout << "\n[4] Выход\n";
    std::cout << "Выберите пункт меню: ";
}