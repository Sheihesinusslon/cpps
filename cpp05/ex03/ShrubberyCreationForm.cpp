#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
:   AForm("ShrubberyCreationForm", 145, 137),
    target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
:   AForm("ShrubberyCreationForm", 145, 137),
    target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
:   AForm(other),
    target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::action() const
{
    std::ofstream file((target + "_shrubbery").c_str());

    if (!file.is_open())
        throw ShrubberyCreationForm::FileOpenException();

    file << "       ###\n"
            "      #####\n"
            "     #######\n"
            "    #########\n"
            "   ###########\n"
            "  #############\n"
            "       ###\n"
            "       ###\n"
            "\n"
            "         #\n"
            "        ###\n"
            "       #####\n"
            "      #######\n"
            "     #########\n"
            "    ###########\n"
            "         #\n"
            "         #\n";
    file.close();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "ShrubberyCreationForm: could not open the output file";
}
