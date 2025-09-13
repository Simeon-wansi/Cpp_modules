/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:23:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/02 14:58:40 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;

    std::cout << "== Testing Harl's Complaints ==" << std::endl;
    
    //testing all levels
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    harl.complain("INFO");
    std::cout << std::endl;
    
    harl.complain("WARNING");
    std::cout << std::endl;
    
    harl.complain("ERROR");
    std::cout << std::endl;

    //Intereactive mode
    std::string level;
    std::cout << "Enter complaint level(DEBUG, INFO, WARNING, ERROR):  ";
    while (std::getline(std::cin, level) && !level.empty())
    {
        harl.complain(level);
        std::cout << "Enter complaint level(DEBUG, INFO, WARNING, ERROR):  ";
    }

    return (0);
}