#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template <typename T>
int easyfind(const T &haystack, int needle)
{
    typename T::const_iterator p = std::find(haystack.begin(), haystack.end(), needle);

    if (p == haystack.end())
        return -1;
    return static_cast<int>(std::distance(haystack.begin(), p));
}


#endif