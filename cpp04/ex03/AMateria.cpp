/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:33:54 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 22:00:56 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(): _type("")
{
    std::cout << "Default constructor called for AMateria" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "Destructor called for AMateria" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

AMateria::AMateria(const AMateria &other): _type(other._type)
{
    std::cout << "Copy constructor called for AMateria" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
    std::cout << "Constructor with type called for AMateria" << std::endl;
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria used on " << target.getName() << std::endl;
}
