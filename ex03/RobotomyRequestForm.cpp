#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), target()
{
	std::cout << "[DEBUG] RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target)
	: AForm("Robotomy Request", 72, 45), target(_target)
{
	std::cout << "[DEBUG] RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& sf)
	: AForm(sf), target(sf.target)
{
	std::cout << "[DEBUG] RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& sf)
{
	if (this != &sf)
		target = sf.target;
	std::cout << "[DEBUG] RobotomyRequestForm copy assignment operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[DEBUG] RobotomyRequestForm destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	// std::cout << "[DEBUG] RobotomyRequestForm execute member function called" << std::endl;
	if (getIsSigned() == 0)
		throw (FormNotSignedException());
	else if (b.getGrade() > getGradeToExecute())
		throw (GradeTooLowException());
	else
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		if (rand() % 2 == 0)
			std::cout << "[INFO] '" << target << "' has been robotomized!(success)" << std::endl;
		else
			std::cout << "[INFO] '" << target << "' couldn't be robotomized!(failed)" << std::endl;
	}
}
