/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:36:13 by sngantch          #+#    #+#             */
/*   Updated: 2025/09/03 15:02:37 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat(void): _name("bureau"), _grade(150)
{
    std::cout << "Bureaucrat default constuctor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &other)
    {
        _grade = other._grade;
    }
    
    return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const& other): _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructor called " <<std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << _name << " Destroyed !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
        
    std::cout << "Bureaucrat parametrized with constructor called" << std::endl;
    
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const 
{
    return (_grade);
}


void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade += 1;
    
}

void Bureaucrat::signForm(Form &form)
{
    
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn't sign " << form.getName() << "because " << e.what() << '\n';
    }
    
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() ;
    return os;
}