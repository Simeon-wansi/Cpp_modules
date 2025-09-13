/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:38:11 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 19:27:56 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"


class Cat: public Animal
{    
    public:
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        
        void makeSound()  const;
};


#endif
