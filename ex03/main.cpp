#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	Intern someRandomIntern;

	Form* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Bender");

	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	Form* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

	Bureaucrat	a("john", 45);
	Bureaucrat	b("michael", 137);
	Bureaucrat	c("Jack", 5);
	// Bureaucrat	d;

	std::cout << std::endl;
	std::cout << std::boolalpha << *scf << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha << *rrf << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha << *ppf << std::endl;
	std::cout << std::endl;
	
	scf->beSigned(b);
	rrf->beSigned(a);
	ppf->beSigned(c);

	std::cout << std::endl;
	std::cout << std::boolalpha << *scf << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha << *rrf << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha << *ppf << std::endl;
	std::cout << std::endl;

	b.executeForm(*scf);
	system("cat michael_shrubbery");
	std::cout << std::endl;
	a.executeForm(*rrf);
	std::cout << std::endl;
	c.executeForm(*ppf);
	std::cout << std::endl;

	std::cout << std::endl;
	try
	{
		Form* temp;
		temp = someRandomIntern.makeForm("not exist", "test");
		(void)temp;
	}
	catch (const Intern::NotExistFormNameException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
