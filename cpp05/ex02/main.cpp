/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:54:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/09/24 19:58:19 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
    try
    {
        std::cout << "1111111111111" << std::endl;
        Bureaucrat lowGrade("Arnaud", 150);
        Bureaucrat midGrade("Lise", 20);
        Bureaucrat highGrade("Simeon", 1);

        ShrubberyCreationForm shrubForm("cible");

        std::cout << "\n Signing test 1\n" ;
        
        lowGrade.signForm(shrubForm);
        midGrade.signForm(shrubForm);
        highGrade.signForm(shrubForm);
        
        std::cout << "\n Testing execution 1\n";
        lowGrade.executeForm(shrubForm);
        highGrade.executeForm(shrubForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Execption: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n 222222222222" << std::endl;
        Bureaucrat lowGrade("Arnaud", 150);
        Bureaucrat midGrade("Lise", 50);
        Bureaucrat highGrade("Simeon", 40);
        std::cout << std::endl;
    
        RobotomyRequestForm shrubForm("garden");

        std::cout << "\n Signing test 2\n" ;
        
        lowGrade.signForm(shrubForm);
        midGrade.signForm(shrubForm);
        highGrade.signForm(shrubForm);
        
        std::cout << "\n Testing execution 2 \n";
        lowGrade.executeForm(shrubForm);
        midGrade.executeForm(shrubForm);
        highGrade.executeForm(shrubForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Execption: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n 333333333333" << std::endl;
        Bureaucrat lowGrade("Arnaud", 150);
        Bureaucrat midGrade("Lise", 20);
        Bureaucrat highGrade("Simeon", 20);
        std::cout << std::endl;
        
        
        PresidentialPardonForm shrubForm("garden");

        std::cout << "\n Signing test 3\n" ;
        
        lowGrade.signForm(shrubForm);
        midGrade.signForm(shrubForm);
        highGrade.signForm(shrubForm);
        
        std::cout << "\n Testing execution 3 \n";
        lowGrade.executeForm(shrubForm);
        midGrade.executeForm(shrubForm);
        highGrade.executeForm(shrubForm);
        
    }
    catch (std::exception& e)
    {
        std::cout << "Execption: " << e.what() << std::endl;
    }

    return 0;
}

