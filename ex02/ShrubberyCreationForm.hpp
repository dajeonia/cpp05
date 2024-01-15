#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	std::string target;
public:
	ShrubberyCreationForm(const std::string&);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat&) const;
private:
	ShrubberyCreationForm();
};

#endif
