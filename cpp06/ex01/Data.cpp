#include "Data.hpp"


Data::Data() {
    _id = 0;
    _name = "default";
    std::cout << "Default constructor called" << std::endl;
}


Data::Data(int id , std::string name): _id(id), _name(name)
{
    std::cout << "Constructor called" << std::endl;
}

Data::Data(const Data& other) {
    _id = other._id;
    _name = other._name;
    std::cout << "Copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        _id = other._id;
        _name = other._name;

    }
    return *this;
}

Data::~Data() {
    std::cout << "Destructor called" << std::endl;
}

int Data::getId() const
{
    return _id;
}

std::string Data::getName() const
{
    return _name;
}