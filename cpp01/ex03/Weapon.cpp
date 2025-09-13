/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:04:53 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/30 20:50:34 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon(void) {}

Weapon::Weapon(void) {}

void Weapon::setType(std::string type)
{
    _type = type;
}

std::string Weapon::getType(void)
{
    return _type;
}

Weapon::Weapon(std::string type)
{
    setType(type);
}
