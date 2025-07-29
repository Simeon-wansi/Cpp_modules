/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:14:41 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/28 12:29:36 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
        
    public:
        Contact();

        //setters
        void setFirstName(const std::string& str);
        void setLastName(const std::string& str);
        void setNickName(const std::string& str);
        void setPhoneNumber(const std::string& str);
        void setDarkestSecret(const std::string& str);
        
        //getters
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName()  const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;

        bool isEmpty() const; 
        void displayFull() const;
        std::string truncateField(const std::string& field) const;
};

#endif 