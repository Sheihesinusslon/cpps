#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
:   AForm("RobotomyRequestForm", 72, 45),
    target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:   AForm("RobotomyRequestForm", 72, 45),
    target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
:   AForm(other),
    target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string &RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::action() const
{
    std::cout << "* BZZZZT... VRRRRR... DRRRRRRRRR *" << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "the robotomy of " << target << " failed" << std::endl;
}
