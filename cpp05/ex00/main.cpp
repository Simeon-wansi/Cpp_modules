/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:54:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/09/24 18:26:36 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
    Bureaucrat bureau1("Bureau1", 150);
    Bureaucrat bureau2("Bureau2", 150);

    std::cout<<"--1--\n";
    std::cout << bureau1 <<std::endl;
    std::cout << bureau2 <<std::endl;

    std::cout<<"--2--\n";

    for( int i = 1; i < 153; i++)
    {
        try
        {
            bureau1.incrementGrade();
        }  
        catch (std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    
    std::cout<<"--3--\n";
    try {
        bureau2.decrementGrade();
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout<<"\n --4--new values \n";
    
    std::cout << bureau1 <<std::endl;
    std::cout << bureau2 <<std::endl;
    
    std::cout<<"\n--5--Invalid\n ";
    try
    {
        Bureaucrat invalid("invalid", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout <<"\n--6--Test grade too low\n";
    try
    {
        Bureaucrat invalid2("TooLow", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Constrcutor error: " << e.what() << '\n';
    }
    
    std::cout<<"\n--7--Cleaning!\n";
}

