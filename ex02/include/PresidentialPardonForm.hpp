#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

/*.include */
#include "./AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private :
	std::string	_target;

	void doExecute() const;

public :
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();
};
#endif