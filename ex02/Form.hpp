#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				sign;
	const int			signGrade;
	const int			execGrade;

protected:
	Form(void);

public:
	Form(const Form &obj);
	Form(std::string _name, bool _sign, int _signgrade, int _execgrade);
	Form	&operator=(const Form &obj);
	virtual ~Form(void) {};

	std::string	getName(void) const;
	bool		getSign(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	void		setSign(bool _sign);

	bool	beSigned(const Bureaucrat &obj);
	void	checkExeception(Bureaucrat const &obj) const;

	virtual void	execute(Bureaucrat const & executor) const = 0;

	class IsNotSignedException : public std::exception
	{
	public:
		const char*	what(void) const throw();
	};
	class ExecGradeNotMatchException : public std::exception
	{
	public:
		const char*	what(void) const throw();
	};
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

std::ostream 	&operator<<(std::ostream &os, const Form &obj);

#endif
