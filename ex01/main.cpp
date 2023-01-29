#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat	a("john", 1);
	Bureaucrat	b("michael", 150);
	Bureaucrat	c(a);
	// Bureaucrat	d;

	std::cout << std::endl;
	a = b;
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
	std::cout << c << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat	e1("jenny", 151);
	}
	catch (const Bureaucrat::GradeTooLowhException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Bureaucrat	e2("cristina", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
