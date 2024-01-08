#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat {
	const std::string name;
	int grade;
public:
	Bureaucrat(const std::string& _name, int _grade=150);
	~Bureaucrat();

	std::string getName(void) const;
	int getGrade(void) const;
	void increaseGrade(int);
	void decreaseGrade(int);
private:
	Bureaucrat();
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
