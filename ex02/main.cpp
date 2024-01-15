#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	leaks(void) { system ("leaks -q a.out"); }

int	main(void) try
{
	/*
	ShrubberyCreationForm shrub("Cluster");
	Bureaucrat junior("junior", 145);
	Bureaucrat elder("elder", 137);

	// elder.executeForm(shrub); // not signed
	std::cout << shrub;
	junior.signForm(shrub);
	std::cout << shrub;
	// junior.executeForm(shrub); // grade to low
	elder.executeForm(shrub);
	*/

	/*
	RobotomyRequestForm robot("Mushroom");
	Bureaucrat junior("junior", 72);
	Bureaucrat elder("elder", 45);

	// elder.executeForm(robot); // not signed
	junior.signForm(robot);
	// junior.executeForm(robot); // grade to low
	elder.executeForm(robot);
	*/

	
	/*
	PresidentialPardonForm pardon("dajeon");
	Bureaucrat junior("junior", 25);
	Bureaucrat elder("elder", 5);

	// elder.executeForm(pardon); // not signed
	junior.signForm(pardon);
	// elder.executeForm(pardon); // not signed
	// junior.executeForm(pardon); // grade too low
	elder.executeForm(pardon);
	*/

	return (0);
}
catch (std::exception& e)
{
	std::cerr << "main: " << e.what() << std::endl;
	return (1);
}
