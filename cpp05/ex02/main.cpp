#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void testFormBasic()
{
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Tester");
    PresidentialPardonForm pardon("Developer");

    std::cout << "Testing form basics" << std::endl;

    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    std::cout << std::endl;
}

void testExecuteSuccess()
{
    Bureaucrat boss("boss", 1);
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Tester");
    PresidentialPardonForm pardon("Developer");

    std::cout << "Testing successful execution" << std::endl;

    boss.signForm(shrubbery);
    boss.executeForm(shrubbery);

    boss.signForm(robotomy);
    boss.executeForm(robotomy);

    boss.signForm(pardon);
    boss.executeForm(pardon);

    std::cout << std::endl;
}

void testExecuteNotSigned()
{
    Bureaucrat boss("boss", 1);
    ShrubberyCreationForm shrubbery("nowhere");

    std::cout << "Testing execution of an unsigned form" << std::endl;

    boss.executeForm(shrubbery);

    try
    {
        shrubbery.execute(boss);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
}

void testExecuteGradeTooLow()
{
    Bureaucrat signer("signer", 25);
    Bureaucrat intern("intern", 150);
    PresidentialPardonForm pardon("Tester");

    std::cout << "Testing execution with a grade that is too low" << std::endl;

    signer.signForm(pardon);
    signer.executeForm(pardon);

    intern.signForm(pardon);
    intern.executeForm(pardon);

    std::cout << std::endl;
}

void testExecuteExactGrade()
{
    Bureaucrat shrubberySigner("shrubbery signer", 145);
    Bureaucrat shrubberyExecutor("shrubbery executor", 137);
    ShrubberyCreationForm shrubbery("garden");

    std::cout << "Testing the exact required grades" << std::endl;

    shrubberySigner.signForm(shrubbery);
    shrubberyExecutor.executeForm(shrubbery);

    std::cout << std::endl;
}

void testPolymorphism()
{
    Bureaucrat boss("boss", 1);
    AForm *forms[3];

    std::cout << "Testing polymorphic execution" << std::endl;

    forms[0] = new ShrubberyCreationForm("home");
    forms[1] = new RobotomyRequestForm("Tester");
    forms[2] = new PresidentialPardonForm("Developer");

    for (int i = 0; i < 3; i++)
    {
        boss.signForm(*forms[i]);
        boss.executeForm(*forms[i]);
        delete forms[i];
    }

    std::cout << std::endl;
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    testFormBasic();
    testExecuteSuccess();
    testExecuteNotSigned();
    testExecuteGradeTooLow();
    testExecuteExactGrade();
    testPolymorphism();

    return 0;
}
