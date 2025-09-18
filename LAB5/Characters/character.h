/**
    * @file      character.h
    * @brief     Абстрактный базовый класс для всех игровых персонажей.
    * @details   Содержит основные характеристики и интерфейс для взаимодействия между персонажами в бою.
    * @author    clay
    * @date      22.05.2025
    * @copyright © clay, 2025. All rights reserved.
    */

#ifndef CHARACTER_H
#define CHARACTER_H


#include <memory>
#include <string>
#include "../library/dice.h"

/**
* @brief Базовый класс Character.
*
* Класс паладина включает в себя методы для получения урона, атаки и ультимативной способности,
* а также уникальные перки, такие как благословение, которое улучшает броню и урон, а также шанс на снижение урона.
*/
class Character {
private:
    std::string _name;          /// Имя персонажа
    double _hp;                 /// Количество здоровья
    double _armor;              /// Значение брони
    double _damage;             /// Базовый урон
    double _perk_chance;        /// Шанс срабатывания перка
    double _ultimate_chance;    /// Шанс срабатывания ультимативной способности

    /**
     * @brief Приватный конструктор по умолчанию, недоступен для создания экземпляров напрямую.
     */
    Character() = default;
protected:
    /**
     * @brief Кубик для вероятностных действий
     */
    Dice _dice;

    /**
     * @brief Установить значение здоровья
     */
    void set_hp(double new_hp);

    /**
     * @brief Установить значение брони
     */
    void set_armor(double new_armor);

    /**
     * @brief Установить значение урона
     */
    void set_damage(double new_damage);

public:

    /**
     * @brief Статический метод-константа влияния брони на урон.
     */
    static double ARMOR_BALANCE();
    /**
     * @brief Удалённый конструктор копирования.
     */
    Character(const Character&) = delete;

    /**
     * @brief Удалённый оператор присваивания.
     */
    Character& operator=(const Character&) = delete;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Character() = default;

    /**
     * @brief Конструктор с параметрами.
     * @param name Имя персонажа
     * @param hp Здоровье
     * @param armor Броня
     * @param damage Урон
     * @param perk_chance Шанс срабатывания перка
     * @param ultimate_chance Шанс ультимативной способности
     * @param dice Кубик для расчета вероятностей
     */
    Character(const std::string name, const double hp, const double armor, const double damage,
        const int perk_chance, const int ultimate_chance, const Dice& dice);

    /**
     * @brief Конструктор с параметрами.
     * @param hp Здоровье
     * @param armor Броня
     * @param damage Урон
     * @param perk_chance Шанс срабатывания перка
     * @param ultimate_chance Шанс ультимативной способности
     * @param dice Кубик для расчета вероятностей
     */
    Character( const double hp, const double armor, const double damage,
        const int perk_chance, const int ultimate_chance, const Dice& dice);

    /**
     * @brief Проверка, жив ли персонаж.
     * @return true, если здоровье больше 0
     */
    bool is_alive();

    /**
     * @brief Получить наименование класса.
     * @return Название класса на русском
     */
    virtual std::string get_class_name() const = 0;

    /**
     * @brief Получить текущее здоровье персонажа.
     * @return Значение здоровья
     */
    double get_hp() const;

    /**
     * @brief Получить имя персонажа.
     * @return Имя
     */
    std::string get_name() const;

    /**
     * @brief Получить урон персонажа.
     * @return Значение урона
     */
    double get_damage() const;

    /**
     * @brief Получить значение брони.
     * @return Значение брони
     */
    double get_armor() const;

    /**
     * @brief Получить шанс срабатывания перка.
     * @return Шанс в процентах
     */
    int get_perk_chance() const;

    /**
     * @brief Получить шанс ультимативной способности.
     * @return Шанс в процентах
     */
    int get_ultimate_chance() const;

    /**
     * @brief Метод для получения урона.
     * @param input_damage Получаемый урон
     */
    virtual void receive_damage(double input_damage) = 0;

    /**
     * @brief Обычная атака по противнику.
     * @return Нанесённый урон
     */
    virtual double attack() = 0;

    /**
     * @brief Применение ультимейта
     * @return Нанесённый урон
     */
    virtual double ultimate() = 0;


};

#endif