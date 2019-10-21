#include "task3.hpp"
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> source;
    std::vector<int> result1;
    std::vector<int> result2;
    std::vector<int> result3;
    std::vector<int> result4;

    // Заполняем начальными значениями.
    source.emplace_back(2);
    source.emplace_back(4);
    source.emplace_back(3);
    source.emplace_back(8);
    source.emplace_back(0);

    // Заполняем значениями инкрементированые один раз.
    result1.emplace_back(2 + 1);
    result1.emplace_back(4 + 1);
    result1.emplace_back(3 + 1);
    result1.emplace_back(8 + 1);
    result1.emplace_back(0 + 1);

    // Заполняем значениями инкрементированые два раза.
    result2.emplace_back(2 + 2);
    result2.emplace_back(4 + 2);
    result2.emplace_back(3 + 2);
    result2.emplace_back(8 + 2);
    result2.emplace_back(0 + 2);

    // Заполняем значениями инкрементированые три раза.
    result3.emplace_back(2 + 3);
    result3.emplace_back(4 + 3);
    result3.emplace_back(3 + 3);
    result3.emplace_back(8 + 3);
    result3.emplace_back(0 + 3);

    // Заполняем значениями инкрементированые четыре раза.
    result4.emplace_back(2 + 4);
    result4.emplace_back(4 + 4);
    result4.emplace_back(3 + 4);
    result4.emplace_back(8 + 4);
    result4.emplace_back(0 + 4);

    if (source == result1
            || source == result2
            || source == result3
            || source == result4)
    {
        std::cerr << "Неверное сравнение." << std::endl;

        return 1;
    }

    // Выводим источник данных для визуального сравнения.
    for (auto el : source)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;


    std::for_each(source.begin(), source.end(), [](decltype (*source.begin()) &el)
    {
        ++el;
    });

    // Выводим данные после первого инкремента для визуального сравнения.
    for (auto el : source)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    if (source != result1)
    {
        std::cerr << "Функция std::for_each() работает неверно." << std::endl;

        return 2;
    }



    ils::recursiveIncrement(source.begin(), source.end());

    // Выводим данные после второго инкремента для визуального сравнения.
    for (auto el : source)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    if (source != result2)
    {
        std::cerr << "Функция ils::recursiveIncrement() работает неверно." << std::endl;

        return 3;
    }


    ils::cycledIncrement(source.begin(), source.end());

    // Выводим данные после первого инкремента для визуального сравнения.
    for (auto el : source)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    if (source != result3)
    {
        std::cerr << "Функция ils::cycledIncrement() работает неверно." << std::endl;

        return 4;
    }


    ils::badIncrement(source);

    // Выводим данные после первого инкремента для визуального сравнения.
    for (auto el : source)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    if (source != result4)
    {
        std::cerr << "Функция ils::badIncrement() работает неверно." << std::endl;

        return 5;
    }

    return 0;
}
