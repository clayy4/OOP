/**
 * @file      game.h
 * @brief     Файл, содержащий основные логические функции игры
 * @details   Включает функции отображения меню, настройки и симуляции игры, а также взаимодействия между персонажами.
 * @author    clay
 * @date      26.05.2025
 * @copyright © clay, 2025. All rights reserved.
 */

#ifndef GAME_H
#define GAME_H

#include "../Characters/character.h"
#include "../Characters/assasin.h"
#include "../Characters/paladin.h"
#include "../Characters/gunslinger.h"
#include "../Characters/vampire.h"
#include "dice.h"
#include "wrapcharacter.h"

#include <string>
#include <memory>
#include <iostream>
#include <format>


/**
* @brief Класс игры 
*/
class Game {
private:
	Dice _dice;								///<Кубик
	std::shared_ptr<Character> _character1; ///< Первый персонаж
	std::shared_ptr<Character> _character2; ///< Второй персонаж
	std::vector<std::string> _menu;			///< Вектор пунктов меню
	std::vector<std::string> _info;			///< Вектор информации
	std::vector<WrapCharacter> _characters; ///< Вектор классов персонажей с первоначальными данными

	/**
	* @brief Возвращает персонажа к изначальному состоянию
	* @param Ссылка на персонаж, которого нужно вернуть
	*/
	void character_reset(std::shared_ptr<Character>& character);
public:
	/**
	 * @brief Конструктор игры c расчетом вероятностей от 0 до 100.
	*/
	Game(): _dice(0,100){}

	/**
	* @brief Метод для получения оригинального кубика
	* @return Возвращает кубик из поля игры
	*/
	Dice& get_dice();

	/**
	 * @brief Добавляет в вектор персонажей новый класс
	*/
	void add_character(WrapCharacter wrcharacter);

	/**
	 * @brief Добавляет пункт в главное меню программы.
	 * @param item Пункт меню
	 */
	void add_menu_item(const std::string& item);

	/**
	 * @brief Отображает главное меню программы.
	 */
	void print_menu() noexcept;

	/**
	 * @brief Добавляет пункт в главное меню программы.
	 * @param item Пункт меню информацииы
	 */
	void add_info_item(const std::string& item);

	/**
	 * @brief Выводит информацию об игре.
	 */
	void print_info() noexcept;

	/**
	 * @brief Создаёт персонажа по заданному типу и имени.
	 * @param choose Номер выбранного класса персонажа
	 * @param name Имя персонажа
	 * @return Изменяет персонажей заданных в полях
	 */
	std::shared_ptr<Character> create_character(const int choose, const std::string name);

	/**
	 * @brief Настройки игры: имена и классы персонажей.
	 */
	void settings();

	/**
	 * @brief Создает случайные настройки игры: имена и классы персонажей.
	 * @param vec_names Вектор имен для героев
	 */
	void random_settings(const std::vector<std::string>& vec_names);

	/**
	 * @brief Выполняет действие одного персонажа над другим с использованием случайного фактора.
	 * @param attacker 
	 * @param defender
	*/
	void act(std::shared_ptr<Character> attacker, std::shared_ptr<Character> defender);

	/**
	 * @brief Отображает текущую статистику боя.
	 * @param move Номер текущего хода
	 */
	void statistic(const int move);

	/**
	 * @brief Запускает симуляцию сражения между двумя персонажами.
	 * @return Имя победителя
	 */
	std::string simulation();

	/**
	 * @brief Запускает игру.
	 * @return Возвращает код выполнения программы
	 */
	int run(const std::vector<std::string>& vec_names);
};

 /**
  * @brief Запрашивает у пользователя корректное целочисленное значение в диапазоне от MIN до MAX.
  * @param MIN Минимально допустимое значение
  * @param MAX Максимально допустимое значение
  * @return Корректное значение в указанном диапазоне
  */
int correct_input(const int MIN, const int MAX);

#endif 
