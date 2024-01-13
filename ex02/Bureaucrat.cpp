#include "Bureaucrat.hpp"

char const*	Bureaucrat::GradeTooLowException::what(void) const _NOEXCEPT
{
	return ("the grade is too low");
}

char const*	Bureaucrat::GradeTooHighException::what(void) const _NOEXCEPT
{
	return ("the grade is too high");
}

int	Bureaucrat::validate(int _grade)
{
	if (_grade > 150)
		throw (GradeTooLowException());
	else if (_grade < 1)
		throw (GradeTooHighException());
	return (_grade);
}

Bureaucrat::Bureaucrat(void) : name(), grade(0)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
try : name(_name), grade(validate(_grade)) {
	std::cout << "Bureaucrat constructor called" << std::endl;
} catch (std::exception &e) { throw ; }

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name), grade(b.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &b)
		grade = b.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const { return (name); }

int	Bureaucrat::getGrade(void) const { return (grade); }

void Bureaucrat::increment(int n)
{
	validate(grade -= n);
	std::cout << name << ", incremented to grade " << grade << "(+" << n << ")." << std::endl;
}

void Bureaucrat::decrement(int n)
{
	validate(grade += n);
	std::cout << name << ", decremented to grade " << grade << "(-" << n << ")." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl);
}

void	Bureaucrat::signForm(AForm& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << "\'" << name << "\' signed \'" << f.getName() << "\'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\'" << name << "\' couldn't sign \'" << f.getName() << "\' because " << e.what() << std::endl;
	}
}
