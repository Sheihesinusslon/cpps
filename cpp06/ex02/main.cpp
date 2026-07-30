#include "Base.hpp"
#include "ABC.hpp"

#include <iostream>

int main()
{
    A a;
    B b;
    C c;

    std::cout << "--- identify instances ---" << std::endl;
    identify(&a);
    identify(&b);
    identify(&c);
    identify(a);
    identify(b);
    identify(c);

    std::cout << std::endl << "--- generate and identify ---" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        Base *p = generate();

        identify(p);
        identify(*p);
        delete p;
    }

    std::cout << std::endl << "--- edge cases (Unknown) ---" << std::endl;
    Base base;
    identify(&base);
    identify(NULL);

    return 0;
}
