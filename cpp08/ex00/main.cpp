#include "easyfind.hpp"

#include <vector>
#include <list>
#include <deque>
#include <iostream>

void testVector(int *array, int size)
{
    std::cout << "--- test with std::vector ---" << std::endl;

    std::vector<int> v(array, array+size);

    std::cout << easyfind(v, 0)   << std::endl;
    std::cout << easyfind(v, 30)  << std::endl;
    std::cout << easyfind(v, 40)  << std::endl;
    std::cout << easyfind(v, 99)  << std::endl;

    std::vector<int> empty;
    std::cout << easyfind(empty, 1) << std::endl;
}

void testList(int *array, int size)
{
    std::cout << "--- test with std::list ---" << std::endl;

    std::list<int> l(array, array+size);
    std::cout << easyfind(l, 30) << std::endl;
    std::cout << easyfind(l, 99) << std::endl;
}

void testDeque(int *array, int size)
{
    std::cout << "--- test with std::deque ---" << std::endl;

    std::deque<int> d(array, array+size);
    std::cout << easyfind(d, 20) << std::endl;
    std::cout << easyfind(d, 99) << std::endl;
}

int main()
{
    int array[] = { 0, 10, 20, 30, 40 };
    int size = sizeof(array) / sizeof(int);

    testVector(array, size);
    testList(array, size);
    testDeque(array, size);

    return 0;
}