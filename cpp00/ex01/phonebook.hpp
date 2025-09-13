/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:47:51 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/31 19:37:30 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

#include "Contact.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

class PhoneBook
{
   private:
        Contact contacts[8];
        int contactCount;
        int oldestContactIndex;

        bool isValidIndex(std::string& input);
    public:
        PhoneBook();
        ~PhoneBook();
        
        void addContact();
        void searchContact();
        void displayContactsList() const; 
};

#endif