#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat {
	const std::string name;
	int grade;
	int validate(int);
public:
	Bureaucrat(const std::string& _name, int _grade=150);
	Bureaucrat(const Bureaucrat&);
	virtual Bureaucrat& operator=(const Bureaucrat&);
	virtual ~Bureaucrat();

	std::string getName(void) const;
	int getGrade(void) const;
	void increment(int);
	void decrement(int);

	class GradeTooHighException : public std::exception {
	public:
		char const* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		char const* what(void) const throw();
	};
private:
	Bureaucrat();
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
