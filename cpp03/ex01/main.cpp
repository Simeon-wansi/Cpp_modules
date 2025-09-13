/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:56:32 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/11 18:48:36 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");
    
    ScavTrap scav("Scavvy");
    
    clap.attack("Enemy1");
    
    scav.attack("Enemy 2");
    
    scav.guardGate();
    
    scav.takeDamage(5);
    scav.beRepaired(5);
    
    return 0;   
}