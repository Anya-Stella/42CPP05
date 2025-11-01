#ifndef SHRUBBRYCREATIONFORM_HPP
#define SHRUBBRYCREATIONFORM_HPP

/*.include */
#include "./AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private :
	std::string	_target;

public :
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();
};
#endif