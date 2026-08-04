#include "Span.hpp"

Span::Span()
:   N(0)
{
}

Span::Span(unsigned int N)
:   N(N)
{
}

Span::Span(const Span& other)
:   N(other.N)
{
}

Span &Span::operator=(const Span& other)
{
    if (this != &other)
        N = other.N;
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int nb)
{

}

int Span::shortestSpan() const
{

}

int Span::longestSpan() const
{

}