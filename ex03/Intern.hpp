#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	class FormNoIndexException;

	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	AForm* makeForm(const std::string&, const std::string&) const;
	class FormNoIndexException : public std::exception {
	public:
		char const* what(void) const _NOEXCEPT;
	};
};

#endif
