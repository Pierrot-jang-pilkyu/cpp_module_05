#ifndef INTERN_HPP
# define INTERN_HPP
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &obj);
	Intern	&operator=(const Intern &obj);
	~Intern(void);

	Form	*makeForm(std::string type, std::string formName);

	class NotExistFormNameException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};
};

#endif
