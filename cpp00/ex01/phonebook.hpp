/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:47:51 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/26 19:53:36 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

#include "contact.hpp"


class PhoneBook
{
   private:
        Contact contacts[8];
        int contactCount;
        int oldestContactIndex;
    public:
        PhoneBook();
        
        void addContact();
        void searchContact();
        void displayContactsList() const;
        void displayContact(int index);

    private:
        std::string getInput(const std::string& prompt);
        bool isValidIndex(std::string& input);
};

#endif