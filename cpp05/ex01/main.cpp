#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testBureaucratInitException()
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

void testBureaucratIncrementDecrementException()
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

void testBureaucratBasic()
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

void testFormBasic()
{
    Form contract("contract", 50, 25);
    Form fallback;

    std::cout << "Testing form basics" << std::endl;

    std::cout << contract << std::endl;
    std::cout << fallback << std::endl;

    std::cout << std::endl;
}

void testFormInitException()
{
    std::cout << "Testing form init exceptions" << std::endl;

    try
    {
        Form signTooHigh("sign too high", 0, 25);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form signTooLow("sign too low", 151, 25);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form execTooHigh("exec too high", 50, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form execTooLow("exec too low", 50, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
}

void testFormBeSigned()
{
    Bureaucrat boss("boss", 1);
    Bureaucrat clerk("clerk", 50);
    Bureaucrat intern("intern", 150);
    Form high("high grade", 50, 25);
    Form exact("exact grade", 50, 25);
    Form low("low grade", 50, 25);

    std::cout << "Testing beSigned" << std::endl;

    try
    {
        high.beSigned(boss);
        std::cout << high << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        exact.beSigned(clerk);
        std::cout << exact << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        low.beSigned(intern);
        std::cout << low << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << low << std::endl;
    }

    std::cout << std::endl;
}

void testBureaucratSignForm()
{
    Bureaucrat boss("boss", 1);
    Bureaucrat intern("intern", 150);
    Form contract("contract", 50, 25);
    Form report("report", 50, 25);

    std::cout << "Testing signForm" << std::endl;

    boss.signForm(contract);
    intern.signForm(report);

    std::cout << std::endl;
}

int main()
{
    //testBureaucratBasic();
    //testBureaucratInitException();
    //testBureaucratIncrementDecrementException();

    testFormBasic();
    testFormInitException();
    testFormBeSigned();
    testBureaucratSignForm();

    return 0;
}
