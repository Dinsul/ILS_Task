#include "ilsfunctions.h"
#include "cars.h"
#include "load.h"

#include <algorithm>

void ils::removeLowCapacityCars(std::vector<Car *> &cars, int volume)
{
auto newEnd = std::remove_if(cars.begin(), cars.end(), [&](const Car* car)->bool
        {
            auto carVolume = dynamic_cast<const CarWeightAndVolume *>(car);

            if (carVolume && carVolume->volume() < volume)
            {
                delete car;
                return true;
            }

            return false;
        });

    while(newEnd != cars.end())
    {
        cars.pop_back();
    }
}


void ils::removeLowCapacityCars(std::vector<Car *> &cars, const Load &load)
{
auto newEnd = std::remove_if(cars.begin(), cars.end(), [&](const Car* car)->bool
        {
            auto carVolume = dynamic_cast<const CarWeightAndVolume *>(car);

            if (carVolume && carVolume->volume() < load.volume())
            {
                delete car;
                return true;
            }

            return false;
        });

    while(newEnd != cars.end())
    {
        cars.pop_back();
    }
}
