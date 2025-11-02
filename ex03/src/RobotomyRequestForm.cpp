#include "../include/RobotomyRequestForm.hpp"

/*.default */
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {};
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {};
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return *this;
};
RobotomyRequestForm::~RobotomyRequestForm(){};

void	RobotomyRequestForm::doExecute() const{
	std::cout << "Bzzz… Whirrr… Rrrrrrr…" << std::endl;

	// reset use to current time.
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully 🤖" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << " 💥" << std::endl;
}
