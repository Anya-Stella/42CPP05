#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "./AForm.hpp"

class Intern
{
public:
	/*.default */
	Intern();
	Intern(const Intern &other);
	Intern	&operator=(const Intern &rhs);
	~Intern();

	/*.behave */
	AForm	*makeForm(const std::string &name, const std::string &target) const;

	/*.exception */
	class UnknownFormException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Intern&);
#endif