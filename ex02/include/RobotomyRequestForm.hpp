#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

/*.include */
#include "./AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private :
	std::string	_target;

public :
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();
};
#endif