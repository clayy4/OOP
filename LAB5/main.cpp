#include "library/game.h"
#include <iostream>


void intro() {
    std::cout << "┌──ЛР № 4─────────────┐\n"
              << "│Группа: 6113         │\n"
              << "│Автор: Матушкин Роман│\n"
              << "│Вариант: 19          │\n"
              << "└─────────────────────┘\n\n";
}

int main(){
    std::ios_base::sync_with_stdio(false);

    intro();
    
    Game game;
    game.add_menu_item("Информация об игре");
    game.add_menu_item("Случайные настройки игры");
    game.add_menu_item("Настройки игры"); 
    game.add_menu_item("Симуляция боя");
    game.add_menu_item("Выход");


    game.add_info_item("\n\tСражение героев\nИгра представляет собой сражение двух героев на ваш выбор ");
    game.add_info_item("Вы можете сами выбрать классы персонажей и назвать их или сделать это случайным образом");
    game.add_info_item("Для хорошего опыта стоит знать способности:\n");
    game.add_info_item("  Вампир: \nПерк: 20% шанс, что атака удвоится \nУльтимейт: 30% шанс, увеличить урон на 50% и восстанавить 40% здоровья.");
    game.add_info_item("  Ассасин: \nПерк: 20% шанс, уклониться от атаки \nУльтимейт:25% шанс, нанести атаку увеличивающуся урон в зависимости от брони.");
    game.add_info_item("  Паладин: \nПерк: 30% шанс, что получаемый урон будет снизен вдвое \nУльтимейт: 25% шанс, благославить себя на 1 ход, увеличет урон на 75% и броню на 50%.");
    game.add_info_item("  Стрелок: \nПерк: 20% шанс, что его начнет прикрывать снайпер с уроном 250% от обычной атаки, во время чего он сможет восстановить 10% хп \nУльтимейт: 15% шанс стрельнуть серебряной пулей в голову, 500% от изначального урона");

    game.add_character(WrapCharacter(std::make_shared<Vampire>(540., 3., 90., 20., 30., game.get_dice())));
    game.add_character(WrapCharacter(std::make_shared<Assasin>(300., 2., 110., 20., 25., game.get_dice())));
    game.add_character(WrapCharacter(std::make_shared<Paladin>(640., 15., 120., 30., 30., game.get_dice())));
    game.add_character(WrapCharacter(std::make_shared<Gunslinger>(530., 1., 80., 20., 15., game.get_dice())));

    std::vector<std::string> vec_names = {"Roman","Pasha","Maksim","Danil","Egor","Denis", "Valentin","Geralt", "Ezio", "Luna", "Kratos", "Morrigan", "Arthas", "Aloy", "Sephiroth", "Ripley", "Neo", "Thalia", "Vesemir", "Rogue", "Ciri", "Dante", "Jinx", "Bayonetta", "Legion", "Ellie", "Yennefer"};



    game.run(vec_names);
    
    return 0;
}