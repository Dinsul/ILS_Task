#ifndef TASK3_H
#define TASK3_H

#include <vector>
#include <stdexcept>


namespace ils {

/*!
 * \brief recursiveIncrement инкрементирует все элементы контейнера.
 *
 *
 * Алгоритм рекурсивно обходин контейнер и инкрементирует каждый элемент.
 * Требования к типам:
 * -Iter должен соответствовать требованиям InputIterator.
 * -Тип на который указывает Iter должен иметь оператор ++
 *
 * \param current итератор указывающий на элемент, который будет инкременирован.
 * После инкрементирования в функцыю будет передан следующий итератор.
 *
 * \param end итератор конца контейнера.
 */
template <class Iter>
void recursiveIncrement(Iter current, const Iter &end)
{
    if (current == end)
    {
        return;
    }

    ++(*current);

    recursiveIncrement(++current, end);
}


/*!
 * \brief cycledIncrement инкрементирует все элементы контейнера.
 *
 *
 * Алгоритм в цикле обходин контейнер и инкрементирует каждый элемент.
 * Требования к типам:
 * -Iter должен соответствовать требованиям InputIterator.
 * -Тип на который указывает Iter должен иметь оператор ++
 *
 * \param begin итератор указывающий на начальный элемент, который будет инкременирован.
 * \param end итератор конца контейнера.
 */
template <class Iter>
void cycledIncrement(Iter begin, const Iter &end)
{
    for (; begin != end; ++begin)
    {
        ++(*begin);
    }
}


// максимальный размер вектра, котрый может быть обработан
// функцией badIncrement
const size_t maxSize = 20;


/*!
 * \brief badIncrement инкрементация вектора интов без
 * цикла и рекурсии.
 *
 * Очень плохой и медленный способ инкрементировать элементы.
 * Но задание надо выполнить, а это единственный способ,
 * который я смог придумать.
 *
 * \param container std::vector содержащий элементы для инкрементирования.
 * \return true если смоли проинкрементировать все элементы в векторе.
 */
bool badIncrement(std::vector<int> &container)
{
    if (container.size() > maxSize)
    {
        // Если элементов больше чем мы можем обработать,
        // то мы их и не будем обрабатывать, вернём ошибку.
        return false;
    }

    try {
        container.at(0)  += 1;
        container.at(1)  += 1;
        container.at(2)  += 1;
        container.at(3)  += 1;
        container.at(4)  += 1;
        container.at(5)  += 1;
        container.at(6)  += 1;
        container.at(7)  += 1;
        container.at(8)  += 1;
        container.at(9)  += 1;
        container.at(10) += 1;
        container.at(11) += 1;
        container.at(12) += 1;
        container.at(13) += 1;
        container.at(14) += 1;
        container.at(15) += 1;
        container.at(16) += 1;
        container.at(17) += 1;
        container.at(18) += 1;
        container.at(19) += 1;
        container.at(20);
    }
    catch (std::out_of_range)
    {
        // Если обратились к несуществующему элементу,
        // значит дошли до конца контейнера и больше нечего инкрементировать.
        return true;
    }
    catch (std::exception &exc)
    {
        // Если исключение было другим, пробрасываем его дальше.
        throw exc;
    }

    // Если попали сюда, что-то пошло не так.
    return false;
}

} // namespace ils

#endif // TASK3_H
