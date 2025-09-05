#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(): AForm(), _target("")
{ 
    std::cout << "ShrubberyCreationForm Default constructor called\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("Shrubbery Creation", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm created for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other): AForm(other)
{
    _target = other._target;
    std::cout <<"ShrubberyCreationForm copy constructor called \n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
        
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destroyed";
}

void printInFile(const std::string& fileName)
{
    std::ofstream outFile(fileName);
    if (!outFile)
    {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    outFile << "       ccee88oo\n";
    outFile << "  C8O8O8Q8PoOb o8oo\n";
    outFile << " dOB69QO8PdUOpugoO9bD\n";
    outFile << "CgggbU8OU qOp qOdoUOdcb\n";
    outFile << "     6OuU  /p u gcoUodpP\n";
    outFile << "        \\\\//  /douUP\n";
    outFile << "          \\\\////\n";
    outFile << "           |||/\\\n";
    outFile << "           |||\\/\n";
    outFile << "           |||||\n";
    outFile << "     .....//||||\\....\n";

    outFile.close();
    std::cout << "ASCII tree saved to " << fileName << std::endl;
}


void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{

    if(!getSign())
        throw std::runtime_error("Form not signed");
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::string fileName = _target + "_shrubbery";
    printInFile(fileName);
}
