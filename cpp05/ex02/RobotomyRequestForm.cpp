#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm(), _target("")
{
    std::cout << "RobotomyRequestForm Defaut constructor called \n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("Robotomy Request", 25, 5), _target(target)
{
    std::cout << "RobotomyRequestForm created for target : " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other): AForm(other)
{
    _target = other._target;
    std::cout << "RobotomyRequestForm copy constructer called \n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destroyed";
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!getSign())
        throw std::runtime_error("Form not signed");
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    
    std::cout <<" BZZZZT DRILL NOISE!" <<std::endl;

    srand(time(0));
    if (rand() % 2 )
        std::cout << _target << " has been robotomized successfully 50% of the time\n";
    else
        std::cout << "Robotomy of " << _target << " failed!" << std::endl;
}