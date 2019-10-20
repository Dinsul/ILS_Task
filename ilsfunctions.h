#ifndef ILSFUNCTIONS_H
#define ILSFUNCTIONS_H

#include <vector>


namespace ils {
class Car;
class CarWeight;
class CarWeightAndVolume;
class Load;

/*!
 * \brief sortDescending сортерует автомомили в порядке уменьшения.
 *
 * Сортировка идёт по грузоподъёмности и вместительности автомобиля.
 * При этом грузоподъёмность имеет более высокий приоретет.
 *
 * \param container std::vector содержащий автомобили, которые нужно
 * отсортировать.
 */
void sortDescending(std::vector<CarWeightAndVolume> &container);


/*!
 * \brief removeLowCapacityCars удаляет автомобили из контейнера, которые
 * имеют вместимость меньше заданного объёма.
 *
 * \param cars контейнер содержащий любые автомобили.
 * \param volume объм груза.
 */
void removeLowCapacityCars(std::vector<Car *> &cars, int volume);

/*!
 * \brief removeLowCapacityCars перегрузка функции удающей автомобили из контейнера, которые
 * имеют вместимость меньше заданного объёма.
 * \param cars контейнер содержащий любые автомобили.
 * \param load груз с заданными параметрами.
 */
void removeLowCapacityCars(std::vector<Car *> &cars, const Load &load);



}

#endif // ILSFUNCTIONS_H
