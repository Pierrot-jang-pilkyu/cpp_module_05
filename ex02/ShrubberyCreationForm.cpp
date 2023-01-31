#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _name) : AForm(_name, false, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
: AForm(obj.getName(), obj.getSign(), obj.getSignGrade(), obj.getExecGrade()) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
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

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkExeception(executor);

	std::string	filename = executor.getName() + "_shrubbery";
	std::string texture = "\
		           ,@@@@@@@,\n\
	       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
	    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
	   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'\n\
	   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\'\n\
	   %&&%/ %&%%&&@@\\ V /@@\' `88\\8 `/88\'\n\
	   `&%\\ ` /%&\'    |.|        \\ \'|8\'\n\
	       |o|        | |         | |\n\
	       |.|        | |         | |\n\
	jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n\
	";

	std::ofstream	fout(filename, std::ios_base::out | std::ios_base::trunc);
	fout.write(texture.c_str(), texture.length());
	fout.close();
}
