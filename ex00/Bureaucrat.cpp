#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char*	Bureaucrat::GradeTooLowhException::what(void) const throw()
{
	return ("Grade too low.");
}

Bureaucrat::Bureaucrat(void) : name("")
{
	this->grade = 150;	
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(_grade > 150)
		throw Bureaucrat::GradeTooLowhException();
	this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.getName())
{
	if (obj.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(obj.getGrade() > 150)
		throw Bureaucrat::GradeTooLowhException();
	this->grade = obj.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	// standard
	(void)obj;
	std::cout << "Wrong using operator. Because of having const member attribute.\n";
	return (*this);

	/* A case of using const_cast

	std::string* temp = const_cast<std::string*>(&this->name);
	*temp = obj.getName();
	return (*this);

	*/
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::upGrade(void)
{
	++this->grade;
}

void Bureaucrat::downGrade(void)
{
	--this->grade;
}

std::ostream 	&operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}
