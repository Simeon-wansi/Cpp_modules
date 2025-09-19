/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:54:19 by sngantch          #+#    #+#             */
/*   Updated: 2025/09/17 23:06:15 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// int main(void)
// {
//     try
//     {
//         Intern someRandomIntern;
//         AForm* rrf;
//         rrf = someRandomIntern.makeForm("robotomy request", "Bender");
//         if (rrf != NULL)
//             delete rrf;
//     }
//     catch (std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }

    
//     return 0;
// }

int main(void)
{
    std::cout << "=== Testing Intern Factory Pattern ===" << std::endl;
    
    // Test 1: Valid form creation
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        std::cout << "\n--- Test 1: Creating robotomy request ---" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf != NULL) {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
        
        std::cout << "\n--- Test 2: Creating presidential pardon ---" << std::endl;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (ppf != NULL) {
            std::cout << *ppf << std::endl;
            delete ppf;
        }
        
        std::cout << "\n--- Test 3: Creating shrubbery creation ---" << std::endl;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (scf != NULL) {
            std::cout << *scf << std::endl;
            delete scf;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Invalid form name
    try {
        std::cout << "\n--- Test 4: Invalid form name ---" << std::endl;
        Intern intern;
        AForm* invalidForm = intern.makeForm("invalid form", "target");
        if (invalidForm != NULL) {
            delete invalidForm;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Complete workflow - create, sign, execute
    try {
        std::cout << "\n--- Test 5: Complete workflow ---" << std::endl;
        Intern intern;
        Bureaucrat highGrade("Boss", 1);
        
        AForm* form = intern.makeForm("shrubbery creation", "office");
        if (form != NULL) {
            std::cout << "Before signing: " << *form << std::endl;
            highGrade.signForm(*form);
            std::cout << "After signing: " << *form << std::endl;
            highGrade.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Multiple forms with different targets
    try {
        std::cout << "\n--- Test 6: Multiple forms ---" << std::endl;
        Intern intern;
        AForm* forms[3];
        std::string targets[3] = {"Target1", "Target2", "Target3"};
        std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
        
        for (int i = 0; i < 3; i++) {
            forms[i] = intern.makeForm(formNames[i], targets[i]);
            if (forms[i] != NULL) {
                std::cout << "Created: " << *forms[i] << std::endl;
            }
        }
        
        // Clean up
        for (int i = 0; i < 3; i++) {
            if (forms[i] != NULL) {
                delete forms[i];
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

