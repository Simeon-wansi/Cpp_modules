/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:06:41 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/01 22:13:43 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie zombie1("zombie1");
    zombie1.announce();

    Zombie* foo = newZombie("foo");
    foo->announce();

    randomChump("bar");

    delete foo;

    return (0);
}
