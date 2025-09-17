#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;
class Bureaucrat;



class Intern{
private:
    AForm* makeRobotomy(std::string formName, std::string target);
    AForm* makePresidential(std::string formName, std::string target);
    AForm* makeShrubbery(std::string formName, std::string target);

public:
    Intern();
    ~Intern();
    Intern& operator=(const Intern& other);
    Intern(const Intern& other);
    AForm* makeForm(std::string const formName, std::string const target);

    class FormNotFound:public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Form not recongnized";
            }
    };
};


#endif