#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::checkGrade(int grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm()
:   name("default"),
    signed_(false),
    gradeToSign(150),
    gradeToExec(150)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
:   name(name),
    signed_(false),
    gradeToSign(gradeToSign),
    gradeToExec(gradeToExec)
{
    checkGrade(gradeToSign);
    checkGrade(gradeToExec);
}

AForm::AForm(const AForm &other)
:   name(other.name),
    signed_(other.signed_),
    gradeToSign(other.gradeToSign),
    gradeToExec(other.gradeToExec)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->signed_ = other.signed_;
    return *this;
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::isSigned() const
{
    return signed_;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExec() const
{
    return gradeToExec;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    signed_ = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!signed_)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > gradeToExec)
        throw AForm::GradeTooLowException();
    action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm: form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "form " << form.getName() << " grade to sign " << form.getGradeToSign()
        << " grade to exec " << form.getGradeToExec()
        << " signed: " << form.isSigned() << ".";
    return out;
}
