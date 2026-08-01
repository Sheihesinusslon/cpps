#include "Array.hpp"
#include <iostream>
#include <string>

template <typename T>
void printArray(const std::string& label, const Array<T>& array)
{
    std::cout << label << " (size " << array.size() << ") : ";
    for (unsigned int i = 0; i < array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void testEmpty()
{
    std::cout << "--- empty array ---" << std::endl;

    Array<int> empty;

    std::cout << "size              : " << empty.size() << std::endl;
    try
    {
        empty[0] = 42;
        std::cout << "ERROR: no exception thrown" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "caught            : " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void testDefaultValues()
{
    std::cout << "--- default initialization ---" << std::endl;

    Array<int> numbers(5);

    printArray("ints", numbers);

    Array<std::string> words(3);

    printArray("strings", words);

    std::cout << std::endl;
}

void testCopy()
{
    std::cout << "--- copy construction ---" << std::endl;

    Array<int> original(5);

    for (unsigned int i = 0; i < original.size(); i++)
        original[i] = static_cast<int>(i) * 10;

    Array<int> copy(original);

    copy[0] = 999;
    printArray("original", original);
    printArray("copy    ", copy);

    std::cout << std::endl;
}

void testAssignment()
{
    std::cout << "--- copy assignment ---" << std::endl;

    Array<int> original(4);

    for (unsigned int i = 0; i < original.size(); i++)
        original[i] = static_cast<int>(i) + 1;

    Array<int> assigned;

    assigned = original;
    assigned[0] = 777;
    printArray("original", original);
    printArray("assigned", assigned);

    Array<int>& alias = original;

    original = alias;
    printArray("self-assigned", original);

    std::cout << std::endl;
}

void testOutOfRange()
{
    std::cout << "--- out of range ---" << std::endl;

    Array<int> numbers(3);

    try
    {
        numbers[3] = 1;
        std::cout << "ERROR: no exception thrown" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "write past the end : " << e.what() << std::endl;
    }

    const Array<int> frozen(numbers);

    try
    {
        std::cout << frozen[42] << std::endl;
        std::cout << "ERROR: no exception thrown" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "const read         : " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void testStrings()
{
    std::cout << "--- another type ---" << std::endl;

    Array<std::string> words(3);

    words[0] = "chaine1";
    words[1] = "chaine2";
    words[2] = "chaine3";
    printArray("strings", words);

    Array<std::string> copy(words);

    copy[1] = "modified";
    printArray("original", words);
    printArray("copy    ", copy);

    std::cout << std::endl;
}

int main( void ) {
    testEmpty();
    testDefaultValues();
    testCopy();
    testAssignment();
    testOutOfRange();
    testStrings();

    return 0;
}
