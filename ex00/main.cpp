#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat a("dajeon");
	std::cout << a;
	a.increaseGrade(5);
	a.increaseGrade(5);
	a.increaseGrade(5);
	a.increaseGrade(5);
	std::cout << a;
}
