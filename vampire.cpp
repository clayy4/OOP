#include "vampire.h"

void Vampire::dead(){
    _hp= 0;
    _armor = 0;
    _damage = 0;
}

double Vampire::get_hp(){
    return _hp;
}

bool Vampire::is_alive(){
    if(get_hp() <= 0){
        dead();
        return false;
    }
    return true;
}

double Vampire::receive_damage(double input_damage){
    input_damage *= _armor/(_armor+2.25);
    _hp-=input_damage;
    is_alive();
    return input_damage;

}

double Vampire::attack(Vampire enemy){
    double damage = _damage;
    if(dis(rand_gen) <=_perk_chance){
        damage *= 2;
    }
    
}

double Vampire::ultimate(Vampire enemy){

}