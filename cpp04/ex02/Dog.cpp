/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:33:02 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 22:00:18 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(): Animal()
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}


Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}


Dog::Dog(const Dog &other): Animal(other)
{
    _brain = new Brain(*other._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << "Dog: bark bark bark !" << std::endl;
}
