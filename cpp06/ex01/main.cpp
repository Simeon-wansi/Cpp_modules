#include "Serializer.hpp"
#include "Data.hpp"


int main(void)
{
    Data data(18, "Simeon");

    std::cout << "Address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);

    std::cout << "Address: " << &raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Address: " << &deserialized << std::endl;

    std::cout << "ID: " << deserialized->getId() << std::endl;
    std::cout << "Name: " << deserialized->getName() << std::endl;
    return 0;
}

