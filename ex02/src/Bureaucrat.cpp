#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) , _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {};


// getters
const std::string &Bureaucrat::getName() const { return _name; }

int	 Bureaucrat::getGrade() const
{
	return (_grade);
}


// Grade control
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm &f) const
{
	try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign "
                  << f.getName() << " because " << e.what() << std::endl;
    }
}

void	Bureaucrat::executeForm(AForm const &f) const
{
	try
	{
		f.execute(*this);
		std::cout << _name << " executed " << f.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn’t execute " << f.getName()
                  << " because " << e.what() << std::endl;
	}
}


// exeptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
