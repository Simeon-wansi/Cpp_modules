#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* Intern::makeRobotomy(std::string formName, std::string target)
{
    std::cout << "Intern creates " << formName << std::endl;

    return new RobotomyRequestForm(formName, target);

}


AForm* Intern::makePresidential(std::string formName, std::string target)
{
    std::cout << "Intern creates " << formName << std::endl;
    
    return new PresidentialPardonForm(formName, target);
}

AForm* Intern::makeShrubbery(std::string formName, std::string target)
{
    std::cout << "Intern creates " << formName << std::endl;

    return new ShrubberyCreationForm(formName, target);
}


Intern::Intern() {}

Intern::~Intern()
{

}
Intern& Intern::operator=(const Intern& other)
{

    (void)other;
    return *this;
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string requests[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    //Array pointer 
    AForm* (Intern::*functions[3])(std::string formName, std::string target) = {
        &Intern::makeRobotomy,
        &Intern::makePresidential,
        &Intern::makeShrubbery
    };

    for (int i=0; i < 3; i++)
    {
        if(formName == requests[i]){
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*functions[i])(formName, target);
        }
    }

    throw FormNotFound();
    return nullptr;
}

