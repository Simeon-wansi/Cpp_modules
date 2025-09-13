/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:57:43 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/11 21:44:09 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called " << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << _name << " FragTrap destroyed" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;

    std::cout << _name << " FragTrap created" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (_energyPoint == 0 || _hitPoint == 0)
    {
        std::cout << "FragTrap " << _name << " has no energy to attack" << std::endl;
        return;
    }
    _energyPoint--;
   std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " high fives" << std::endl;
}