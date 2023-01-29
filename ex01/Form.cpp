#include "Form.hpp"

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char*	Form::GradeTooLowhException::what(void) const throw()
{
	return ("Grade too low.");
}

Form::Form(void) : name(""), sign(false), signGrade(150), execGrade(150) {}

Form::Form(const Form &obj) : name(obj.getName()), signGrade(obj.getSignGrade()), execGrade(obj.getExecGrade())
{
	if (obj.getSignGrade() < 1)
		throw Form::GradeTooHighException();
	else if(obj.getSignGrade() > 150)
		throw Form::GradeTooLowhException();
	if (obj.getExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if(obj.getExecGrade() > 150)
		throw Form::GradeTooLowhException();
	this->sign = obj.getSign();
}

Form::Form(std::string _name, bool _sign, int _signgrade, int _execgrade)
: name(_name), signGrade(_signgrade), execGrade(_execgrade)
{
	if (_signgrade < 1)
		throw Form::GradeTooHighException();
	else if(_signgrade > 150)
		throw Form::GradeTooLowhException();
	if (_execgrade < 1)
		throw Form::GradeTooHighException();
	else if(_execgrade > 150)
		throw Form::GradeTooLowhException();
	this->sign = _sign;
}

Form::~Form(void) {}

Form &Form::operator=(const Form &obj)
{
	// standard
	(void)obj;
	std::cout << "Wrong using operator. Because of having const member attribute.\n";
	return (*this);

	/* A case of using const_cast

	std::string* temp1 = const_cast<std::string*>(&this->name);
	*temp1 = obj.getName();
	int* temp2 = const_cast<int*>(&this->signGrade);
	*temp2 = obj.getSignGrade();
	int* temp3 = const_cast<int*>(&this->execGrade);
	*temp3 = obj.getExecGrade();
	return (*this);

	*/
}

std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getSign(void)
{
	return (this->sign);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecGrade(void) const
{
	return (this->execGrade);
}

void Form::setSign(bool _sign)
{
	this->sign = _sign;
}

std::ostream 	&operator<<(std::ostream &os, const Form &obj)
{
	
}
