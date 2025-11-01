#include "../include/AForm.hpp"

/*default*/
AForm::AForm() : _name("nonname"), _signed(false), _gradeToSign(150), _gradeToExec(150){}
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){}
AForm	&AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}
AForm::~AForm(){}

/*getters*/
const std::string	&AForm::getName() const{ return _name; };
bool	AForm::isSigned() const{ return _signed; };
int	AForm::getGradeToSign() const{ return _gradeToSign;};
int	AForm::getGradeToExec() const{ return _gradeToExec;};

/* behave */
void	AForm::beSigned(const Bureaucrat &bureaucrat) { 
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
};
void	AForm::execute(Bureaucrat const &executor) const
{
	// check form and executor status
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
}

/*exeption*/
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: grade is too high";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: grade is too low";
}
const char* AForm::FormNotSignedException::what() const throw() {
	return "AForm: Form is not signed, yet";
}


/*override*/
std::ostream	&operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << ", signed: " << f.isSigned() << ", gradeToSign: " << f.getGradeToSign() << ", gradeToExec: " << f.getGradeToExec();
	return (os);
}
