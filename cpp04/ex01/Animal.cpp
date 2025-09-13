/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:28:03 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 19:25:37 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal(): _type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    _type = other._type;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}


std::string Animal::getType() const
{
    return _type;
}


void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}