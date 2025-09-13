/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:07:34 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 21:25:58 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

// #include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
        
    public:
        AMateria();
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        virtual ~AMateria();
        
        AMateria(std::string const & type);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif