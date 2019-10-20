#include "ilsfunctions.h"
#include "cars.h"

#include <iostream>

int main()
{
    std::vector<ils::CarWeightAndVolume> source;
    std::vector<ils::CarWeightAndVolume> result;

    source.push_back(ils::CarWeightAndVolume{4, 2});
    source.push_back(ils::CarWeightAndVolume{5, 8});
    source.push_back(ils::CarWeightAndVolume{2, 5});
    source.push_back(ils::CarWeightAndVolume{4, 1});
    source.push_back(ils::CarWeightAndVolume{1, 4});
    source.push_back(ils::CarWeightAndVolume{3, 6});
    source.push_back(ils::CarWeightAndVolume{4, 7});

    result.push_back(ils::CarWeightAndVolume{5, 8});
    result.push_back(ils::CarWeightAndVolume{4, 7});
    result.push_back(ils::CarWeightAndVolume{4, 2});
    result.push_back(ils::CarWeightAndVolume{4, 1});
    result.push_back(ils::CarWeightAndVolume{3, 6});
    result.push_back(ils::CarWeightAndVolume{2, 5});
    result.push_back(ils::CarWeightAndVolume{1, 4});



    if (source == result)
    {
        std::cerr << "Сравнение неверно." << std::endl;

        return 1;
    }

    ils::sortDescending(source);

    std::cout << "Source" << std::endl;
    for (auto &car : source)
    {
        car.print();
    }


    std::cout << "\nResult" << std::endl;
    for (auto &car : result)
    {
        car.print();
    }


    if (source != result)
    {
        std::cerr << "Сортировка неверна." << std::endl;

        return 2;
    }

    std::cout << "Тест прошёл успешно" << std::endl;

    return 0;
}
