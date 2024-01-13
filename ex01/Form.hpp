#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_execute;
public :
	class GradeTooHighException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
	class FormAlreadySignedException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
	Form(const std::string&, int, int);
	Form(const Form&);
	virtual Form& operator=(const Form&);
	virtual ~Form();

	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	
	void beSigned(const Bureaucrat&);
private:
	int validate(const int);
	Form();
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif
