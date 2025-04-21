#include "game.h"


int correct_input(int MIN, int MAX) {
    int input;
 
    while (!(std::cin >> input) || (input < MIN) || (input > MAX)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nВвод некоректный\n"
            << "Попробуйте еще раз: ";
        
    } 
    return input;
}

void print_menu(int game_mode) {
    std::cout << "\n[1] Информация об игре";
    std::cout << "\n[2] Настройки игры";
    if (game_mode != 0) {
        std::cout << "\n[3] Симуляция игры";
    }
    std::cout << "\n[4] Выход\n";
    std::cout << "Выберите пункт меню: ";
}

void game_info() {
    std::cout << "\n\tСражение  вампиров\n"
        << "Игра представляет собой сражение двух вампиров\n"
        << "Где сперва вам предстоит выбрать режим игры и назвать своих героев\n"
        << "Но для хорошего опыта стоит знать правила:\n"
        << "Любая атака имеет шанс удвоить урон 35%\n"
        << "Также имеется ультимейт урон увеличена на 50% и восстанавливает 50% от нанесенного урона.\n"
        << "\n";
}

void game_settings(int& game_mode, std::string& vampire1_name, std::string& vampire2_name) {
    std::cout << "\nВведите режим игры PVP или PVE (1 - PVP, 2 - PVE): ";
    game_mode = correct_input(1, 2);
    std::cin.ignore();
    std::cout << "Назовите персонажа: ";
    std::getline(std::cin, vampire1_name);
    if (game_mode == 1) {
        std::cout << "Назовите второго персонажа: ";
        std::getline(std::cin, vampire2_name);
        return;
    }
    vampire2_name = "Дракула";
}

void game_simulation(std::string& vampire1_name, std::string& vampire2_name) {
    Vampire vampire1;
    Vampire vampire2;
    int move = 1;

    std::mt19937 rd(std::random_device{}());
    std::uniform_int_distribution dist(0, 100);

    

    while (vampire1.is_alive() && vampire2.is_alive()) {
        int which_attack;
        double damage;
        std::cout << "\nХод: " << move << '\n';
        //Ход 1 вампира
        which_attack = dist(rd);
        if (vampire1.is_alive() && which_attack <= 70) {
            damage = vampire1.attack(vampire2);
            std::cout << vampire1_name << " нанёс атакой " << vampire2_name << " " << damage << '\n';
            
        }
        else if(vampire1.is_alive() && which_attack > 70) {
            damage = vampire1.ultimate(vampire2);
            std::cout << vampire1_name << " нанёс особым умением " << vampire2_name << " " << damage << '\n';
        }
        //Ход 2 вампира
        which_attack = dist(rd);
        if (vampire2.is_alive() && which_attack <= 70) {
            damage = vampire2.attack(vampire1);
            std::cout << vampire2_name << " нанёс атакой " << vampire1_name << " " << damage << '\n';
        }

        else if (vampire2.is_alive() && which_attack > 70) {
            damage = vampire2.ultimate(vampire1);
            std::cout << vampire2_name << " нанёс особым умением " << vampire1_name << " " << damage << '\n';
            
        }
        move++;
    }
    if (vampire2.is_alive()) {
        std::cout << "\nПобеду одержал: " << vampire2_name << '\n';
    }
    else {
        std::cout << "\nПобеду одержал: " << vampire1_name << '\n';
    }
}