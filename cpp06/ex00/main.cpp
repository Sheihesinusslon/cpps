#include "ScalarConverter.hpp"

#include <iostream>

static const char *tests[] = {
        "'c'", "'a'", "'0'", "*", "a",
        "0", "42", "-42", "2147483647", "-2147483648",
        "2147483648", "-2147483649",
        "0.0f", "42.0f", "-4.2f", "4.2f", "42f",
        "0.0", "42.0", "-4.2", "4.2", "3.14159265",
        "1e40",
        "nanf", "+inff", "-inff", "nan", "+inf", "-inf",
        "127", "128", "-1", "65",  // out of the displayable range
        "", "hello", "42abc", "4.2.3", "--42"
    };

const size_t count = sizeof(tests) / sizeof(*tests);

static void test(const std::string &s)
{
    std::cout << "--- [" << s << "] ---" << std::endl;
    ScalarConverter::convert(s);
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    // ScalarConverter converter;
    // ScalarConverter *p = new ScalarConverter();

    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    if (argc > 2)
    {
        std::cout << "usage: " << argv[0] << " [literal]" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < count; i++)
        test(tests[i]);
    return 0;
}
