#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm(void);
	
public:
	PresidentialPardonForm(std::string _name);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);
	~PresidentialPardonForm(void);

	void execute(Bureaucrat const & executor) const;
};

#endif
