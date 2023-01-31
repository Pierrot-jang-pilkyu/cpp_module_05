#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string _name) : AForm(_name, false, 72, 45) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
: AForm(obj.getName(), obj.getSign(), obj.getSignGrade(), obj.getExecGrade()) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
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

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkExeception(executor);

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}
