/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:46:52 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/31 19:38:48 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
    contactCount = 0;
    oldestContactIndex = 0;
}

PhoneBook::~PhoneBook() {}

bool isEmptyOrWhitespace(const std::string& str)
{
    if (str.empty()) return true;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') 
            return false;
    }
    return true;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string str;
    
    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, str);
        if (isEmptyOrWhitespace(str))
            std::cout << "❌ Please enter a valid first name ❌" << std::endl;
    } while (isEmptyOrWhitespace(str));
    
    newContact.setFirstName(str);
    
    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, str);
        if (isEmptyOrWhitespace(str))
            std::cout << "❌ Please enter a valid last name ❌" << std::endl;
    } while (isEmptyOrWhitespace(str));
   
    newContact.setLastName(str);

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, str);
        if (isEmptyOrWhitespace(str))
            std::cout << "❌ Please enter a valid nickname ❌" << std::endl;
    } while (isEmptyOrWhitespace(str));
    
    newContact.setNickName(str);
    
    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, str);
        if (isEmptyOrWhitespace(str))
            std::cout << "❌ Please enter a valid phone number ❌" << std::endl;
    } while (isEmptyOrWhitespace(str));
    newContact.setPhoneNumber(str);
    
    do{
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, str);
        if (isEmptyOrWhitespace(str))
            std::cout << "❌ Please enter a valid darkest secret ❌" << std::endl;
    } while (isEmptyOrWhitespace(str));
    
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
        std::cout << "❌ Please enter a valid number between 0 and 7 ❌" << std::endl;
        return false;
    }
    index = std::stoi(input);
    if (index >= contactCount)
    {
        std::cout << "❌ Please enter a valid number between 0 and " << contactCount - 1 << " next time ❌" << std::endl;
        return false;
    }
    if (index < 0 || index > 7)
    {
        std::cout << "❌ Please enter a valid number between 0 and 7 ❌" << std::endl;
        return false;
    }
    return true;
}

void PhoneBook::displayContactsList() const
{
    int i = 0;
    
    std::cout << GREEN;
    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "First name" << "|";
    std::cout << std::setw(10) << std::right << "Last name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
    std::cout << RESET;
    
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
