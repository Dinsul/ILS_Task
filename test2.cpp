#include "ilsfunctions.h"
#include "cars.h"
#include "load.h"

#include <iostream>


int main()
{
    std::vector<ils::Car*> source;
    std::vector<ils::Car*> result1;
    std::vector<ils::Car*> result2;

    const int minVolume = 3;
    const ils::Load load{3, 4};

    source.push_back(new ils::CarWeightAndVolume{1, 1});
    source.push_back(new ils::CarWeightAndVolume{2, 2});
    source.push_back(new ils::CarWeight{3});
    source.push_back(new ils::CarWeightAndVolume{4, 3});
    source.push_back(new ils::CarWeight{5});
    source.push_back(new ils::CarWeight{6});
    source.push_back(new ils::CarWeightAndVolume{7, 4});
    source.push_back(new ils::CarWeight{8});
    source.push_back(new ils::CarWeightAndVolume{9, 5});
    source.push_back(new ils::CarWeightAndVolume{9, 6});

    // Заполняем результирующий контейнер для удаления
    // по значению объёма только теми элементами, которые
    // останутся после удаления.
    // (Должны удалиться элементы с индексами 0 и 1)
    result1.push_back(source[2]);
    result1.push_back(source[3]);
    result1.push_back(source[4]);
    result1.push_back(source[5]);
    result1.push_back(source[6]);
    result1.push_back(source[7]);
    result1.push_back(source[8]);
    result1.push_back(source[9]);


    // Заполняем результирующий контейнер для удаления
    // по грузу только теми элементами, которые
    // останутся после удаления.
    // (Должен удалиться элемент с индексом 3)
    result2.push_back(source[2]);
    result2.push_back(source[4]);
    result2.push_back(source[5]);
    result2.push_back(source[6]);
    result2.push_back(source[7]);
    result2.push_back(source[8]);
    result2.push_back(source[9]);

    if (source == result1)
    {
        std::cerr << "Сравнение неверно." << std::endl;

        return 1;
    }

    // Удаляем по значению объёма
    removeLowCapacityCars(source, minVolume);

    if (source != result1)
    {
        std::cerr << "Удаление из контейтера по объёму работает неправильно." << std::endl;

        return 2;
    }

    // Распечатаем содержимое контейнера для визуального сравнения.
    std::cout << "\nПосле удаления по объёму" << std::endl;
    for (auto car : source)
    {
        car->print();
    }

    // Удаляем по грузу
    removeLowCapacityCars(source, load);

    if (source != result1)
    {
        std::cerr << "Удаление из контейтера по грузу работает неправильно." << std::endl;

        return 3;
    }

    // Распечатаем содержимое контейнера для визуального сравнения.
    std::cout << "\nПосле удаления по объёму" << std::endl;
    for (auto car : source)
    {
        car->print();
    }

    std::cout << "Тест прошёл успешно" << std::endl;

    // Чистим контейнеры.
    for (auto car : source)
    {
        delete car;
    }

    source.clear();
    result1.clear();
    result2.clear();

    return 0;
}
