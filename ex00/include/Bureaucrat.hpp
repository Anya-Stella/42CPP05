#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	/* data */
	std::string	_name;
	int	_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	// getter
	const std::string	&getName() const;
	int	getGrade() const;

	// Grade control
	void	incrementGrade();
	void	decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

	class GradeTooLowExeption : 
	{
	public:
		const char *what() const throw();
	}



};
#endif

