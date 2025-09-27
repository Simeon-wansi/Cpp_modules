#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>


class Data;

class Serializer{

private:
    Serializer();
    ~Serializer();
    Serializer& operator=(const Serializer& other);
    Serializer(const Serializer& other);

public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);


};

#endif