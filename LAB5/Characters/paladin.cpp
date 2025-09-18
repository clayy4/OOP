#include "paladin.h"

std::string Paladin::get_class_name() const {
    return "Паладин";
}

void Paladin::blessed() {
    if (_is_blessing==true) {
        set_armor( get_armor()* 1.5);
        set_damage(get_damage() * 1.75);
    }
    else {
        set_armor(get_armor() / 1.5);
        set_damage(get_damage() / 1.75);
    }
}

void Paladin::receive_damage(double input_damage) {

    if (_dice.roll() <=get_perk_chance()) {
        input_damage *= 0.5;
    }
    input_damage *= get_armor() / (get_armor() + Character::ARMOR_BALANCE());
    set_hp(get_hp() - input_damage);
}

double Paladin::attack() {
    double damage = get_damage();    
    if (_is_blessing) {
        _is_blessing = false;
        blessed();
    }

    return damage;
}

double Paladin::ultimate() {

    if (_dice.roll() <= get_ultimate_chance() && !_is_blessing) {
        _is_blessing = true; 
        blessed();
    }

    return get_damage();
}