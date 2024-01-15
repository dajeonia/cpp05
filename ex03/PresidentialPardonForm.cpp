#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5), target()
{
	std::cout << "[DEBUG] PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target)
	: AForm("Presidential Pardon", 25, 5), target(_target)
{
	std::cout << "[DEBUG] PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& sf)
	: AForm(sf), target(sf.target)
{
	std::cout << "[DEBUG] PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& sf)
{
	if (this != &sf)
		target = sf.target;
	std::cout << "[DEBUG] PresidentialPardonForm copy assignment operator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[DEBUG] PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	// std::cout << "[DEBUG] PresidentialPardonForm execute member function called" << std::endl;
	if (getIsSigned() == 0)
		throw (FormNotSignedException());
	else if (b.getGrade() > getGradeToExecute())
		throw (GradeTooLowException());
	else
		std::cout << "[INFO] " << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
