/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:19:49 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 20:38:54 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << std::endl;
    
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* j2 = new WrongCat();

    std::cout << std::endl;
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    
    std::cout << std::endl;
    
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;
    
    meta2->makeSound();
    j2->makeSound();
    
    std::cout << std::endl;
    
    delete meta;
    delete i;
    delete j;
    
    std::cout << std::endl;
    
    delete meta2;
    delete j2;

return 0;
}