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

Dice& Game::get_dice() {
    return _dice;
}

void Game::add_character(WrapCharacter wrcharacter) {
    _characters.push_back(wrcharacter);
}

void Game::character_reset(std::shared_ptr<Character>& character) {
    for (auto& wrap : _characters) {
        if (std::dynamic_pointer_cast<Vampire>(character) && std::dynamic_pointer_cast<Vampire>(wrap.CHARACTER)) {
            character = std::make_shared<Vampire>(character->get_name(), wrap.HP, wrap.ARMOR, wrap.DAMAGE, wrap.PERK_CHANCE, wrap.ULTIMATE_CHANCE, _dice);
        }
        if (std::dynamic_pointer_cast<Gunslinger>(character) && std::dynamic_pointer_cast<Gunslinger>(wrap.CHARACTER)) {
            character = std::make_shared<Gunslinger>(character->get_name(), wrap.HP, wrap.ARMOR, wrap.DAMAGE, wrap.PERK_CHANCE, wrap.ULTIMATE_CHANCE, _dice);
        }
        if (std::dynamic_pointer_cast<Assasin>(character) && std::dynamic_pointer_cast<Assasin>(wrap.CHARACTER)) {
            character = std::make_shared<Assasin>(character->get_name(), wrap.HP, wrap.ARMOR, wrap.DAMAGE, wrap.PERK_CHANCE, wrap.ULTIMATE_CHANCE, _dice);
        }
        if (std::dynamic_pointer_cast<Paladin>(character) && std::dynamic_pointer_cast<Paladin>(wrap.CHARACTER)) {
            character = std::make_shared<Paladin>(character->get_name(), wrap.HP, wrap.ARMOR, wrap.DAMAGE, wrap.PERK_CHANCE, wrap.ULTIMATE_CHANCE, _dice);
        }

    }
}

void Game::print_menu() noexcept {
    for (size_t i = 0; i < _menu.size(); i++) {
        std::cout << std::format("[{}] {}\n", i + 1, _menu[i]);
    }
    if (!_menu.empty()) {
        std::cout << "Выберите пункт меню: ";
    }
}

void Game::add_menu_item(const std::string& item) {
    _menu.push_back(item);

}

void Game::add_info_item(const std::string& item) {
    _info.push_back(item);
}

void Game::print_info() noexcept {
    for (size_t i = 0; i < _info.size(); i++) {
        std::cout << std::format("{}\n",_info[i]);
    }
}

void Game::settings() {
    std::vector<std::string> classes;
    for (WrapCharacter wrap : _characters) {
        classes.push_back(wrap.CHARACTER->get_class_name());
    }
    for (size_t i = 0; i < classes.size();i++) {
        std::cout << format("{} - {}\n", i + 1, classes[i]);
    }
    std::cout << "Введите номер для класса первого персонажа: ";
    int choose = correct_input(1, classes.size());
    std::cin.ignore();
    std::string name;

    std::cout << "Напишите имя для первого персонажа: ";
    std::getline(std::cin, name);

    _character1 = create_character(choose, name);

    std::cout << "Введите номер для класса второго персонажа: ";
    choose = correct_input(1, classes.size());
    std::cin.ignore();

    std::cout << "Напишите имя для второго персонажа: ";
    std::getline(std::cin, name);
    _character2 = create_character(choose, name);

}

void Game::random_settings(const std::vector<std::string>& vec_names) {
    std::string name1;
    std::string name2;

    do {
        name1 = vec_names[_dice.roll() % vec_names.size()];
        name2 = vec_names[_dice.roll() % vec_names.size()];
    } while (name1 == name2);

    _character1 = create_character((_dice.roll() % _characters.size())+1, name1);
    _character2 = create_character((_dice.roll() % _characters.size())+1, name2);
}

