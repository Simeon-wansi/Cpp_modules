#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm(), _target("")
{
    std::cout << "PresidentialPardonForm Default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("Presidential Pardon", 25, 5), _target(target)
{
    std::cout << " PresidentialPardonForm  created with target: " << target << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string formName, std::string target):AForm(formName, 25, 5), _target(target)
{
    std::cout << " PresidentialPardonForm  created with target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other): AForm(other)
{
    _target = other._target;
    std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    if( this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout<< "PresidentialPardonForm destroyed";
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!getSign())
        throw std::runtime_error("Form not signed");
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::cout << _target << "has been pardoned by Zaphod Beeblebrox\n";
}