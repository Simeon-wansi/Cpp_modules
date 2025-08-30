/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:54:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/30 22:31:04 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat bureau1("Bureau1", 150);
    
    Form form1("form1", 2, 6);
    

    std::cout<<"\n";
    std::cout << form1 <<std::endl;

    std::cout<<"\n";

   
    
    std::cout<<"\n";
    try {
        
        Form form2("form2", 485, -411);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout<<"\n new values \n";
    
    std::cout << bureau1 <<std::endl;
    
    std::cout<<"\n Cleaning!\n";
}

