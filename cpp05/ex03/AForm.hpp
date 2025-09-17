/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:30:49 by sngantch          #+#    #+#             */
/*   Updated: 2025/09/03 16:47:04 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AForm_HPP
#define AForm_HPP

#include <ostream>
#include "Bureaucrat.hpp"

class AForm
{
   private:
    std::string const _name;
    bool _signed;
    const int  _gradeToSign;
    const int _gradeToExecute;

    public:
        AForm();
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator=(const AForm& other);
        AForm(std::string name, int gradeToSign, int gradeToExecute);

        void beSigned(Bureaucrat const&bureaucrat);
    
        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        
        virtual void execute(Bureaucrat const &executor) const = 0;
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

std::ostream& operator<<(std::ostream& os, const AForm& obj);


#endif