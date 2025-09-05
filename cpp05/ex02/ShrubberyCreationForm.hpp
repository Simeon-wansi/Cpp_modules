# ifndef SHRUBBERYGREATIONFORM_HPP
# define SHRUBBERYGREATIONFORM_HPP

#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const& other);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const& executor) const;
};


#endif
