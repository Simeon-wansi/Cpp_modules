/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:06:08 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/30 19:02:43 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF =  str;

    std::cout << "The memorry address of the string variablle is: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR is: " << stringPTR << std::endl; 
    std::cout << "The memory adree held by stringREF is " << &stringREF << std::endl;
    std::cout << "    -----------------------------------------"<< std::endl;
    std::cout << "The value of the string variable is: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;

    return (0);
}