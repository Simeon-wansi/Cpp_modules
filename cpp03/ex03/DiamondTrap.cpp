/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:00:54 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/11 22:15:05 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name")
{
    _name = "";
    _hitPoint = 100; //FragTrap value
    _energyPoint = 50; // ScavTrap value
    _attackDamage = 30; // FragTrap value
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    _name = other._name;
    
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
    _name = name;
    _hitPoint = 100; //FragTrap value
    _energyPoint = 50; // ScavTrap value
    _attackDamage = 30; // FragTrap value
    
    std::cout << "DiamondTrap constructor with name called" << std::endl;
}


void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}