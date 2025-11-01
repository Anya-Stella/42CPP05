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
    ShrubberyCreationForm shrub("garden");            // 145, 137
    RobotomyRequestForm robo("Bender");               // 72, 45
    PresidentialPardonForm pardon("Ford Prefect");    // 25, 5
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;



    std::cout << "\n===== Signing forms =====" << std::endl;
    bob.signForm(shrub);      // OK
    bob.signForm(robo);       // NG
    alice.signForm(robo);     // OK
    charlie.signForm(pardon); // NG
    alice.signForm(pardon);   // OK



    std::cout << "\n===== Executing forms =====" << std::endl;
    bob.executeForm(shrub);      // fail bob140, 137
    alice.executeForm(shrub);    // OK: alice5, 137
    charlie.executeForm(robo);   // fail: charlie70, 45
    alice.executeForm(robo);     // OK: alice5, 45
    alice.executeForm(pardon);   // OK: alice5, 5




    std::cout << "\n===== Invalid form test =====" << std::endl;
    try {
        ShrubberyCreationForm badForm("oops");
        Bureaucrat low("Low", 150);
        low.executeForm(badForm);
    } catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }




    std::cout << "\n===== End of tests =====" << std::endl;
    return 0;
}
