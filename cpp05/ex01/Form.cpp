#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::checkGrade(int grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form()
:   name("default"),
    signed_(false),
    gradeToSign(150),
    gradeToExec(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
:   name(name),
    signed_(false),
    gradeToSign(gradeToSign),
    gradeToExec(gradeToExec)
{
    checkGrade(gradeToSign);
    checkGrade(gradeToExec);
}

Form::~Form()
{
}

Form::Form(const Form &other)
:   name(other.name),
    signed_(other.signed_),
    gradeToSign(other.gradeToSign),
    gradeToExec(other.gradeToExec)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->signed_ = other.signed_;
    return *this;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    signed_ = true;
}

const std::string &Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return signed_;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExec() const
{
    return gradeToExec;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "form " << form.getName() << " grade to sign " << form.getGradeToSign()
        << " grade to exec " << form.getGradeToExec()
        << " signed: " << form.isSigned() << ".";
    return out;
}