#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm(void);
	
public:
	ShrubberyCreationForm(std::string _name);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);
	~ShrubberyCreationForm(void);

	void execute(Bureaucrat const & executor) const;
};

#endif
