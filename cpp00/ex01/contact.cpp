/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:12:30 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/26 20:29:03 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
}

void Contact::setFirstName(const std::string& str)
{
    firstName = str;
}

void Contact::setLastName(const std::string& str)
{
    lastName = str;
}

void Contact::setNickName(const std::string& str)
{
    nickName = str;
}

void Contact::setPhoneNumber(const std::string& str)
{
    phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string& str)
{
    darkestSecret = str;
}

std::string Contact::getFirstName() const
{
    return (firstName);
}

std::string Contact::getLastName() const
{
    return (lastName);
}

std::string  Contact::getNickName() const
{
    return (nickName);
}

std::string Contact::getPhoneNumber() const
{
    return (phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (darkestSecret);
}


bool Contact::isEmpty() const 
{
    return (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty());
}


std::string Contact::truncateField(const std::string& field) const
{
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");
    else
        return (field);
}

void Contact::displayFull() const 
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}