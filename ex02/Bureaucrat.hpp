#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	const std::string name;
	int grade;
public:
	class GradeTooHighException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
	Bureaucrat(const std::string&, int _grade=150);
	Bureaucrat(const Bureaucrat&);
	virtual Bureaucrat& operator=(const Bureaucrat&);
	virtual ~Bureaucrat();

	std::string getName(void) const;
	int getGrade(void) const;
	void increment(int);
	void decrement(int);
	
	void signForm(AForm&) const;
private:
	int validate(int);
	Bureaucrat();
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
