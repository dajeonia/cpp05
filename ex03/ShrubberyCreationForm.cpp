#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), target()
{
	std::cout << "[DEBUG] ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target)
	: AForm("Shrubbery Creation", 145, 137), target(_target)
{
	std::cout << "[DEBUG] ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& sf)
	: AForm(sf), target(sf.target)
{
	std::cout << "[DEBUG] ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& sf)
{
	if (this != &sf)
		target = sf.target;
	std::cout << "[DEBUG] ShrubberyCreationForm copy assignment operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[DEBUG] ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	// std::cout << "[DEBUG] ShrubberyCreationForm execute member function called" << std::endl;
	if (getIsSigned() == 0)
		throw (FormNotSignedException());
	else if (b.getGrade() > getGradeToExecute())
		throw (GradeTooLowException());
	else
	{
		std::ofstream out(target + "_shrubbery");
		if (out.is_open())
		{
			out << "::::::::.:::::::::::::::::-=-:---+====-==---==----=--==+=+*====+%***%%%##%%" << std::endl;
			out << "::::.:.:::..:..::....:==*==+:--==+--+==----=---=--::::::::::::::---=++=*=-=" << std::endl;
			out << "=-=--====-====---=--=+=+*+*#++=-**:-=#*=-=--==+=+==-::....................." << std::endl;
			out << "=======-=-=--=---=+==#*:+*+@##*-%#+-=*==#++=-+#+%++=+-==-:::::-........:..:" << std::endl;
			out << "=-----==--------*+#%%+##++=+-*++-%==+++*%*#*=++=+-==#*==+==--=-===--===-===" << std::endl;
			out << "---=-----====-+**@#-*+*#*+++=+-+%*-+*+++++==##++*=#-=+=+-=-----======-=====" << std::endl;
			out << "---------==-=+#*#*#**-=+%+*#*@-=@*++=*+=+#%#=%*++=-#+=-*-===-=-=----==--=--" << std::endl;
			out << "=+=-===-=---=**%@*#+%@@*@*+%+#--=+%+=++=#+%*=%=+-++*+:-=*+=-==-----====--=-" << std::endl;
			out << "=*==+*+#+##*++-@+##-*--:+=*#-#+-+#+#-**+%*#=====+=-===*-=#==-======-==-==-=" << std::endl;
			out << "........:::=+@%@##*++**+=-++==#**#@-@*=-#=***=--=+-=+-=-=+=+=-=------------" << std::endl;
			out << "...........*@%@%+###=+@*=*#+#*%=*%@+**++*+-%+#=*=*-+#+++#**+--=-=--+=-==-==" << std::endl;
			out << "...........#+%@%%=#*%-*##+#--%+%%=*%@%+##%**-%#*+#--=+#*++%--:==**=+-*=*=++" << std::endl;
			out << "::::::....:.=%@+%*%%%*#**%:=*-+%-%##@*=++=@+*%@%:=-+%**#+*===*:::::::::::::" << std::endl;
			out << ":..::::.:..:+%%#%%*@#%@@%%@*#+-%%#*-=*@#=#@--*+#=#++**#+#+=+:.:..........:." << std::endl;
			out << ".:..:.........%@%%%%%*%#@+%%%-*+-##*+%*+*%+*%*=-===%%--%#+*-..:..........::" << std::endl;
			out << "=====----::..:*=@#@*@@%#%@#+*%+#@@*=@=*##+@+@+##=%#==+*@+=+:..:........::.." << std::endl;
			out << "--=#%%%%%%%%%%%%%%@%@%#@%=**#*+%++*-#=%=+@%%##*=*%#***==-:......:.::..:..::" << std::endl;
			out << "=%%%%%%%%%%%%%%%%%%%%%%@=@@%=+@%%+*#%%==#=%#%#=*=-=*+*+....:::..:......:.::" << std::endl;
			out << "+*%%%%#%%%%%%%%@@%@%%%%@@%%@@#%%###++=%@#%+#++@-+=*%#+-..:.:.::::.......:.." << std::endl;
			out << "==-+%#%%%%%%%%%%@%%@@@@%%@@@%%%@%@#+%@%@@@%%*@#@@@%%*+=-=-=====+:==--:::.:." << std::endl;
			out << "==+++=*-=++#-#+%%#%%@%%@@@@@@@@@@@%%@@%@@%@@@@*%#=--:::--=+*===--=+-=++==+-" << std::endl;
			out << "==+++==-*#-:=-==-=======-=%***++#*++#*--*:==--=-=---===+=-=+===+=-=+====+==" << std::endl;
			out << "====-+-=+=--=--=-+=--==-*+===*--+==+=-=+==+--======*=======*++=====++*+++*+" << std::endl;
			std::cout << "[INFO] The shrub has been planted on \'" << target << "_shrubbery\'(success)" << std::endl;
			out.close();
		}
		else 
			std::cout << "[INFO] The shrub couldn't be planted on \'" << target << "_shrubbery\'(failed)" << std::endl;
	}
}
