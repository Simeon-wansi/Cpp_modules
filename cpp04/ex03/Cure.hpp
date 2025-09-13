/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:37:27 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 20:10:59 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const & src);
        ~Cure();
        Cure & operator=(Cure const & other );
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif