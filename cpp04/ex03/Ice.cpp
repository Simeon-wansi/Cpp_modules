/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:29:17 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 22:00:04 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"


Ice::Ice(): AMateria("ice") {
    std::cout << " Default constructor called for Ice" << std::endl;
}

Ice::Ice(const Ice &other): AMateria(other) {
    std::cout << " Copy constructor called for Ice" << std::endl;
}

Ice::~Ice() {
    std::cout << "Destructor called for Ice" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Copy assignment operator called for Ice" << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Ice::clone() const
{
    std::cout << "Clone called for Ice" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}