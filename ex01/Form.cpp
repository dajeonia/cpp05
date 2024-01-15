#include "Form.hpp"

char const*	Form::GradeTooLowException::what(void) const throw()
{
	return ("the grade is too low");
}

char const*	Form::GradeTooHighException::what(void) const throw()
{
	return ("the grade is too high");
}

char const*	Form::FormAlreadySignedException::what(void) const throw()
{
	return ("the form is already signed");
}

int	Form::validate(const int _grade)
{
	if (_grade > 150)
		throw (GradeTooLowException());
	else if (_grade < 1)
		throw (GradeTooHighException());
	return (_grade);
}

Form::Form(void) : name(), is_signed(0), grade_to_sign(0), grade_to_execute(0)
{
	std::cout << "[DEBUG] Form default constructor called (not used)" << std::endl;
}

Form::Form(const std::string& _name, int _sign, int _exec)
try : name(_name), is_signed(0), grade_to_sign(validate(_sign)), grade_to_execute(validate(_exec)) {
	std::cout << "[DEBUG] Form constructor called" << std::endl;
} catch (std::exception &e) { throw ; }

Form::Form(const Form& f)
	: name(f.name), is_signed(f.is_signed), grade_to_sign(f.grade_to_sign), grade_to_execute(f.grade_to_execute)
{
	std::cout << "[DEBUG] Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& f)
{
	std::cout << "[DEBUG] Form copy assignment operator called" << std::endl;
	if (this != &f)
		is_signed = f.is_signed;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "[DEBUG] Form destructor called" << std::endl;
}

std::string Form::getName(void) const { return (name); }

bool	Form::getIsSigned(void) const { return (is_signed); }

int	Form::getGradeToSign(void) const { return (grade_to_sign); }

int Form::getGradeToExecute(void) const { return (grade_to_execute) ; }

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << "-------------------------" << std::endl;
	os << "Name: " << f.getName() << std::endl;
	os << "Status: " << (f.getIsSigned() == 1 ? "Signed" : "Not Signed") << std::endl;
	os << "Grade Need to Sign: " << f.getGradeToSign() << std::endl;
	os << "Grade Need to Execute: " << f.getGradeToExecute() << std::endl;
	return (os << "-------------------------" << std::endl);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (is_signed == 1)
		throw (FormAlreadySignedException());
	else if (b.getGrade() > grade_to_sign)
		throw (GradeTooLowException());
	else
		is_signed = 1;
}
