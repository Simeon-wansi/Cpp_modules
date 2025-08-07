/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:06:14 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/07 23:13:27 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"



ClapTrap::ClapTrap() : _name("") , _hitPoint(10) , _energyPoint(10),  _attackDamage(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoint(other._hitPoint), _energyPoint(other._energyPoint), _attackDamage(other._attackDamage) 
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout <<"Copy assignment operator called" << std::endl;
    
    if (this != &other)
    {
        _name = other._name;
        _hitPoint = other._hitPoint;
        _energyPoint = other._energyPoint;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) 
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << _name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoint == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy to attack" << std::endl;
        return;
    }
    _energyPoint--;
   std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

std::string ClapTrap::getName() const
{
    return _name;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoint == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    _hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount < 0)
    {
        std::cout << "Amount must be greater than 0" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
    _hitPoint += amount;
}
