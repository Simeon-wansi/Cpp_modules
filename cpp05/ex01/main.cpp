/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:54:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/09/16 20:43:57 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
    // Test 1: Low grade trying to sign
    Bureaucrat lowGrade("Bob", 150);
    Form form1("Tax form", 50, 25);
    
    std::cout << "Before signing: " << form1 << std::endl;
    std::cout << std::endl;
    
    lowGrade.signForm(form1);

    std::cout << std::endl;
    std::cout << "After attempt: " <<form1 << std::endl;
    
    std::cout << "\n--- Second Test ---\n";
    
    // Test 2: High grade signing
    Bureaucrat highGrade("Alice", 1);
    Form form2("Important form", 25, 50);
    
    std::cout << "Before signing: " << form2 << std::endl;
    std::cout << std::endl;
    
    highGrade.signForm(form2);

    std::cout << std::endl;
    std::cout << "After signing: " << form2 << std::endl;

    std::cout << "\nCleaning" << std::endl;
}

