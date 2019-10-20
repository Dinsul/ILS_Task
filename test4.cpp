#include <iostream>

#include "task3.hpp"
#include "load.h"
#include "cars.h"

int main()
{
    std::vector<int> sourceInt;
    std::vector<ils::CarWeight> sourceCarWeight;
    std::vector<ils::CarWeightAndVolume> sourceCarWeightAndVolume;
    std::vector<ils::Load> sourceLoad;

    std::vector<int> resultInt;
    std::vector<ils::CarWeight> resultCarWeight;
    std::vector<ils::CarWeightAndVolume> resultCarWeightAndVolume;
    std::vector<ils::Load> resultLoad;

    // Заполняем начальными значениями.
    sourceInt.emplace_back(5);
    sourceInt.emplace_back(6);
    sourceInt.emplace_back(3);

    sourceCarWeight.emplace_back(9);
    sourceCarWeight.emplace_back(8);
    sourceCarWeight.emplace_back(1);

    sourceCarWeightAndVolume.emplace_back(3, 3);
    sourceCarWeightAndVolume.emplace_back(6, 4);
    sourceCarWeightAndVolume.emplace_back(8, 5);

    sourceLoad.emplace_back(5, 4);
    sourceLoad.emplace_back(6, 5);
    sourceLoad.emplace_back(3, 5);

    // Заполняем значениями инкрементироваными один раз.
    resultInt.emplace_back(5 + 1);
    resultInt.emplace_back(6 + 1);
    resultInt.emplace_back(3 + 1);

    resultCarWeight.emplace_back(9 + 1);
    resultCarWeight.emplace_back(8 + 1);
    resultCarWeight.emplace_back(1 + 1);

    resultCarWeightAndVolume.emplace_back(3 + 1, 3 + 1);
    resultCarWeightAndVolume.emplace_back(6 + 1, 4 + 1);
    resultCarWeightAndVolume.emplace_back(8 + 1, 5 + 1);

    resultLoad.emplace_back(5 + 1, 4 + 1);
    resultLoad.emplace_back(6 + 1, 5 + 1);
    resultLoad.emplace_back(3 + 1, 5 + 1);

    // Выводим изначальные данные для визуального сравнения.
    for (auto el : sourceInt)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    // Так как для структур определён оператор ++
    // то для их увелечения можто воспользоваться любой
    // шаблонной функцией из задания №3.
    // Я считаю, что надо пользоваться уже готовыми функциями
    // (например STL), а не изобретать велосипед.
    std::for_each(sourceInt.begin(), sourceInt.end(), [](decltype (*sourceInt.begin()) &el)
    {
        ++el;
    });

    // Выводим инкрементрованные значения для визуального сравнения.
    for (auto el : sourceInt)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    if (sourceInt != resultInt)
    {
        std::cerr << "Инкримент целого числа работает неверно" << std::endl;

        return 1;
    }

    // Повторяем инкримент и проверку для каждого контейнера.

    for (auto &car : sourceCarWeight)
    {
        car.print();
    }
    std::cout << std::endl;

    std::for_each(sourceCarWeight.begin(), sourceCarWeight.end(), [](decltype (*sourceCarWeight.begin()) &el)
    {
        ++el;
    });

    for (auto &car : sourceCarWeight)
    {
        car.print();
    }
    std::cout << std::endl;

    if (sourceCarWeight != resultCarWeight)
    {
        std::cerr << "Инкримент автомобиля с грузоподъёмностью работает неверно" << std::endl;

        return 1;
    }



    for (auto &car : sourceCarWeightAndVolume)
    {
        car.print();
    }
    std::cout << std::endl;

    std::for_each(sourceCarWeightAndVolume.begin(), sourceCarWeightAndVolume.end(),
                  [](decltype (*sourceCarWeightAndVolume.begin()) &el)
    {
        ++el;
    });

    for (auto &car : sourceCarWeightAndVolume)
    {
        car.print();
    }
    std::cout << std::endl;

    if (sourceCarWeightAndVolume != resultCarWeightAndVolume)
    {
        std::cerr << "Инкримент автомобиля с грузоподъёмностью и вместительностью работает неверно" << std::endl;

        return 1;
    }


    for (auto &load : sourceLoad)
    {
        load.print();
    }
    std::cout << std::endl;

    std::for_each(sourceLoad.begin(), sourceLoad.end(), [](decltype (*sourceLoad.begin()) &el)
    {
        ++el;
    });

    for (auto &load : sourceLoad)
    {
        load.print();
    }
    std::cout << std::endl;


    if (sourceLoad != resultLoad)
    {
        std::cerr << "Инкримент грузов работает неверно" << std::endl;

        return 1;
    }

    return 0;
}
