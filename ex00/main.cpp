#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) try
{
	Bureaucrat junior("junior"); // 인자 1개 생성자 (string name)
	Bureaucrat elder("elder", 1); // 인자 2개 생성자(string name, int grade)
	// Bureaucrat zero; // error: a private constructor called
	// Bureaucrat bad_elder("elder", 0); // exception: GradeTooHighException
	// Bureaucrat bad_junior("junior", 151); // exception: GradeTooLowException

	std::cout << junior;
	std::cout << elder;

	junior.increment(1);
	elder.decrement(1);
	// junior.decrement(2); // GradeTooLowException
	// elder.increment(2); // GradeTooHighException

	std::cout << junior;
	std::cout << elder;

	return (0);
}
catch (std::exception& e)
{
	std::cerr << "main: " << e.what() << std::endl;
	return (1);
}
