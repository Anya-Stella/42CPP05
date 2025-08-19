#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"

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

	// getters


	// behavior


	// Exception
};

// << override

#endif