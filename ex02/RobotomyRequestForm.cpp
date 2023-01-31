#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string _name) : AForm(_name, false, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
: AForm(obj.getName(), obj.getSign(), obj.getSignGrade(), obj.getExecGrade()) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
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

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkExeception(executor);

	std::cout << "drilling noise : drrrrrrr....\n";
	
	if (srand((unsigned int)time(NULL)) % 2)
		std::cout << "Congratulation! " << executor.getName() << " successfully robotomized.\n";
	else
		std::cout << "OMG! " << executor.getName() << " is failed robotomizing.\n";
}
