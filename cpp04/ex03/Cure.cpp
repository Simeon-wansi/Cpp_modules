/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:37:57 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 21:41:37 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << " Default constructor called for Cure" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Destructor called for Cure" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src) {
    std::cout << "Copy constructor called for Cure" << std::endl;
}

Cure & Cure::operator=(Cure const & other)
{
    std::cout << "Copy assignment operator called for Cure" << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Cure::clone() const
{
    std::cout << "Clone called for Cure" << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}