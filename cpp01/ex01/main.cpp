/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:06:21 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/01 22:24:49 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* zombie = zombieHorde(20, "zombie");
    for (int i = 0; i < 20; i++)
        zombie[i].announce();
    delete[] zombie;
    return (0);
}
