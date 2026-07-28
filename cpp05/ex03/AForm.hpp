#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool signed_;
    const int gradeToSign;
    const int gradeToExec;

    static void checkGrade(int grade);

protected:
    virtual void action() const = 0;

public:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExec);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(const Bureaucrat &b);
    void execute(const Bureaucrat &executor) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
