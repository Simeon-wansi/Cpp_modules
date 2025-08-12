/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:19:49 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/12 22:38:30 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
    

//     std::cout << std::endl;
    
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     std::cout << meta->getType() << " " << std::endl;
    
//     std::cout << std::endl;
    
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
    
//     std::cout << std::endl;
    
//     delete meta;
//     delete i;
//     delete j;

// return 0;
// }

int main()
{
    int N = 6;
    
    Animal* animals[N]; 
    
    // Filling half with Dogs, half with Cats
    for (int i = 0; i < N/2; i++)
    {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
       
    for (int i = N/2; i < N; i++)
    {
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    for (int i = 0; i < N; i++)
    {
        animals[i]->makeSound();
        std::cout << std::endl;
    }        

    // testing the virtual destructor!
    for (int i = 0; i < N; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }
        
}