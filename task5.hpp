#ifndef TASK5_H
#define TASK5_H

#include <utility>
#include <string>
#include <iostream>

/*!
 * \brief IncludedExpansion класс добавляющий к заданному классу поле с именем,
 * и расширяющий метод print().
 *
 * Исходный класс включается как параметр нового.
 * Требования к исходному классу:
 * - класс должен иметь конструктор принимающий два числа int.
 * - класс должен иметь метод print().
 *
 */
template <class T>
class IncludedExpansion
{
    std::string _name;
    T _source;

public:
    IncludedExpansion(const std::string &name, int weight, int volume)
        : _name(name)
        ,  _source(weight, volume) {}

    void print()
    {
        std::cout << _name << " ";
        _source.print();
    }
};


/*!
 * \brief InheritanceExtension класс добавляющий к заданному классу поле с именем,
 * и расширяющий метод print().
 *
 * Исходный класс включается как родитель нового.
 * Требования к исходному классу:
 * - класс должен иметь конструктор принимающий два числа int.
 * - класс должен иметь метод print().
 *
 */
template <class T>
class InheritanceExtension : public T
{
    std::string _name;

public:
    InheritanceExtension(const std::string &name, int weight, int volume)
        : T(weight, volume)
        , _name(name)
    {}

    void print()
    {
        std::cout << _name << " ";
        dynamic_cast<T*>(this)->print();
    }
};

#endif // TASK5_H
