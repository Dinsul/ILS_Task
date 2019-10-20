#ifndef TASK3_H
#define TASK3_H

#include <vector>
#include <stdexcept>


namespace ils {

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


} // namespace ils

#endif // TASK3_H
