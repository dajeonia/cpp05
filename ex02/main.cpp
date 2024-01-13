#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat b1("elder", 110);
		Bureaucrat b2("younger", 138);
		ShrubberyCreationForm abc("abc");
		b2.signForm(abc);
		b2.executeForm(abc);
		b1.executeForm(abc);
	}
	catch (std::exception& e)
	{
		std::cerr << "main: " << e.what() << std::endl;
		return (1);
	}
}
