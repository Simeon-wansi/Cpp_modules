/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:12:58 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 14:32:59 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"


class Ice : public AMateria
{
    
    public:
        Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        virtual ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif