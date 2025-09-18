
/**
* @file      assasin.h
* @brief     Класс для персонажа-ассасина, наследующий от базового класса Character.
* @details   Класс ассасина включает в себя методы для получения урона, атаки, использования ультимативной способности и перков, таких как шанс избежать урона.
* @author    clay
* @date      26.05.2025
* @copyright © clay, 2025. All rights reserved.
*/

#ifndef ASSASIN_H
#define ASSASIN_H

#include "character.h"

/**
* @brief Класс ассасина (Assassin), наследующий от Character.
*
* Класс ассасина включает в себя методы для получения урона, атаки, использования ультимативной способности,
* а также уникальные перки, такие как шанс избежать урона и увеличенный урон в зависимости от брони.
*/
class Assasin : public Character {
public:
    /**
    * @brief Конструктор ассасина.
    *
    * Создаёт объект ассасина с заданными параметрами.
    *
    * @param name Имя ассасина
    * @param hp Здоровье ассасина
    * @param armor Броня ассасина
    * @param damage Базовый урон ассасина
    * @param perk_chance Шанс на активацию перка
    * @param ultimate_chance Шанс на активацию ультимативной способности
     * @param dice Кубик для расчета вероятностей
    */
    Assasin(const std::string name, const double hp, const double armor, const double damage,
        const int perk_chance, const int ultimate_chance, const Dice dice) :
        Character(name, hp, armor, damage, perk_chance, ultimate_chance, dice) {}
    
    /**
    * @brief Конструктор ассасина.
    *
    * Создаёт объект ассасина с заданными параметрами.
    *
    * @param hp Здоровье ассасина
    * @param armor Броня ассасина
    * @param damage Базовый урон ассасина
    * @param perk_chance Шанс на активацию перка
    * @param ultimate_chance Шанс на активацию ультимативной способности
    * @param dice Кубик для расчета вероятностей
    */
    Assasin(const double hp, const double armor, const double damage,
        const int perk_chance, const int ultimate_chance, const Dice dice) :
        Character(hp, armor, damage, perk_chance, ultimate_chance, dice) {}


    /**
    * @brief Получить наименование класса.
    * @return Название класса на русском
    */
    std::string get_class_name()  const override;


    /**
    * @brief Метод для получения урона ассасином.
    *
    * Этот метод уменьшает здоровье ассасина в зависимости от полученного урона и его брони.
    * Также существует шанс на отсутствие урона за счёт активации перка.
    *
    * @param input_damage Величина получаемого урона
    */
    void receive_damage(double input_damage) override;

    /**
    * @brief Метод для атаки ассасина по противнику.
    *
    * Ассасин наносит базовый урон противнику.
    * @return double Урон, нанесенный противнику
    */
    double attack() override;

    /**
    * @brief Метод для использования ультимативной способности ассасина.
    *
    * Ультимативная способность ассасина увеличивает урон в зависимости от брони.
    * @return double Урон, нанесенный противнику
    */
    double ultimate() override;
};

#endif 
