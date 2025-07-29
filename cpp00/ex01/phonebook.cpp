/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:46:52 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/28 11:33:13 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip> 


PhoneBook::PhoneBook()
{
    contactCount = 0;
    oldestContactIndex = 0;
}

bool isWhitesoaceOnly(const std::string& str)
{
    size_t i = 0;
    while (i < str.length())
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') 
            return false;
        i++;
    }
    return true;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string str;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, str);
    if (str.empty())
        return;
    newContact.setFirstName(str);
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, str);
    if (str.empty())
        return;
    newContact.setLastName(str);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, str);
    if (str.empty())
        return;
    newContact.setNickName(str);
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, str);
    if (str.empty())
        return;
    newContact.setPhoneNumber(str);
    
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, str);
    if (str.empty())
        return;
    newContact.setDarkestSecret(str);

    if(contactCount < 8)
    {
        contacts[contactCount] = newContact;
        contactCount++;
    }
    else
    {
        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
}

bool isNumber(const std::string& str)
{
    size_t i = 0;
    while (i < str.length())
    {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return !str.empty();
}

bool PhoneBook::isValidIndex(std::string& input)
{
    int index;
    
    if (!isNumber(input))
    {
        std::cout << "Please enter a valid number between 0 and 7" << std::endl;
        return false;
    }
    index = std::stoi(input);
    if (index >= contactCount)
    {
        std::cout << "Please enter a valid number between 0 and " << contactCount - 1 << std::endl;
        return false;
    }
    if (index < 0 || index > 7)
    {
        std::cout << "Please enter a valid number between 0 and 7" << std::endl;
        return false;
    }
    return true;
}

void PhoneBook::displayContact(int index)
{
    std::cout << "|index| |First name| |Last name| |Nickname|" << std::endl;
    std::cout << index << contacts[index].getFirstName();
    std::cout << contacts[index].getLastName();
    std::cout << contacts[index].getNickName();    
}

void PhoneBook::displayContactsList() const
{
    int i = 0;
    
    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "First name" << "|";
    std::cout << std::setw(10) << std::right << "Last name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
    
    while (i < contactCount && i < 8)
    {
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << contacts[i].truncateField(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << std::right << contacts[i].truncateField(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << contacts[i].truncateField(contacts[i].getNickName()) << "|" << std::endl;
        i++;
    }
}

void PhoneBook::searchContact()
{
    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }
    displayContactsList();
    
    std::string input;
    
    std::cout << "Enter the index of the contact you want to display: ";
    std::getline(std::cin, input);

    
    if (isValidIndex(input))
    {
        int index = std::stoi(input);
        contacts[index].displayFull();
    }
}


