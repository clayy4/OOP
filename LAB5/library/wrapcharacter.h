/**
	* @file      wrapcharacter.h
	* @brief     Класс для игровых персонажей.
	* @details   Содержит первоначальные основные характеристики персонажа.
	* @author    clay
	* @date      27.05.2025
	* @copyright © clay, 2025. All rights reserved.
	*/

#include <memory>
#include "../Characters/character.h"

/**
* @brief Обертка над классом Character для первоначальныъ значений
*/
struct WrapCharacter {

	const std::shared_ptr<Character> CHARACTER;		///< Ссылка на класс персонажа
	const double HP;								///< Количество здоровья
	const double ARMOR;								///< Значение брони
	const double DAMAGE;						    ///< Базовый урон
	const double PERK_CHANCE;					    ///< Шанс срабатывания перка
	const double ULTIMATE_CHANCE;				    ///< Шанс срабатывания ультимативной способности

	/**
	* @brief Обертка над классом Character для хранения данных
	* @param character Ссылка на класс персонажа
	*/
	WrapCharacter(const std::shared_ptr<Character> character) :
		CHARACTER(character), HP(character->get_hp()), ARMOR(character->get_armor()), DAMAGE(character->get_damage()),
		PERK_CHANCE(character->get_perk_chance()), ULTIMATE_CHANCE(character->get_ultimate_chance()) {
	}
};