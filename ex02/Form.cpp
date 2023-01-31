#include "Form.hpp"

const char*	Form::IsNotSignedException::what(void) const throw()
{
	return ("This Form isn't sined.");
}

const char*	Form::ExecGradeNotMatchException::what(void) const throw()
{
	return ("Your grade is lower than this form execGrade.");
}

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

bool Form::getSign(void) const
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

bool	Form::beSigned(const Bureaucrat &obj)
{
	if (!this->sign && this->signGrade >= obj.getGrade())
		return (this->sign = true);
	else
		return (this->sign = false);
}

void	Form::checkExeception(Bureaucrat const &obj) const
{
	if (!this->getSign())
		throw Form::IsNotSignedException();
	else if (this->getExecGrade() < obj.getGrade())
		throw Form::ExecGradeNotMatchException();
}

std::ostream 	&operator<<(std::ostream &os, const Form &obj)
{
	os << obj.getName() << std::endl \
		<< "sign	| signGrade	| execGrade	|" << std::endl \
		<< obj.getSign() << "	| " \
		<< obj.getSignGrade() << "		| " << obj.getExecGrade() << "		|\n";
	return (os);
}
