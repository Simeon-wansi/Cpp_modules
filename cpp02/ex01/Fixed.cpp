/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:29:05 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/06 16:05:11 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() 
{
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this !=  &other)
    {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}


Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fracBit;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fracBit));
}

int Fixed::toInt() const
{
    return _fixedPointValue >> _fracBit;
}

float Fixed::toFloat() const
{
    return (float)_fixedPointValue / (1 << _fracBit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();  // Use your toFloat() function
    return os;
}
