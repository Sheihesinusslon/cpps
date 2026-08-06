#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    ~MutantStack();

};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
:   std::stack<T, Container>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
:   std::stack<T, Container>(other)
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack &operator=(const MutantStack &other)
{
    if (this != &other)
        std::stack<T, Container>::operator=(other)
    return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

#endif