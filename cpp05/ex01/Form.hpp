#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool signed_;
    const int gradeToSign;
    const int gradeToExec;

    static void checkGrade(int grade);

public:
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExec);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);

    void beSigned(const Bureaucrat &b);

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif