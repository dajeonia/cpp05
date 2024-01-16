#ifndef FORM_HPP
# define FORM_HPP

#include "AForm.hpp"

class Form {
	AForm* p;
public:
	Form(AForm*);
	~Form();
	operator AForm&();
private:
	Form(const Form&);
	Form& operator=(const Form&);
};

#endif
