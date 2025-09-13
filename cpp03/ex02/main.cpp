/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:56:32 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/11 20:15:48 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");
    
    ScavTrap scav("Scavvy");

    FragTrap frag("Fraggy");
    
    clap.attack("Enemy1");
    
    scav.attack("Enemy 2");

    frag.attack("Enemy 3");
    
    scav.guardGate();
    
    frag.highFivesGuys();
    
    scav.takeDamage(5);
    scav.beRepaired(5);

    frag.takeDamage(5);
    frag.beRepaired(5);
    
    std::cout << "\n= Destruction Order =" << std::endl;

    return 0;   
}