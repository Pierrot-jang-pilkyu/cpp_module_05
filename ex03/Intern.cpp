#include "Intern.hpp"

Intern::Intern(void) {};

Intern::Intern(const Intern &obj) {};

Intern &Intern::operator=(const Intern &obj) { return (*this); };

Intern::~Intern(void) {};

Form &Intern::makeForm(std::string type, std::string formName)
{
	std::string	c1 = "shrubbery creation";
	std::string	c2 = "robotomy request";
	std::string	c3 = "presidential pardon";

	switch (type)
	{
	case c1:
		
		break;
	
	default:
		break;
	}
}
