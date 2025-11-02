#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

/*.default */
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {};
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {};
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return *this;
};
ShrubberyCreationForm::~ShrubberyCreationForm(){};

void ShrubberyCreationForm::doExecute() const{
	std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        throw std::runtime_error("Could not open file.");

    ofs << "   /\\   " << std::endl;
    ofs << "  /\\*\\  " << std::endl;
    ofs << " /\\O\\*\\ " << std::endl;
    ofs << "   ||   " << std::endl;
    ofs << "   ||   " << std::endl;

    ofs.close();
    std::cout << _target << "_shrubbery created successfully 🌳" << std::endl;
};
