#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(const T& value)
{
    std::cout << value << " ";
}

void printInt(const int& value)
{
    std::cout << value << " ";
}

void doubleValue(int& value)
{
    value *= 2;
}

void shout(std::string& word)
{
    word += "!";
}

void testInts()
{
    std::cout << "Testing ints" << std::endl;

    int numbers[] = {1, 2, 3, 4, 5};
    const size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "int array         : ";
    iter(numbers, numbersLen, printInt);
    std::cout << std::endl;

    std::cout << "after doubleValue : ";
    iter(numbers, numbersLen, doubleValue);
    iter(numbers, numbersLen, printInt);
    std::cout << std::endl;

    std::cout << "printElement<int> : ";
    iter(numbers, numbersLen, printElement<int>);
    std::cout << std::endl;

    const int frozen[] = {10, 20, 30};
    const size_t frozenLen = sizeof(frozen) / sizeof(frozen[0]);

    std::cout << "const int array   : ";
    iter(frozen, frozenLen, printElement<int>);
    std::cout << std::endl;
}

void testStrings()
{
    std::cout << "Testing strings" << std::endl;

    std::string words[] = {"chaine1", "chaine2", "chaine3"};
    const size_t wordsLen = sizeof(words) / sizeof(words[0]);

    std::cout << "string array      : ";
    iter(words, wordsLen, printElement<std::string>);
    std::cout << std::endl;

    std::cout << "after shout       : ";
    iter(words, wordsLen, shout);
    iter(words, wordsLen, printElement<std::string>);
    std::cout << std::endl;
}

int main( void ) {
    testInts();
    testStrings();

    return 0;
}
