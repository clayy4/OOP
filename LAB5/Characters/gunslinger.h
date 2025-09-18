    /**
     * @file      gunslinger.h
     * @brief     Класс для персонажа-стрелка, наследующий от базового класса Character.
     * @details   Класс стрелка включает в себя методы для получения урона, атаки, использования ультимативной способности и перков, таких как шанс на увеличенный урон и восстановление здоровья.
     * @author    clay
     * @date      26.05.2025
     * @copyright © clay, 2025. All rights reserved.
     */

#ifndef GUNSLINGER_H
#define GUNSLINGER_H

#include "character.h"

     /**
      * @brief Класс стрелка (Gunslinger), наследующий от Character.
      *
      * Класс стрелка включает в себя методы для получения урона, атаки, использования ультимативной способности,
      * а также уникальные перки, такие как увеличение урона с шансом и восстановление здоровья при атаке.
      */
    class Gunslinger : public Character {
    public:
        /**
         * @brief Конструктор стрелка.
         *
         * Создаёт объект стрелка с заданными параметрами.
         *
         * @param name Имя стрелка
         * @param hp Здоровье стрелка
         * @param armor Броня стрелка
         * @param damage Базовый урон стрелка
         * @param perk_chance Шанс на активацию перка
         * @param ultimate_chance Шанс на активацию ультимативной способности
         * @param dice Кубик для расчета вероятностей
         */
        Gunslinger(const std::string name, const double hp, const double armor, const double damage,
            const int perk_chance, const int ultimate_chance, const Dice dice) :
            Character(name, hp, armor, damage, perk_chance, ultimate_chance, dice) {}
        /**
        * @brief Конструктор стрелка.
        *
        * Создаёт объект стрелка с заданными параметрами.
        *
        * @param hp Здоровье стрелка
        * @param armor Броня стрелка
        * @param damage Базовый урон стрелка
        * @param perk_chance Шанс на активацию перка
        * @param ultimate_chance Шанс на активацию ультимативной способности
        * @param dice Кубик для расчета вероятностей
        */
        Gunslinger(const double hp, const double armor, const double damage,
            const int perk_chance, const int ultimate_chance, const Dice dice) :
            Character(hp, armor, damage, perk_chance, ultimate_chance, dice) {}

        /**
        * @brief Получить наименование класса.
        * @return Название класса на русском
        */
        std::string get_class_name()  const override;

        /**
         * @brief Метод для получения урона стрелком.
         *
         * Этот метод уменьшает здоровье стрелка в зависимости от полученного урона и его брони.
         * Также существует шанс на отсутствие урона за счёт активации перка.
         *
         * @param input_damage Величина получаемого урона
         */
        void receive_damage(double input_damage) override;

        /**
         * @brief Метод для атаки стрелка по противнику.
         *
         * Стрелок наносит базовый урон противнику. Если активирован перк, урон увеличивается в 2.5 раза,
         * а стрелок восстанавливает 5% единиц изначального здоровья.
         * @return double Урон, нанесенный противнику
         */
        double attack() override;

        /**
         * @brief Метод для использования ультимативной способности стрелка.
         *
         * Ультимативная способность стрелка увеличивает урон в 5 раз с шансом на активацию.
         * @return double Урон, нанесенный противнику
         */
        double ultimate() override;
    };

#endif // GUNSLINGER_H
