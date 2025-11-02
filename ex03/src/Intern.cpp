#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"


Intern::Intern(){};
Intern::Intern(const Intern&) {};
Intern& Intern::operator=(const Intern&) { return *this; };
Intern::~Intern() {};

static AForm *makeShrub(const std::string &target) { return new ShrubberyCreationForm(target);};
static AForm *makeRobo(const std::string &target) { return new RobotomyRequestForm(target);};
static AForm *makePardon(const std::string &target) { return new PresidentialPardonForm(target);};

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	const std::string keys[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// pointer of function
	AForm *(*creators[3])(const std::string &) = { makeShrub, makeRobo, makePardon };

	for (int i = 0; i < 3; i++){
		if (name == keys[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ( creators[i](target) );
		}
	}
	throw UnknownFormException();
};

const char* Intern::UnknownFormException::what() const throw() {
	return "Intern: unknown form name";
}

std::ostream& operator<<(std::ostream& os, const Intern&) {
    return os << "Intern()";
}