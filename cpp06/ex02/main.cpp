#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main()
{
    Base *base = generate();

    std::cout << "Indentify from pointer: ";
    identify(base);

    std::cout << "Indentify from reference: ";
    identify(*base);

    delete base;
    return 0;
}