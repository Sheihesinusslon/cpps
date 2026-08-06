#include "Serializer.hpp"

#include <iostream>

static void check(const std::string &title, bool ok)
{
    std::cout << (ok ? "[OK] " : "[KO] ") << title << std::endl;
}

int main()
{
    // Serializer s;                    
    // Serializer *p = new Serializer;

    Data data;
    data.id = 42;

    uintptr_t raw = Serializer::serialize(&data);
    Data *back = Serializer::deserialize(raw);

    std::cout << "original : " << &data << std::endl;
    std::cout << "raw      : " << std::hex << raw << std::dec << std::endl;
    std::cout << "restored : " << back << std::endl;
    check("restored pointer equals the original", back == &data);

    back->id = 21;
    check("writes reach the original object", data.id == 21);

    Data *heap = new Data;
    heap->id = 7;
    check("heap round trip", Serializer::deserialize(Serializer::serialize(heap)) == heap);
    delete heap;

    check("NULL round trip", Serializer::deserialize(Serializer::serialize(NULL)) == NULL);
    check("serialized NULL is 0", Serializer::serialize(NULL) == 0);

    return 0;
}
