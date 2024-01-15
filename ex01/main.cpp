#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) try
{
	Bureaucrat b1("elder", 110);
	Bureaucrat b2("younger", 150);
	Form f1("Immigration", 120, 100);

	// Form f2("Immigration", 120, -1); // Grade Too High
	// Form f3("Immigration", -1, 120); // Grade Too High 2
	// Form f4("Immigration", 120, 151); // Grade Too Low
	// Form f5("Immigration", 151, 100); // Grade Too Low 2

	std::cout << f1; // operator<<
	// b2.signForm(f1); // Grade Too Low
	// f1.beSigned(b2); // throw exception then escape // stack winding: destructors called

	b1.signForm(f1); // OK
	// b1.signForm(f1); // Form Already Signed
	return (0);
}
catch (std::exception& e)
{
	std::cerr << "main: " << e.what() << std::endl;
	return (1);
}
