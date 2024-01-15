#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	std::string target;
public:
	RobotomyRequestForm(const std::string&);
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	~RobotomyRequestForm();

	void execute(const Bureaucrat&) const;
private:
	RobotomyRequestForm();
};

#endif
