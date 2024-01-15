#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) try
{
	Bureaucrat b1("elder", 110);
	Bureaucrat b2("younger", 150);
	Form f1("Immigration", 120, 100);

	// Form f2("Immigration", 120, -1); // exception: Grade Too High
	// Form f3("Immigration", -1, 120); // exception: Grade Too High 2
	// Form f4("Immigration", 120, 151); // exception: Grade Too Low
	// Form f5("Immigration", 151, 100); // exception: Grade Too Low 2

	std::cout << f1;

	b1.signForm(f1); // OK 
	// b2.signForm(f1); // couldn't sign by signForm() GradeTooLow
	// f1.beSigned(b2); // throw exception then escape // stack winding: destructors called
	// b1.signForm(f1); // couldn't sign by signForm() FormAlreadySigned

	std::cout << f1;
	return (0);
}
catch (std::exception& e)
{
	std::cerr << "[EXCEPTION] main: " << e.what() << std::endl;
	return (1);
}
