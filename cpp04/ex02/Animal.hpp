/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 22:22:49 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/13 21:54:12 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>


//Any class with one or more pure virtual functions is declared abstract
// And cant be instantiated
class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        Animal &operator=(const Animal &other);
        Animal(const Animal &other);
        
        std::string getType() const;
        // Now we set MakeSound as pure virtual function
        virtual void makeSound() const = 0;
        
};

#endif