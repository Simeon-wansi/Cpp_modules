/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:38:11 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 20:56:40 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{   
    private:
        Brain *_brain; 
    public:
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        
        void makeSound()  const;
};


#endif
