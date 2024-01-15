#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_execute;
public :
	class GradeTooHighException;
	class GradeTooLowException;
	class FormAlreadySignedException;
	class FormNotSignedException;

	AForm(const std::string&, int, int);
	AForm(const AForm&);
	virtual ~AForm();

	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	
	void beSigned(const Bureaucrat&);
	virtual void execute(const Bureaucrat&) const =0;

	class GradeTooHighException : public std::exception {
	public:
		char const* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		char const* what(void) const throw();
	};
	class FormAlreadySignedException : public std::exception {
	public:
		char const* what(void) const throw();
	};
	class FormNotSignedException : public std::exception {
	public:
		char const* what(void) const throw();
	};
private:
	int validate(const int);
	AForm& operator=(const AForm&);
	AForm();
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif
