#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	const std::string name;
	const std::string target;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_execute;
public :
	class GradeTooHighException;
	class GradeTooLowException;
	class AFormAlreadySignedException;

	AForm(const std::string&, const std::string&, int, int);
	AForm(const AForm&);
	virtual AForm& operator=(const AForm&);
	virtual ~AForm();

	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	
	void beSigned(const Bureaucrat&);
	virtual void excute(const Bureaucrat&) =0;

	class GradeTooHighException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
	class AFormAlreadySignedException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
private:
	int validate(const int);
	AForm();
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif
