#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cctype>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

static bool isNan(double v)
{
    return v != v;
}

static bool isInf(double v)
{
    return !isNan(v) && std::fabs(v) > std::numeric_limits<double>::max();
}

static void printChar(double v)
{
    std::cout << "char: ";
    if (isNan(v) || isInf(v)
        || v < std::numeric_limits<char>::min()
        || v > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(static_cast<char>(v))))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(v) << "'" << std::endl;
}

static void printInt(double v)
{
    std::cout << "int: ";
    if (isNan(v) || isInf(v)
        || v < std::numeric_limits<int>::min()
        || v > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(v) << std::endl;
}

static void printReal(double v, const char *suffix)
{
    if (isNan(v))
        std::cout << "nan" << suffix << std::endl;
    else if (isInf(v))
        std::cout << (v > 0 ? "+inf" : "-inf") << suffix << std::endl;
    else
    {
        if (std::floor(v) == v && std::fabs(v) < 1e16)
            std::cout << std::fixed << std::setprecision(1);
        std::cout << v << suffix << std::endl;
        std::cout.unsetf(std::ios::floatfield);
        std::cout.precision(6);
    }
}

void ScalarConverter::convert(const std::string &s)
{
    double v;

    if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
        v = s[1];
    else if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
        v = s[0];
    else
    {
        char *end;
        v = std::strtod(s.c_str(), &end);
        if (end == s.c_str() || (*end != '\0' && !(*end == 'f' && end[1] == '\0')))
        {
            std::cout << "Error: \"" << s << "\" is not a known literal." << std::endl;
            return;
        }
        if (*end == 'f')
            v = static_cast<float>(v);
    }
    printChar(v);
    printInt(v);
    std::cout << "float: ";
    if (!isNan(v) && !isInf(v) && std::fabs(v) > std::numeric_limits<float>::max())
        std::cout << "impossible" << std::endl;
    else
        printReal(static_cast<float>(v), "f");
    std::cout << "double: ";
    printReal(v, "");
}
