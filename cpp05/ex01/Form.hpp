/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:30:49 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/30 22:37:35 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include "Bureaucrat.hpp"

class Form
{
   private:
    std::string const _name;
    bool _signed;
    const int  _gradeToSign;
    const int _gradeToExecute;

    public:
        Form();
        Form(Form& other);
        ~Form();
        Form& operator=(const Form& other);
        Form(std::string name, int gradeToSign, int gradeToExecute);

        void beSigned(Bureaucrat const&bureaucrat);
    
        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade to high!";
                }
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade to low!";
                }
        };
        
};

std::ostream& operator<<(std::ostream& os, const Form& obj);


#endif