/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:56:32 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/07 23:00:54 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot1("Robot1");
    ClapTrap robot2("Robot2");
    ClapTrap robot3("Robot3");
    ClapTrap robot4("Robot4");
    ClapTrap robot5("Robot5");
    robot1.attack(robot2.getName());
    robot2.takeDamage(5);
    robot3.beRepaired(3);
    robot4.takeDamage(5);
    robot5.beRepaired(3);
    return 0;   
}