void Game::act(std::shared_ptr<Character> attacker, std::shared_ptr<Character> defender) {
    double damage = 1;
    double start_defender_hp = defender->get_hp();

    if (attacker->is_alive() && _dice.roll() >= attacker->get_ultimate_chance()) {
        damage = attacker->attack();
        defender->receive_damage(damage);
        std::cout << std::format("\n{} нанёс \"{}\" {:.2f} урона\n", attacker->get_name(), defender->get_name(), damage);

    }
    else if (attacker->is_alive()) {
        damage = attacker->ultimate();
        defender->receive_damage(damage);
        std::cout << std::format("\n{} нанёс особым умением \"{}\" {:.2f} урона\n", attacker->get_name(), defender->get_name(), damage);
    }

    if (defender && attacker->is_alive()) {
        double diff_hp = start_defender_hp - defender->get_hp();
        double block_percentage = (1.0 - (diff_hp / damage)) * 100;
        std::cout << std::format("{} заблокировал {:.0f}% нанесенного ему урона\n", defender->get_name(), block_percentage);
    }
}

void Game::statistic(int move) {
    std::cout << std::format("\n\n┌─ Статистика {:2} хода ────┐\n", move);
    std::cout << std::format("│  {:<23}│\n", _character1->get_name() + ':');
    std::cout << std::format("│    Класс: {:<14}│\n", _character1->get_class_name());
    std::cout << std::format("│    Здоровье: {:<8.3f}   │\n", _character1->get_hp());
    std::cout << std::format("│    Броня: {:<4}          │\n", _character1->get_armor());
    std::cout << "│                         │\n";
    std::cout << std::format("│  {:<23}│\n", _character2->get_name() + ':');
    std::cout << std::format("│    Класс: {:<14}│\n", _character2->get_class_name());
    std::cout << std::format("│    Здоровье: {:<8.3f}   │\n", _character2->get_hp());
    std::cout << std::format("│    Броня: {:<4}          │\n", _character2->get_armor());
    std::cout << "└─────────────────────────┘\n";
}

std::shared_ptr<Character> Game::create_character(int choose, std::string name) {
    choose--;
    if (choose == 0) {
        return std::make_shared<Vampire>(name, _characters[0].HP, _characters[0].ARMOR, _characters[0].DAMAGE, _characters[0].PERK_CHANCE, _characters[0].ULTIMATE_CHANCE, _dice);
    }
    if (choose == 1) {
        return std::make_shared<Assasin>(name, _characters[1].HP, _characters[1].ARMOR, _characters[1].DAMAGE, _characters[1].PERK_CHANCE, _characters[1].ULTIMATE_CHANCE, _dice);
    }
    if (choose == 2) {
        return std::make_shared<Paladin>(name, _characters[2].HP, _characters[2].ARMOR, _characters[2].DAMAGE, _characters[2].PERK_CHANCE, _characters[2].ULTIMATE_CHANCE, _dice);
    }
    if (choose == 3) {
        return std::make_shared<Gunslinger>(name, _characters[3].HP, _characters[3].ARMOR, _characters[3].DAMAGE, _characters[3].PERK_CHANCE, _characters[3].ULTIMATE_CHANCE, _dice);
    }
}

std::string Game::simulation() {
    int move = 0;
    character_reset(_character1);
    character_reset(_character2);
    std::cin.ignore();

    while (_character1->is_alive() && _character2->is_alive()) {
        statistic(move);

        std::cout << "Нажмите Enter для следующего хода: \n";
        std::getchar();

        act(_character1, _character2);
        move++;
        act(_character2, _character1);
    }


    statistic(move);
    return (_character2->get_hp() <= 0) ? _character1->get_name() : _character2->get_name();
}

int Game::run(const std::vector<std::string>& vec_names) {
    random_settings(vec_names);

    int choose;
    do {
        print_menu();
        choose = correct_input(1, 5);

        switch (choose)
        {
        case(1): {
            print_info();
            break;
        }
        case(2): {
            random_settings(vec_names);
            std::cout << "\nСлучайно настроено:\n";
            std::cout << "Первый персонаж:\n";
            std::cout << std::format(" Псевдониим: \"{}\"\n Класс: {}\n\n", _character1->get_name(), _character1->get_class_name());
            std::cout << "Второй персонаж:\n";
            std::cout << std::format(" Псевдониим: \"{}\"\n Класс: {}\n", _character2->get_name(), _character2->get_class_name());
            break;
        }
        case(3): {
            settings();
            break;
        }

        case(4): {
            std::string winner = simulation();
            std::cout << "Победу одержал " << winner << "\n\n";
            break;
        }
        }
    } while (choose != 5);
    return 1;
}