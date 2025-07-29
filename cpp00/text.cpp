/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:38:37 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/21 21:40:00 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include <string>
// using namespace std;

// int main()
// {
//     cout << "Hello Sims";
//     return 0;
// }



// int main()
// {
//     int a = 42;
//     float b = 3.14f;
//     char c = 'A';
//     double d = 2.71828;
//     bool e = true;
//     char greeting[] = "Hello, World!";
//     int age;
//     std::string name;
    
//     std::cout << "Sims is the best!\n";
//     std::cout << "Sims will do wonders!" << std::endl;
//     std::cout << "And he knows it!" << "\n";
//     std::cout << 4 + 3;

//     // Printing variables
//     std::cout << "Integer: " << a << std::endl;
//     std::cout << "Float: " << b << std::endl;
//     std::cout << "Character: " << c << std::endl;
//     std::cout << "Double: " << d << std::endl;
//     std::cout << "Boolean: " << (e ? "true" : "false") << std::endl;
//     std::cout << "Type your name" << std::endl;
//     std::cin >> name;
//     std::cout << "Hello, " << name << "!" << std::endl;
//     std::cout << "Type your age" << std::endl;
//     std::cin >> age;
//     std::cout << "You are " << age << " years old" << std::endl;
//     if (age < 18)
//         std::cout << "You are a minor" << std::endl;
//     else
//         std::cout << "You are an adult" << std::endl;
//     return (0);
// }


class Person
{
    public:
        std::string name;
        int age;

};


int main(void)
{
    Person person;
    
    std::cout << "Enter your name: ";
    std::getline(std::cin, person.name);
    std::cout << "Enter your age: ";
    std::cin >> person.age;
    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Age: " << person.age << std::endl;
    return (0);
}