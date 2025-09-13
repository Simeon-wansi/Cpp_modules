/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:06:11 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/30 18:06:12 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(void);
        ~Zombie(void);
        Zombie(std::string name);
        void setName(std::string name);
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif