#include "dice.h"

int Dice::roll() {
	return static_cast<int>(std::round(dis(rand_gen)));
}
