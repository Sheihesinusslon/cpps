#include "Span.hpp"

Span::Span()
:   maxSize(0),
    numbers()
{
}

Span::Span(unsigned int N)
:   maxSize(N),
    numbers()
{
    numbers.reserve(N);
}

Span::Span(const Span& other)
:   maxSize(other.maxSize),
    numbers(other.numbers)
{
}

Span &Span::operator=(const Span& other)
{
    if (this != &other)
    {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int nb)
{
    if (numbers.size() >= maxSize)
        throw SpanFullException();
    numbers.push_back(nb);
}

static unsigned int unsignedDiff(int a, int b)
{
    return static_cast<unsigned int>(a) - static_cast<unsigned int>(b);
}

unsigned int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw SpanTooShortException();

    std::vector<int> tmp(numbers);
    std::sort(tmp.begin(), tmp.end());

    std::vector<unsigned int> diffs(tmp.size());
    std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin(), unsignedDiff);
    return *std::min_element(diffs.begin() + 1, diffs.end());
}

unsigned int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw SpanTooShortException();
    return static_cast<unsigned int>(*std::max_element(numbers.begin(), numbers.end()))
         - static_cast<unsigned int>(*std::min_element(numbers.begin(), numbers.end()));
}

const char *Span::SpanFullException::what() const throw()
{
    return "Span vector already contains maxSize elements";
}

const char *Span::SpanTooShortException::what() const throw()
{
    return "Span vector contains < 2 elements, span can not be found";
}