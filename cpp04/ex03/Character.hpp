/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:54:25 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 22:23:46 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
    public:
        Character(std::string name);
        Character(Character const & other);
        ~Character(void);
        Character & operator=(Character const & other);
        
        
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
    private:
        std::string _name;
        AMateria* _inventory[4];
};

#endif