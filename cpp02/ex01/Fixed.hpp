/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:20:21 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/08 19:44:34 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _fixedPointValue;
    static const int _fracBit = 8;
    
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
    
    Fixed(int const value);
    Fixed(float const value);
    float toFloat(void) const;
    int toInt(void) const;
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif