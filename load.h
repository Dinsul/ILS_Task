#ifndef LOAD_H
#define LOAD_H

#include <iostream>

namespace ils {


/*!
 * \brief Load класс грузов.
 */
class Load
{
    int _weight; //<! вес груза.
    int _volume; //<! объём груза.

public:
    /*!
     * \brief Load конструктор
     * \param weight экземпляр груза должен полусить заначение веса присоздании.
     * \param volume экземпляр груза должен полусить заначение веса присоздании.
     */
    Load(int weight, int volume)
        : _weight(weight)
        , _volume(volume)
    {}

    /*!
     * \brief weight метод получения веса груза.
     * \return вес груза в у.е.
     */
    int weight() const { return _weight; }

    /*!
     * \brief volume метод получения объёма груза.
     * \return  объём груза в у.е.
     */
    int volume() const { return _volume; }

    /*!
     * \brief print распечатывает параметры груза.
     */
    void print()
    {

        std::cout << "вес: " << _weight << " объём: " << _volume << std::endl;
    }

    bool operator == (const Load &other) const
    {
        return this->weight() == other.weight() && this->volume() == other.volume();
    }

    /*!
     * \brief operator ++ увеличивает параметры груда на одну у.е.
     * \return экземпляр инкрементированного груза.
     */
    Load &operator ++()
    {
        ++_weight;
        ++_volume;

        return *this;
    }
};

} // namespace ils




#endif // LOAD_H
