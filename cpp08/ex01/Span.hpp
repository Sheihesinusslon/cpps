#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

class Span
{
private:
    unsigned int maxSize;
    std::vector<int> numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int nb);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end)
    {
        if (numbers.size() + std::distance(begin, end) > maxSize)
            throw SpanFullException();
        numbers.insert(numbers.end(), begin, end);
    }

    class SpanFullException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class SpanTooShortException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif