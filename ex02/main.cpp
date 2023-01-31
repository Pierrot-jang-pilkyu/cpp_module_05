#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat	a("john", 20);
	Bureaucrat	b("michael", 150);
	Bureaucrat	c(a);
	// Bureaucrat	d;
	Form	f("Bureaucrat grade up", false, 20, 150);
	std::cout << std::boolalpha << f;
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;

	a.signForm(f);
	if (f.getSign())
		b.upGrade();
	std::cout << b << std::endl;
	std::cout << std::endl;
	try
	{
		Form	e1("jenny",false, 150, 151);
	}
	catch (const Form::GradeTooLowhException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Form	e2("cristina", false, 0, 1);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
