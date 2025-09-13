/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:10:46 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/31 19:20:40 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << CYAN << "*******************************************" << RESET << std::endl;
    std::cout << CYAN << " 🥇 Welcome to My Awesome PhoneBook! 📞🥇" << RESET << std::endl;
    std::cout << CYAN << "*******************************************" << RESET << std::endl;
    std::cout << GREEN << " Available commands: " << RESET;
    std::cout << YELLOW << "ADD" << RESET << ", ";
    std::cout << BLUE << "SEARCH" << RESET << ", ";
    std::cout << RED << "EXIT" << RESET << std::endl;
    std::cout << CYAN << "  ----------------------------------" << RESET << std::endl;
    
    while(true)
    {
        std::cout << "\n ⌨️ Enter command: ";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command ==  "EXIT")
        {
            std::cout << BLUE << " 👋🏼 Goodbye! 👋🏼 " << RESET << std::endl;
            break;
        }
        else if (!command.empty())
            std::cout << RED<< "Invalid command. Use: ADD, SEARCH, or EXIT" << RESET << std::endl;
    }
    return (0);
}