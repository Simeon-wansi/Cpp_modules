/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:56:32 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/11 22:08:31 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");
    
    ScavTrap scav("Scavvy");

    FragTrap frag("Fraggy");

    std::cout << "\n=== DiamondTrap constructor with name called ===" << std::endl;
    DiamondTrap diamond("Diamondy");
    std::cout << std::endl;
    
    clap.attack("Enemy1");
    
    scav.attack("Enemy 2");

    frag.attack("Enemy 3");
    
    diamond.attack("Enemy 4");
    
    scav.guardGate();
    
    frag.highFivesGuys();
    
    scav.takeDamage(5);
    scav.beRepaired(5);
    

    frag.takeDamage(5);
    frag.beRepaired(5);

    std::cout << "\n == Diamond test == " << std::endl;
    std::cout << "Diamond name: " <<  diamond.getName() << std::endl;
    diamond.whoAmI();
    diamond.guardGate();
    diamond.highFivesGuys();

    diamond.takeDamage(5);
    diamond.beRepaired(5);
    
    std::cout << "\n= Destruction Order =" << std::endl;

    return 0;   
}