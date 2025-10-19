/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:26:05 by sngantch          #+#    #+#             */
/*   Updated: 2025/10/06 19:05:38 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void )
{

    Fixed c = Fixed(3);
    Fixed d = Fixed(8);
    Fixed e = Fixed(3);

    if (c > d)
        std::cout << "c is greater than d" << std::endl;
    else
        std::cout << "c is not greater than d" << std::endl;
        
    if (c >= e || c <= e)
        std::cout << "c is greater than or equal to d" << std::endl;

    if (c < d)
        std::cout << "c is less than d" << std::endl;

    if (c == e)
        std::cout << "c is equal to d" << std::endl;

    if (c != d)
        std::cout << "c is not equal to d" << std::endl;

    Fixed i = Fixed(5);
    Fixed j = Fixed(0);
    std::cout << "\ni is " << i << std::endl;
    std::cout << "j is " << j << std::endl;
    std::cout << "\ni + j = " << i + j << std::endl;
    std::cout << "i - j = " << i - j << std::endl;
    std::cout << "i * j = " << i * j << std::endl;
    std::cout << "i / j = " << i / j << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout <<"\n a is " << a << std::endl;
    std::cout << "++a is " << ++a << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "a++ is " << a++ << std::endl;
    
    std::cout << "\n a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;

    
    std::cout << "max( a, b ) is " << Fixed::max( a, b ) << std::endl;

    
    return 0;
}
