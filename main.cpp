#include "vampire.h"
#include <iostream>
#include "game.h"

void intro() {
    std::cout << "";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    intro();
    int game_mode = 0;
    int choose = 0;
    std::string vampire1_name;
    std::string vampire2_name;
    do {
        print_menu(game_mode);
        choose = correct_input(1,4);

        switch (choose)
        {
        case(1):{
            game_info();
            break;
        }
        case(2): {
            game_settings(game_mode, vampire1_name, vampire2_name);
            break;
        }
        case(3): {
            game_simulation(vampire1_name, vampire2_name);
            break;
        }
        default:
            std::cout << "Такой пункт отсутсвует";
            break;
        }
    } while (choose != 4);

    
    return 0;
}