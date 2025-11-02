#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

int main() {

    Intern someRandomIntern;
    Bureaucrat alice("Alice", 3);


    try {
        AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        
        /*.signForm */
        alice.signForm(*f1); alice.executeForm(*f1);
        alice.signForm(*f2); alice.executeForm(*f2);
        alice.signForm(*f3); alice.executeForm(*f3);

        delete f1; delete f2; delete f3;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // failed
    try {
        AForm* fx = someRandomIntern.makeForm("banana split", "nobody");
        delete fx;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
