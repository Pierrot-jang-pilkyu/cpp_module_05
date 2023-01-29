#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
	Bureaucrat(void);

public:
	Bureaucrat(const std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat	&operator=(const Bureaucrat &obj);
	~Bureaucrat(void);

	std::string	getName(void) const;
	int	getGrade(void) const;
	void	upGrade(void);
	void	downGrade(void);

	class GradeTooHighException : public std::exception
	{
	public:
		const char*	what(void) const throw();
	};
	class GradeTooLowhException : public std::exception
	{
	public:
		const char*	what(void) const throw();
	};
};

std::ostream 	&operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
