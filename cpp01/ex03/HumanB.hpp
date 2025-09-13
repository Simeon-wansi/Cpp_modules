/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:40:39 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/30 21:57:27 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon* _weapon;
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void setWeapon(Weapon& weapon);
        void attack(void);
};

#endif 