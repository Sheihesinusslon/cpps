#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>

class Span
{
private:
    unsigned int N;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int nb);
    int shortestSpan() const;
    int longestSpan() const;

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