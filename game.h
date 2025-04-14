#ifndef GAME_H
#define GAME_H

#include "vampire.h"
#include <string>
#include <iostream>

int correct_input(int MIN, int MAX);

void print_menu(int game_mode);

void game_info();

void game_settings(int& game_mode, std::string& vampire1_name, std::string& vampire2_name);

void game_simulation(int& game_mode, std::string& vampire1_name, std::string& vampire2_name);


#endif GAME_H