/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:23:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/31 17:05:45 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harl;
        harl.complain(av[1]);
        return (0);
    }
    std::cout << "Enter complaint level(DEBUG, INFO, WARNING, ERROR):  ";
    return (1);
}