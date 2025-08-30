/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:30:45 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/30 22:38:24 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{ }

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{ }

Form& Form::operator=(Form const& other)
{
    std::cout <<" Copy assigment operator called\n";

    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form()
{
    std::cout << _name << "Destroyed !\n";
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):_name(name), _signed(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();

    std::cout << "Form parametized with constructor called!\n";
}

std::string Form::getName() const 
{
    return (_name);
}

bool Form::getSign() const 
{
    return (_signed);
}

int Form::getGradeToExecute() const
{
    return(_gradeToExecute);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign )
        _signed = true;
    else
        throw GradeTooLowException;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << obj.getName() << " :" << obj.getSign() << " :" << obj.getGradeToExecute()<< " :" << obj.getGradeToSign() ;
    return os;
}