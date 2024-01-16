#include "Intern.hpp"

char const*	Intern::FormNoIndexException::what(void) const throw()
{
	return ("the form doesn't exist at index");
}

Intern::Intern(void)
{
	std::cout << "[DEBUG] Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& b)
{
	(void)b;
	std::cout << "[DEBUG] Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& b)
{
	(void)b;
	std::cout << "[DEBUG] Intern copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "[DEBUG] Intern destructor called" << std::endl;
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const
{
	const std::string index[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	int i(0);
	for (; i!=3; ++i)
	{
		if (index[i] == name) {
			std::cout << "[INFO] Intern creates the form \'" << index[i] << "\'" << std::endl;
			break;
		}
	}
	switch (i) {
	case 0:
		return (new ShrubberyCreationForm(target));
	case 1:
		return (new RobotomyRequestForm(target));
	case 2:
		return (new PresidentialPardonForm(target));
	default:
		throw (FormNoIndexException());
	}
}
