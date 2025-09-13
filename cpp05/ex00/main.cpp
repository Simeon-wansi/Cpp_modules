/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:54:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/29 20:27:30 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void)
{
    Bureaucrat bureau1("Bureau1", 150);
    Bureaucrat bureau2("Bureau2", 150);

    std::cout<<"\n";
    std::cout << bureau1 <<std::endl;
    std::cout << bureau2 <<std::endl;

    std::cout<<"\n";

    for( int i = 1; i < 152; i++)
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
    
    std::cout<<"\n";
    try {
        bureau2.decrementGrade();
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout<<"\n new values \n";
    
    std::cout << bureau1 <<std::endl;
    std::cout << bureau2 <<std::endl;
    
    std::cout<<"\n Invalid\n ";
    try
    {
        Bureaucrat invalid("invalid", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout <<"\n Test grade too low\n";
    try
    {
        Bureaucrat invalid2("TooLow", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Constrcutor error: " << e.what() << '\n';
    }
    
    std::cout<<"\n Cleaning!\n";
}

