#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
	/* data */
	const std::string	_name;
	bool		_signed;
	const int	_gradeToSign;
	const int	_gradeToExec;

public:
	Form();
	Form(const std::string &name, int gradeToSign, int gradeToExec);
	Form(const Form &other);
	Form &operator=(const Form &rhs);
	~Form();

	/* getters */
	const std::string	&getName() const;
	bool	isSigned() const;
	int	getGradeToSign() const;
	int	getGradeToExec() const;

	// behavior
	void	beSigned(const Bureaucrat &bureaucrat);


	/* Exceptions */
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

// << override
std::ostream	&operator<<(std::ostream &os, const Form	&f);

#endif