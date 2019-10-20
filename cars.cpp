#include "cars.h"
#include <iostream>

ils::Car::~Car(){}


int ils::CarWeight::weight() const
{
    return _weight;
}

void ils::CarWeight::print() const
{
    std::cout << "грузоподъёмность: " << _weight << std::endl;

}

bool ils::CarWeight::operator ==(const ils::CarWeight &other) const
{
    return this->weight() == other.weight();
}

ils::CarWeight &ils::CarWeight::operator ++()
{
    ++_weight;

    return *this;
}

ils::CarWeight::CarWeight(int weight)
    : Car()
    , _weight(weight)
{}

int ils::CarWeightAndVolume::volume() const
{
    return _volume;
}

void ils::CarWeightAndVolume::print() const
{
    std::cout << "грузоподъёмность: " << _weight << " вместительность: " << _volume << std::endl;
}

bool ils::CarWeightAndVolume::operator ==(const ils::CarWeightAndVolume &other) const
{
    return this->weight() == other.weight() &&
            this->volume() == other.volume();
}

ils::CarWeight &ils::CarWeightAndVolume::operator ++()
{
    ++_weight;
    ++_volume;

    return *this;
}


ils::CarWeightAndVolume::CarWeightAndVolume(int weight, int volume)
    : CarWeight(weight)
    , _volume(volume)
{}
