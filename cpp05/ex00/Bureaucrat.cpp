#include "Bureaucrat.hpp"

void Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat()
:   name("default"),
    grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
:   name(name),
    grade(grade)
{
    checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
:   name(other.name),
    grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

Bureaucrat &Bureaucrat::operator++()
{
    checkGrade(grade - 1);
    grade--;
    return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
    Bureaucrat temp(*this);

    ++(*this);
    return temp;
}

Bureaucrat &Bureaucrat::operator--()
{
    checkGrade(grade + 1);
    grade++;
    return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
    Bureaucrat temp(*this);

    --(*this);
    return temp;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat: grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat: grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getGrade() << ".";
    return out;
}
