/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:33:02 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 19:25:42 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(): Animal()
{
    _type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}


Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}


Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << "Dog: bark bark bark !" << std::endl;
}
