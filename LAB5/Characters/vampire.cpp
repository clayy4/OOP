#include "vampire.h"

std::string Vampire::get_class_name() const {
    return "Вампир";
}

void Vampire::receive_damage(double input_damage) {
    input_damage *= get_armor() / (get_armor() + Character::ARMOR_BALANCE());
    set_hp(get_hp() - input_damage);
}

double Vampire::attack() {
    double damage = get_damage();
    if (_dice.roll() <= get_perk_chance()) {
        damage *= 2;
    }
    return damage;
}

double Vampire::ultimate() {
    double damage = get_damage() * 1.5;

    if (_dice.roll() <= get_perk_chance()) {
        damage *= 2;
    }

    set_hp(get_hp() + damage * 0.4);
    return damage;
}