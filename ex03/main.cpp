#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat	a("john", 45);
	Bureaucrat	b("michael", 137);
	Bureaucrat	c("Jack", 5);
	// Bureaucrat	d;

	ShrubberyCreationForm	s("Make tree");
	RobotomyRequestForm		r("Run machine");
	PresidentialPardonForm	p("Pardon him");

	std::cout << std::endl;
	std::cout << std::boolalpha << s << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha << r << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha << p << std::endl;
	std::cout << std::endl;
	
	s.beSigned(b);
	r.beSigned(a);
	p.beSigned(c);
	
	std::cout << std::endl;
	std::cout << std::boolalpha << s << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha << r << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha << p << std::endl;
	std::cout << std::endl;

	b.executeForm(s);
	system("cat michael_shrubbery");
	std::cout << std::endl;
	a.executeForm(r);
	std::cout << std::endl;
	c.executeForm(p);
	std::cout << std::endl;
	try
	{
		Bureaucrat	e1("jenny", 6);
		e1.executeForm(p);
	}
	catch (const Form::ExecGradeNotMatchException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Bureaucrat				e2("stella", 26);
		PresidentialPardonForm	p2("Pardon test");
		p2.beSigned(e2);
		e2.executeForm(p2);
	}
	catch (const Form::IsNotSignedException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
