#include "Intern.hpp"

const char* Intern::NotExistFormNameException::what() const throw()
{
	return ("This formname isn't exist.");
}

Intern::Intern(void) {};

Intern::Intern(const Intern &obj) { (void)obj; };

Intern &Intern::operator=(const Intern &obj) { (void)obj; return (*this); };

Intern::~Intern(void) {};

Form *Intern::makeForm(std::string type, std::string formName)
{
	std::string	c1 = "shrubbery creation";
	std::string	c2 = "robotomy request";
	std::string	c3 = "presidential pardon";

	int num = 1 * !type.compare(c1) + 2 * !type.compare(c2) + 3 * !type.compare(c3);

	switch (num)
	{
	case 1:
		std::cout << "Intern creates shrubbery creation.\n";
		return (new ShrubberyCreationForm(formName));
	
	case 2:
		std::cout << "Intern creates robotomy request.\n";
		return (new RobotomyRequestForm(formName));
	
	case 3:
		std::cout << "Intern creates presidential pardon.\n";
		return (new PresidentialPardonForm(formName));
	
	default:
		throw Intern::NotExistFormNameException();
		break;
	}
	return (NULL);
}
