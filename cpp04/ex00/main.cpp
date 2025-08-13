/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:19:49 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/13 21:23:12 by sngantch         ###   ########.fr       */
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
    const Animal* dogy = new Dog();
    const Animal* caty = new Cat();
    
    std::cout << std::endl;
    
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* caty2 = new WrongCat();

    std::cout << std::endl;
    
    std::cout << "Type: "<< dogy->getType() << std::endl;
    std::cout << "Type: "<< caty->getType()  << std::endl;
    std::cout << "Type: "<< meta->getType()  << std::endl;
    
    std::cout << std::endl;
    
    caty->makeSound(); //will output the cat sound!
    dogy->makeSound();
    meta->makeSound();

    std::cout << std::endl;
    
    caty2->makeSound();
    meta2->makeSound();
    
    std::cout << std::endl;
    
    delete meta;
    delete caty;
    delete dogy;
    
    std::cout << std::endl;
    
    delete meta2;
    delete caty2;

return 0;
}