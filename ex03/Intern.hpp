#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &obj);
	Intern	&operator=(const Intern &obj);
	~Intern(void);

	Form	&makeForm(std::string type, std::string formName);
};

Intern::Intern(void)
{
}

Intern::~Intern()
{
}


#endif
