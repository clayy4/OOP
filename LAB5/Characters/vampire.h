
/**
 * @file      vampire.h
 * @brief     Класс для персонажа-вампира, наследующий от базового класса Character.
 * @details   Класс вампира имеет уникальные методы для получения урона, атаки и использования ультимативной способности.
 * @author    clay
 * @date      26.05.2025
 * @copyright © clay, 2025. All rights reserved.
 */

#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "character.h"

 /**
  * @brief Класс вампира, наследующий от Character.
  *
  * Класс вампира включает в себя методы для получения урона, атаки и использования ультимативной способности,
  * а также особенности вампира, такие как восстановление здоровья при успешном ультимейте и шанс на увеличение урона.
  */
class Vampire : public Character {
public:
    /**
     * @brief Конструктор вампира.
     *
     * Создаёт объект вампира с заданными параметрами.
     *
     * @param name Имя вампира
     * @param hp Здоровье вампира
     * @param armor Броня вампира
     * @param damage Базовый урон вампира
     * @param perk_chance Шанс на активацию перка
     * @param ultimate_chance Шанс на активацию ультимативной способности
     * @param dice Кубик для расчета вероятностей
     */
    Vampire(const std::string name, const double hp, const double armor, const double damage,
        const int perk_chance, const int ultimate_chance, const Dice dice) :
        Character(name, hp, armor, damage, perk_chance, ultimate_chance, dice) {}

    /**
     * @brief Конструктор вампира.
     *
     * Создаёт объект вампира с заданными параметрами.
     *
     * @param hp Здоровье вампира
     * @param armor Броня вампира
     * @param damage Базовый урон вампира
     * @param perk_chance Шанс на активацию перка
     * @param ultimate_chance Шанс на активацию ультимативной способности
     * @param dice Кубик для расчета вероятностей
     */
    Vampire(const double hp, const double armor, const double damage,
        const int perk_chance, const int ultimate_chance, const Dice dice) :
        Character(hp, armor, damage, perk_chance, ultimate_chance, dice) {}


    /**
    * @brief Получить наименование класса.
    * @return Название класса на русском
    */
    std::string get_class_name()  const override;

    /**
     * @brief Метод для получения урона вампиром.
     *
     * Этот метод уменьшает здоровье вампира в зависимости от полученного урона и его брони.
     * Урон модифицируется с учетом брони вампира.
     *
     * @param input_damage Величина получаемого урона
     */
    void receive_damage(double input_damage) override;

    /**
     * @brief Метод для атаки вампира по противнику.
     *
     * Вампир атакует противника, с возможностью активировать перк, который удваивает урон.
     * Урон, наносимый противнику, зависит от базового урона вампира и активации перка.
     * @return double Урон, нанесенный противнику
     */
    double attack() override;

    /**
     * @brief Метод для использования ультимативной способности вампира.
     *
     * Ультимативная способность вампира увеличивает урон на 50% и может активировать перк для удвоения урона.
     * После успешной атаки вампир восстанавливает часть здоровья.
     * @return double Урон, нанесенный противнику
     */
    double ultimate() override;
};

#endif 