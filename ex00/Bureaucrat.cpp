#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name), grade(b.grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &b)
		grade = b.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name) {
	std::cout << "Bureaucrat string constructor called" << std::endl;
	try
	{
		/*
		if (_grade > 150)
			throw (GradeTooLowExecption);
		else if (_grade < 1)
			throw (GradeTooHighException);
			*/
		grade = _grade;
	}
	catch (std::exception& e)
	{
		// std::cout << ;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl);
}

std::string Bureaucrat::getName(void) const { return (name); }

int	Bureaucrat::getGrade(void) const { return (grade); }

void Bureaucrat::increaseGrade(int n)
{
	try
	{
		grade -= n;
	}
	catch (std::exception& e)
	{
		//
	}
}

void Bureaucrat::decreaseGrade(int n)
{
	try
	{
		grade += n;
	}
	catch (std::exception& e)
	{
		//
	}
}
