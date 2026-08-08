#include "MutantStack.hpp"

#include <list>
#include <iostream>

void testSubject()
{
    std::cout << "--- subject test ---" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void testList()
{
    std::cout << "--- subject test with std::list ---" << std::endl;

    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << mstack.back() << std::endl;

    mstack.pop_back();

    std::cout << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void testListAsUnderlyingContainer()
{
    std::cout << "--- subject test with MutantStack on std::list ---" << std::endl;

    MutantStack<int, std::list<int> > mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int, std::list<int> >::iterator it = mstack.begin();
    MutantStack<int, std::list<int> >::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void testEmpty()
{
    std::cout << "--- empty test ---" << std::endl;

    MutantStack<int> mstack;

    std::cout << mstack.size() << std::endl;
    if (mstack.begin() == mstack.end())
        std::cout << "begin == end" << std::endl;
}

void testCopy()
{
    std::cout << "--- copy test ---" << std::endl;

    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    MutantStack<int> copy(mstack);
    MutantStack<int> assigned;
    assigned = mstack;

    mstack.push(42);

    std::cout << mstack.size() << std::endl;
    std::cout << copy.size() << std::endl;
    std::cout << assigned.size() << std::endl;

    MutantStack<int>::iterator it = copy.begin();
    while (it != copy.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main()
{
    testSubject();
    testList();
    testListAsUnderlyingContainer();
    testEmpty();
    testCopy();

    return 0;
}
