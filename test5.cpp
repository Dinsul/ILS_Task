#include "task5.hpp"
#include "cars.h"
#include "load.h"

int main()
{
    IncludedExpansion<ils::CarWeightAndVolume> namedCar1{"Car 1", 3, 8};
    InheritanceExtension<ils::CarWeightAndVolume> namedCar2{"Car 2", 5, 9};

    IncludedExpansion<ils::Load> namedLoad1{"Load 1", 8, 3};
    InheritanceExtension<ils::Load> namedLoad2{"Load 2", 6, 5};

    namedCar1.print();
    namedCar2.print();
    namedLoad1.print();
    namedLoad2.print();

    return 0;
}
