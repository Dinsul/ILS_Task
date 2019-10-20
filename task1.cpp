#include "ilsfunctions.h"
#include "cars.h"

void ils::sortDescending(std::vector<ils::CarWeightAndVolume> &container)
{
    std::sort(container.begin(), container.end(), []
              (const CarWeightAndVolume &first,
               const CarWeightAndVolume &second)->bool
    {
        if (second.weight() == first.weight())
        {
            return second.volume() < first.volume();
        }

        return second.weight() < first.weight();
    });
}

