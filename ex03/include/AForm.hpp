#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "./Bureaucrat.hpp"

class AForm
{
private:
	/* data */
	const std::string	_name;
	bool		_signed;
	const int	_gradeToSign;
	const int	_gradeToExec;

	virtual void doExecute() const = 0;

public:
	AForm();
	AForm(const std::string &name, int gradeToSign, int gradeToExec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm();

	/* getters */
	const std::string	&getName() const;
	bool	isSigned() const;
	int	getGradeToSign() const;
	int	getGradeToExec() const;

	// behavior
	void	beSigned(const Bureaucrat &bureaucrat);
	void	execute(Bureaucrat const &executor) const;


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
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

// << override
std::ostream	&operator<<(std::ostream &os, const AForm	&f);

#endif