#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

/*default*/
Form::Form() : _name("nonname"), _signed(false), _gradeToSign(150), _gradeToExec(150){}
Form::Form(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}
Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){}
Form	&Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}
Form::~Form(){}

/*getters*/
const std::string	&Form::getName() const{ return _name; };
bool	Form::isSigned() const{ return _signed; };
int	Form::getGradeToSign() const{ return _gradeToSign;};
int	Form::getGradeToExec() const{ return _gradeToExec;};

/* behave */
void	Form::beSigned(const Bureaucrat &bureaucrat) { 
	if (this->getGradeToSign() >= bureaucrat.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
};


/*override*/
std::ostream	&operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << ", signed: " << f.isSigned() << ", gradeToSign: " << f.getGradeToSign() << ", gradeToExec: " << f.getGradeToExec();
	return (os);
}