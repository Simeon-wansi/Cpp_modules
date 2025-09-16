#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;
class Bureaucrat;



class Intern{
private:
    

public:
    Intern();
    ~Intern();
    Intern& operator=(const Intern& other);
    Intern(const Intern& other);
    AForm* makeForm(std::string formName, std::string target);
};

#endif