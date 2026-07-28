#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm *buildShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *buildRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *buildPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

struct FormEntry
{
    const char *name;
    AForm *(*build)(const std::string &target);
};

static const FormEntry forms[] = {
    { "shrubbery creation", &buildShrubbery },
    { "robotomy request", &buildRobotomy },
    { "presidential pardon", &buildPardon }
};

static const int formCount = sizeof(forms) / sizeof(forms[0]);

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
    for (int i = 0; i < formCount; i++)
    {
        if (formName == forms[i].name)
        {
            AForm *form = forms[i].build(formTarget);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cerr << "Intern cannot create \"" << formName
              << "\": unknown form name" << std::endl;
    return NULL;
}
