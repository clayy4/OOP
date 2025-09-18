/**
 * @file      dice.h
 * @brief     Класс Dice для генерации псевдо случайных чисел
 * @details   Предоставляет интерфейс для получения случайного числа с плавающей точкой в заданном диапазоне.
 * @author    clay
 * @date      23.05.2025
 * @copyright © clay, 2025. All rights reserved.
 */

#ifndef DICE_H
#define DICE_H

#include <random>
#include <cmath>

 /**
  * @brief Класс для генерации случайных чисел с плавающей точкой.
  *
  * Использует стандартный генератор псевдослучайных чисел Mersenne Twister (`std::mt19937`)
  * и равномерное распределение в заданном диапазоне.
  */
class Dice {
private:
    std::mt19937 rand_gen;                     ///< Генератор случайных чисел
    std::uniform_int_distribution<int> dis;    ///< Распределение для генерации чисел

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Dice() = default;

    /**
     * @brief Конструктор с указанием диапазона генерации.
     * @param min Минимальное значение диапазона
     * @param max Максимальное значение диапазона
     */
    Dice(const int min, const int max) : rand_gen(std::random_device{}()), dis(min, max) {}

    /**
     * @brief Генерация случайного числа.
     * @return Случайное число в заданном диапазоне (включительно)
     */

    int roll();
};

#endif // DICE_H
