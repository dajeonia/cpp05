#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat b1("elder", 110);
		Bureaucrat b2("younger", 150);
	}
	catch (std::exception& e)
	{
		std::cerr << "main: " << e.what() << std::endl;
		return (1);
	}
}
