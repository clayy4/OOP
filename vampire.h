#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <random>

class Vampire{
private:
    double _hp;
    double _armor;
    double _damage;
    double _perk_chance;    
    std::mt19937 rand_gen;
    std::uniform_real_distribution<double>  dis;

public:
    Vampire(): _hp(689.0), _armor(3.25), _damage(3.25), _perk_chance(35.0), rand_gen(), dis(0.0,100.0){}
    ~Vampire() = default;
    
    void dead();

    bool is_alive();

    double get_hp();

    double receive_damage(double input_damage);

    double attack(Vampire enemy);

    double ultimate(Vampire enemy);
};

#endif VAMPIRE_H