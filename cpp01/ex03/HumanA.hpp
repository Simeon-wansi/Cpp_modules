/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:33:34 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/30 20:51:35 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA(void);
        void attack(void);
};

#endif