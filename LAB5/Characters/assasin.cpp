#include "assasin.h"

std::string Assasin::get_class_name() const {
	return "Ассасин";
}

void Assasin::receive_damage(double input_damage) {
	if (_dice.roll() <= get_perk_chance()) {
		return;
	}
	input_damage *= (get_armor() / (get_armor() + Character::ARMOR_BALANCE()));
	set_hp(get_hp() - input_damage);
}

double Assasin::attack() {
	return get_damage();
}

double Assasin::ultimate() {
	return get_damage() * ((get_armor() + Character::ARMOR_BALANCE()) / get_armor());
}