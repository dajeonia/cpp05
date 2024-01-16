#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include <iostream>

void	leaks(void) { system ("leaks -q a.out"); }

int	main(void) try
{
	// atexit(leaks);
	Intern intern;
	Bureaucrat master("master", 1);

	// Form undefined(intern.makeForm("Undefined", "target"));

	Form shrub(intern.makeForm("Shrubbery Creation", "Home"));
	std::cout << "==================================================" << std::endl;
	master.signForm(shrub);
	master.executeForm(shrub);
	std::cout << "==================================================" << std::endl;

	/*
	AForm *robot = intern.makeForm("Robotomy Request", "Bender");
	std::cout << "==================================================" << std::endl;
	master.signForm(robot);
	master.executeForm(robot);
	std::cout << "==================================================" << std::endl;
	*/

	/*
	AForm *pardon = intern.makeForm("Presidential Pardon", "dajeon");
	std::cout << "==================================================" << std::endl;
	master.signForm(pardon);
	master.executeForm(pardon);
	std::cout << "==================================================" << std::endl;
	*/
	return (0);
}
catch (std::exception& e)
{
	std::cerr << "[EXCEPTION] main: " << e.what() << std::endl;
	return (1);
}
