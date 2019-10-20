#ifndef CARS_H
#define CARS_H

#include <ostream>

namespace ils {

/*!
 * \brief Car интерфейсный класс автомобиля. Все автомобил
 * должны быть потомками этого класса.
 */
class Car
{
public:
    virtual ~Car();

    /*!
     * \brief print метод печати параметров автомобиля.
     * Все наследники должны уметь распечатывать информациою о себе.
     */
    virtual  void print() const = 0;
};

/*!
 * \brief CarWeight класс автомобиля с грузоподъёмностью.
 * Такие автомобили могут перевозить груз ограниченный
 * по весу, но неограниченный по объёму.
 */
class CarWeight : public Car
{
protected:
    int _weight; //!< Максимальный вес груза, который может перевезти автомобиль.

public:
    /*!
     * \brief CarWeight конструктор автмобиля с ограниченной
     * грузоподъёмностью.
     * \param weight автомобили с грузоподъёмностью дожны принимать
     * максимальный вес груза при создании экземпляра.
     */
    CarWeight (int weight);

    /*!
     * \brief weight метод получения грузоподъёмности.
     * \return значение максимального груза в у.е.
     */
    int weight() const;

    /*!
     * \brief operator == сравнение автомобилей по грузоподъёмности.
     * \param other второй автомобиль для сравнения.
     * \return true если автомобили имеют одинаковую грузоподъёмность.
     */
    bool operator == (const CarWeight &other) const;

    /*!
     * \brief operator ++ увеличивает грузоподъёмность автомобиля на одну у.е.
     * \return ссылка на автомобиль с новой грузоподъёмностью.
     */
    CarWeight &operator ++ ();

    /*!
     * \brief print реализация метода печати параметров.
     */
    void print() const override;
};

class CarWeightAndVolume : public CarWeight
{
    int _volume; //!< Максимальный объём, который поместится в автомобиль.

public:
    /*!
     * \brief CarWeightAndVolume конструктор автмобиля с ограниченной
     * грузоподъёмностью и вместительностью.
     * \param weight автомобили с грузоподъёмностью дожны принимать
     * вес максимального груза при создании экземпляра.
     * \param volume автомобили с ограиченной вместимостью дожны принимать
     * максимальный объём груза при создании экземпляра.
     */
    CarWeightAndVolume(int weight, int volume);

    /*!
     * \brief volume метод получения максимального объёма.
     * \return максимальный объём в у.е.
     */
    int volume() const;

    /*!
     * \brief operator == сравнение автомобилей по грузоподъёмности и вместительности.
     * \param other второй автомобиль для сравнения.
     * \return true если автомобили имеют одинаковую грузоподъёмность и вместительность.
     */
    bool operator == (const CarWeightAndVolume &other) const;

    /*!
     * \brief operator ++ увеличивает грузоподъёмность и вместительность автомобиля на одну у.е.
     * \return ссылка на автомобиль с новыми параметрами.
     */
    CarWeight &operator ++ ();

    /*!
     * \brief print реализация метода печати параметров.
     */
    void print() const override;
};

} // namespace ils

#endif // CARS_H

