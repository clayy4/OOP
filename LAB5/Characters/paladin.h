    /**
     * @file      paladin.h
     * @brief     Класс для персонажа-паладина, наследующий от базового класса Character.
     * @details   Класс паладина включает в себя методы для получения урона, атаки, использования ультимативной способности и перков, таких как благословение.
     * @author    clay
     * @date      26.05.2025
     * @copyright © clay, 2025. All rights reserved.
     */

#ifndef PALADIN_H
#define PALADIN_H

#include "character.h"

     /**
      * @brief Класс паладина, наследующий от Character.
      *
      * Класс паладина включает в себя методы для получения урона, атаки и ультимативной способности,
      * а также уникальные перки, такие как благословение, которое улучшает броню и урон, а также шанс на снижение урона.
      */
    class Paladin : public Character {
    private:
        bool _is_blessing = false; /// Флаг, указывающий на активность благословения

        /**
         * @brief Метод для активации или деактивации благословения.
         *
         * При активированном благословении увеличиваются броня и урон паладина.
         * При деактивированном благословении значения возвращаются к исходным.
         */
        void blessed();

    public:
        /**
         * @brief Конструктор паладина.
         *
         * Создаёт объект паладина с заданными параметрами.
         *
         * @param name Имя паладина
         * @param hp Здоровье паладина
         * @param armor Броня паладина
         * @param damage Базовый урон паладина
         * @param perk_chance Шанс на активацию перка
         * @param ultimate_chance Шанс на активацию ультимативной способности
         * @param dice Кубик для расчета вероятностей
         */

        Paladin(const std::string name, const double hp, const double armor, const double damage,
            const int perk_chance, const int ultimate_chance, const Dice dice) :
            Character(name, hp, armor, damage, perk_chance, ultimate_chance, dice), _is_blessing(false) {}

        /**
         * @brief Конструктор паладина.
         *
         * Создаёт объект паладина с заданными параметрами.
         *
         * @param hp Здоровье паладина
         * @param armor Броня паладина
         * @param damage Базовый урон паладина
         * @param perk_chance Шанс на активацию перка
         * @param ultimate_chance Шанс на активацию ультимативной способности
         * @param dice Кубик для расчета вероятностей
         */
        Paladin(const double hp, const double armor, const double damage,
            const int perk_chance, const int ultimate_chance, const Dice dice) :
            Character(hp, armor, damage, perk_chance, ultimate_chance, dice), _is_blessing(false) {}




         /**
          * @brief Получить наименование класса.
          * @return Название класса на русском
          */
        std::string get_class_name()  const override;

        /**
         * @brief Метод для получения урона паладином.
         *
         * Этот метод уменьшает здоровье паладина в зависимости от полученного урона и его брони.
         * Также существует шанс на снижение урона вдвое за счёт активации перка.
         *
         * @param input_damage Величина получаемого урона
        */

        void receive_damage(double input_damage) override;

        /**
         * @brief Метод для атаки паладином по противнику.
         * Паладин наносит базовый урон противнику.
         * Если паладин использует благословение, оно деактивируется после атаки и обновляются его параметры.
         * 
         * @return double Урон, нанесенный противнику
         */
        double attack() override;

        /**
         * @brief Метод для использования ультимативной способности паладином.
         * Ультимативная способность паладина даёт шанс на активацию благословения, которое усиливает его характеристики.
         * После активации ультимейта паладин наносит базовый урон противнику.
         * 
         * @return double Урон, нанесенный противнику
         */
        double ultimate() override;
    };

#endif 
