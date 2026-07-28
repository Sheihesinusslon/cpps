#include "Bureaucrat.hpp"
#include <iostream>

void testInitException()
{
    std::cout << "Testing init exceptions" << std::endl;

    try
    {
        Bureaucrat tooHigh("too high", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat tooLow("too low", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
}

void testIncrementDecrementException()
{
    Bureaucrat top("top bureaucrat", 1);
    Bureaucrat noname("noname", 150);

    std::cout << "Testing increment/decrement exceptions" << std::endl;

    try
    {
        top++;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        noname--;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
}

void testBasic()
{
    Bureaucrat top("top bureaucrat", 1);
    Bureaucrat noname("noname", 150);

    std::cout << top << std::endl;
    std::cout << noname << std::endl << std::endl;

    top--;
    noname++;

    std::cout << top << std::endl;
    std::cout << noname << std::endl << std::endl;
}

int main()
{
    testBasic();
    testInitException();
    testIncrementDecrementException();

    return 0;
}
