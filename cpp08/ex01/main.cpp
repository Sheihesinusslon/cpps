#include "Span.hpp"

#include <vector>
#include <list>
#include <cstdlib>
#include <iostream>

void subjectTest()
{
    std::cout << "--- subject test ---" << std::endl;

    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest:  " << sp.longestSpan() << std::endl;
}

void fullTest()
{
    std::cout << "--- full test ---" << std::endl;

    Span sp(2);
    sp.addNumber(1);
    sp.addNumber(2);
    try
    {
        sp.addNumber(3);
        std::cout << "ERROR: no throw" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }
}

void tooShortTest()
{
    std::cout << "--- too short test ---" << std::endl;

    Span empty(5);
    try
    {
        empty.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "empty  -> caught: " << e.what() << std::endl;
    }

    Span one(5);
    one.addNumber(42);
    try
    {
        one.longestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "single -> caught: " << e.what() << std::endl;
    }
}

void rangeTest()
{
    std::cout << "--- range test ---" << std::endl;

    int raw[] = { 5, 3, 42, -8, 17 };
    std::vector<int> data(raw, raw + 5);

    Span sp(5);
    sp.addRange(data.begin(), data.end());
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest:  " << sp.longestSpan() << std::endl;

    Span small(3);
    try
    {
        small.addRange(data.begin(), data.end());
        std::cout << "ERROR: no throw" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "caught: " << e.what() << std::endl;
    }
}

void loadTest()
{
    std::cout << "--- load test (20000, from std::list) ---" << std::endl;

    const unsigned int N = 20000;
    std::list<int> data;
    for (unsigned int i = 0; i < N; ++i)
        data.push_back(std::rand());

    Span sp(N);
    sp.addRange(data.begin(), data.end());
    std::cout << "size:     " << N << std::endl;
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest:  " << sp.longestSpan() << std::endl;
}

int main()
{
    subjectTest();
    fullTest();
    tooShortTest();
    rangeTest();
    loadTest();

    return 0;
}
