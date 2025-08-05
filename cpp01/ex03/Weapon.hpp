/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:11:42 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/30 20:50:45 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>


class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string type);
        Weapon(void);
        ~Weapon(void);
        std::string getType(void);
        void setType(std::string type);
};

#endif