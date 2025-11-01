#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Bureaucrat creation =====" << std::endl;
    Bureaucrat alice("Alice", 5);
    Bureaucrat bob("Bob", 140);
    Bureaucrat charlie("Charlie", 70);
    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << charlie << std::endl;

    std::cout << "\n===== Form creation =====" << std::endl;
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n===== Signing forms =====" << std::endl;
    bob.signForm(shrub);      // OK: grade 140 → sign 145
    bob.signForm(robo);       // NG: needs 72
    alice.signForm(robo);     // OK
    charlie.signForm(pardon); // NG: needs 25
    alice.signForm(pardon);   // OK

    std::cout << "\n===== Executing forms =====" << std::endl;
    bob.executeForm(shrub);      // OK: grade 140, exec 137 → fail (too low)
    alice.executeForm(shrub);    // OK: success → creates "garden_shrubbery"
    charlie.executeForm(robo);   // fail: not enough grade
    alice.executeForm(robo);     // OK: will print robotomy success/failure
    alice.executeForm(pardon);   // OK: prints pardon message

    std::cout << "\n===== Invalid form test =====" << std::endl;
    try {
        ShrubberyCreationForm badForm("oops");
        Bureaucrat low("Low", 150);
        low.executeForm(badForm); // not signed → throws
    } catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== End of tests =====" << std::endl;
    return 0;
}