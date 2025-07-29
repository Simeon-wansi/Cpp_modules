/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:10:46 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/26 19:32:31 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "📞 Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << " Available command: ADD, SEARCH, EXIT" << std::endl;
    
    while(true)
    {
        std::cout << "\n Enter command: ";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command ==  "EXIT")
        {
            std::cout << "Goodbye!" <<std::endl;
            break;
        }
        else if (!command.empty())
            std::cout << "Invalid command. Use: ADD, SEARCH, or EXIT" << std::endl;
    }
    return (0);
}