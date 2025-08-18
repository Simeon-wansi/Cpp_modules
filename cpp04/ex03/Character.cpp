/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:03:44 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 22:29:31 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


// Character::Character(std::string name)
// {
//     _name = name;
//     for (int i = 0; i < 4; i++)
//         _inventory[i] = NULL;
// }

Character::Character(Character const & other)
{
    _name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character::~Character(void)
{
    std::cout << "Destructor called for Character" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}


Character & Character::operator=(Character const & other)
{
    if (this == &other)
        return *this;
    _name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    return *this;
}
Character::Character(std::string name)
{
    _name = name;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

std::string const & Character::getName() const
{
    return _name;
}


void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}