#include "character.h"

Character::Character(const std::string name, const double hp, const double armor, const double damage,
    const int perk_chance, const int ultimate_chance, const Dice &dice)
    : _name(name), _hp(hp), _armor(armor), _damage(damage),
    _perk_chance(perk_chance), _ultimate_chance(ultimate_chance), _dice(dice) {
}
Character::Character(const double hp, const double armor, const double damage,
    const int perk_chance, const int ultimate_chance, const Dice &dice):
    _name(""), _hp(hp), _armor(armor), _damage(damage),
    _perk_chance(perk_chance), _ultimate_chance(ultimate_chance), _dice(dice) {
}

double Character::ARMOR_BALANCE(){
    return 3.25;
}


bool Character::is_alive() {
    return _hp > 0;
}

double Character::get_hp() const {
    if (_hp <= 0) {
        return 0.0;
    }
    return _hp;
}

std::string Character::get_name() const {
    return _name;
}

double Character::get_damage() const {
    return _damage;
}

double Character::get_armor() const {
    return _armor;
}

int Character::get_perk_chance() const {
    return _perk_chance;
}

int Character::get_ultimate_chance() const {
    return _ultimate_chance;
}

void Character::set_hp(double new_hp) {
    _hp = new_hp;
}

void Character::set_armor(double new_armor) {
    _armor = new_armor;
}

void Character::set_damage(double new_damage) {
    _damage = new_damage;
}

