/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:54:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/09/05 16:02:17 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
    try
    {
        Bureaucrat lowGrade("Arnaud", 150);
        Bureaucrat midGrade("Lise", 140);
        Bureaucrat highGrade("Simeon", 130);

        ShrubberyCreationForm shrubForm("garden");

        std::cout << "\n Signing test \n" ;
        
        lowGrade.signForm(shrubForm);
        midGrade.signForm(shrubForm);
        
        std::cout << "\n Testing execution \n";
        lowGrade.executeForm(shrubForm);
        highGrade.executeForm(shrubForm);
    }
    catch (std::exception& e)
    {
        std::cout << "Execption: " << e.what() << std::endl;
    }

    return 0;
}

