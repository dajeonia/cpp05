#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM
# include "AForm.hpp"
# include <iostream>
# include <fstream>

class PresidentialPardonForm : public AForm
{
	std::string target;
public:
	PresidentialPardonForm(const std::string&);
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	~PresidentialPardonForm();

	void execute(const Bureaucrat&) const;
private:
	PresidentialPardonForm();
};

#endif
