/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:17:50 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 20:18:42 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &other);
        WrongAnimal(const WrongAnimal &other);
        
        std::string getType() const;
        void makeSound() const;
        
};

#endif