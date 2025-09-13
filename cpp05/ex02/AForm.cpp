/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:30:45 by sngantch          #+#    #+#             */
/*   Updated: 2025/09/03 15:12:36 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("AForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{ }

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{ }

AForm& AForm::operator=(AForm const& other)
{
    std::cout <<" Copy assigment operator called\n ";

    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << _name << "Destroyed !\n";
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();

    std::cout << "AForm parametized with constructor called!\n";
}

std::string AForm::getName() const 
{
    return (_name);
}

bool AForm::getSign() const 
{
    return (_signed);
}

int AForm::getGradeToExecute() const
{
    return(_gradeToExecute);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

void AForm::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign )
        _signed = true;
    else
        throw GradeTooLowException();
}

// void AForm::execute(Bureaucrat const &executor) const
// {
//     if (_signed && _gradeToSign <= _gradeToExecute)
//         std::cout<< executor.getName() << " executed " << _name << std::endl;
// }

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << obj.getName() << " :" << obj.getSign() << " :" << obj.getGradeToExecute()<< " :" << obj.getGradeToSign() ;
    return os;
}