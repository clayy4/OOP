#include <random>

class Vampire{
private:
    double _hp;
    double _armor;
    double _damage;
    double _perk_chance;    
    std::mt19937 rand_gen;
    

public:
    Vampire(): _hp(689.0), _armor(3.25), _damage(3.25), _perk_chance(), rand_gen(){
        std::uniform_real_distribution<double>  dis(5.0,35.0);
        _perk_chance = dis(rand_gen);
    }
    ~Vampire() = default;

    bool is_alive();

    double get_hp();

    void receive_damage(double input_damage);

    void attack(Vampire enemy);

    void ultimate(Vampire enemy);
};