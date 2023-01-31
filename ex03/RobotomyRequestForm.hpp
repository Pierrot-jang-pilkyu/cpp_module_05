#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <stdlib.h>
# include <time.h>

class RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm(void);
	
public:
	RobotomyRequestForm(std::string _name);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);
	~RobotomyRequestForm(void);

	void execute(Bureaucrat const & executor) const;
};

#endif
