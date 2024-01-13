#include "AForm.hpp"

char const*	AForm::GradeTooLowException::what(void) const _NOEXCEPT
{
	return ("the grade is too low");
}

char const*	AForm::GradeTooHighException::what(void) const _NOEXCEPT
{
	return ("the grade is too high");
}

char const*	AForm::AFormAlreadySignedException::what(void) const _NOEXCEPT
{
	return ("the form is already signed");
}

int	AForm::validate(const int _grade)
{
	if (_grade > 150)
		throw (GradeTooLowException());
	else if (_grade < 1)
		throw (GradeTooHighException());
	return (_grade);
}

AForm::AForm(void) : name(), target(), is_signed(0), grade_to_sign(0), grade_to_execute(0)
{
	std::cout << "[DEBUG] AForm default constructor called (not used)" << std::endl;
}

AForm::AForm(const std::string& _name, const std::string& _target, int _sign, int _exec)
try : name(_name), target(_target), is_signed(0), grade_to_sign(validate(_sign)), grade_to_execute(validate(_exec)) {
	std::cout << "[DEBUG] AForm constructor called" << std::endl;
} catch (std::exception &e) { throw ; }

AForm::AForm(const AForm& f)
	: name(f.name), is_signed(f.is_signed), grade_to_sign(f.grade_to_sign), grade_to_execute(f.grade_to_execute)
{
	std::cout << "[DEBUG] AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& f)
{
	std::cout << "[DEBUG] AForm copy assignment operator called" << std::endl;
	if (this != &f)
		is_signed = f.is_signed;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "[DEBUG] AForm destructor called" << std::endl;
}

std::string AForm::getName(void) const { return (name); }

bool	AForm::getIsSigned(void) const { return (is_signed); }

int	AForm::getGradeToSign(void) const { return (grade_to_sign); }

int AForm::getGradeToExecute(void) const { return (grade_to_execute) ; }

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << "-------------------------" << std::endl;
	os << "Name: " << f.getName() << std::endl;
	os << "Status: " << (f.getIsSigned() == 1 ? "Signed" : "Not Signed") << std::endl;
	os << "Grade Need to Sign: " << f.getGradeToSign() << std::endl;
	os << "Grade Need to Execute: " << f.getGradeToExecute() << std::endl;
	return (os << "-------------------------" << std::endl);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (is_signed == 1)
		throw (AFormAlreadySignedException());
	else if (b.getGrade() > grade_to_sign)
		throw (GradeTooLowException());
	else
		is_signed = 1;
}
