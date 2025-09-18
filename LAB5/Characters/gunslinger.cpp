#include "gunslinger.h"


std::string Gunslinger::get_class_name() const {
	return "Стрелок";
}
void Gunslinger::receive_damage(double input_damage) {
	input_damage *= (get_armor() / (get_armor() + Character::ARMOR_BALANCE()));
	set_hp(get_hp() - input_damage);
}

double Gunslinger::attack() {
	double damage = get_damage();
	if (_dice.roll() <= get_perk_chance()) {
		damage *= 2.5;
		set_hp(get_hp() + get_hp()*0.10);
	}
	return damage;
}

double Gunslinger::ultimate() {
	double damage = get_damage();
	if (_dice.roll() <= get_ultimate_chance()) {
		damage *= 5;
	}
	return damage;
}